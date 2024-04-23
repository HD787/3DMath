#include "matrices.h"
#include "types.h"
//Matrix operations
//not sure it makes sense to use pointers for this, might want to return a new vector
//acutually i think it does make sense, im gonna keep thinking about this for now
void vecByMatrix4x4(vec4* vec, matrix4x4 matrix){
    float x = vec->x * matrix[0] + vec->y * matrix[4] + vec->z * matrix[8] + vec->w * matrix[12];
    float y = vec->x * matrix[1] + vec->y * matrix[5] + vec->z * matrix[9] + vec->w * matrix[13];
    float z = vec->x * matrix[2] + vec->y * matrix[6] + vec->z * matrix[10] + vec->w * matrix[14];
    float w = vec->x * matrix[3] + vec->y * matrix[7] + vec->z * matrix[11] + vec->w * matrix[15];
    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->w = w;
}

//idk if i love these parameter names as the types and the parameters follow the same scheme
//but i already did something similar with quaternion paremeters and i want to be consistent
vec3 crossProduct(vec3 vec1, vec3 vec2){
    vec3 result;
    result.x = vec1.y * vec2.z - vec1.z * vec2.y;
    result.y = vec1.z * vec2.x- vec1.x * vec2.z;
    result.z = vec1.x * vec2.y - vec1.y * vec2.z;
    return result;
}

float dotProduct(vec3 vec1, vec3 vec2){
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

void normalizeVector(vec3* vec){
    float normalVal = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
    vec->x /= normalVal;
    vec->y /= normalVal;
    vec->z /= normalVal;
}



//Quaternion operations
void normalizeQuatertion(quaternion* quat){
   double normalVal = sqrt(quat->real * quat->real + quat->i * quat->i + quat->j * quat->j + quat->k * quat->k);
   if(normalVal == 0) return;
   quat->real /= normalVal;
   quat->i /= normalVal;
   quat->j /= normalVal;
   quat->k /= normalVal; 
}

quaternion multiplyQuaternion(quaternion* quat1, quaternion* quat2){
    quaternion temp;
    temp.real = (quat1->real * quat2->real - quat1->i * quat2->i - quat1->j * quat2->j - quat1->k + quat2->k);
    temp.i = (quat1->real * quat2->i + quat1->i * quat2->real + quat1->j * quat2->k - quat1->k + quat2->j);
    temp.j = (quat1->real * quat2->j - quat1->i * quat2->k + quat1->j * quat2->real - quat1->k + quat2->i);
    temp.k = (quat1->real * quat2->k - quat1->i * quat2->j - quat1->j * quat2->i + quat1->k + quat2->real);
    return temp;
}

quaternion createRotationQuaternion(float angle){
    quaternion result;
    float radians = angle * 3.14159265f / 180.0f;
    result.real = cos(radians / 2);
    result.i = sin(radians / 2);
    result.j = sin(radians / 2);
    result.k = sin(radians / 2);
    return result;
}

quaternion createConjugate(quaternion quat){
    quaternion temp;
    temp.real = quat.real;
    temp.i = quat.i * -1;
    temp.j = quat.j * -1;
    temp.k = quat.k * -1;
    return temp;
}

quaternion vectorToQuaternion(vec3 vec){
    quaternion temp;
    temp.real = 0;
    temp.i = vec.x;
    temp.j = vec.y;
    temp.k = vec.z;
    return temp;
}

vec3 quaternionToVector(quaternion quat){
    vec3 temp;
    temp.x = quat.i;
    temp.y = quat.j;
    temp.z = quat.k;
    return temp;
}

vec3 rotateVectorViaQuaternion(vec3* vec, quaternion* rotationQuat){
    quaternion vquat = vectorToQuaternion(*vec);
    quaternion conjugate = createConjugate(*rotationQuat);
    quaternion temp = multiplyQuaternion(rotationQuat, &vquat);
    quaternion resultQuat = multiplyQuaternion(&temp, &conjugate);
    vec3 result = quaternionToVector(resultQuat);
    return result;
}
