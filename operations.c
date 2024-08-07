#include "matrices.c"
#include "mathTypes.h"
void vecByMatrix4x4(vec4* v, matrix4x4 matrix){
    float x = v->x * matrix[0] + v->y * matrix[1] + v->z * matrix[2] + v->w * matrix[3];
    float y = v->x * matrix[4] + v->y * matrix[5] + v->z * matrix[6] + v->w * matrix[7];
    float z = v->x * matrix[8] + v->y * matrix[9] + v->z * matrix[10] + v->w * matrix[11];
    float w = v->x * matrix[12] + v->y * matrix[13] + v->z * matrix[14] + v->w * matrix[15];
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

void vecByMatrix4x4_COLUMNMAJOR(vec4* v, matrix4x4 matrix){
    float x = v->x * matrix[0] + v->y * matrix[4] + v->z * matrix[8] + v->w * matrix[12];
    float y = v->x * matrix[1] + v->y * matrix[5] + v->z * matrix[9] + v->w * matrix[13];
    float z = v->x * matrix[2] + v->y * matrix[6] + v->z * matrix[10] + v->w * matrix[14];
    float w = v->x * matrix[3] + v->y * matrix[7] + v->z * matrix[11] + v->w * matrix[15];
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

//add vectors, w is ignored don't think it makes sense to include it
vec4 addVectors(vec4 v1, vec4 v2){
    vec4 ret;
    ret.x = v1.x + v2.x;
    ret.y = v1.y + v2.y;
    ret.z = v1.z + v2.z;
    ret.w = 1.0f;
    return ret;
}

vec4 scaleVector(vec4 vec, float scalar){
    vec4 ret;
    ret.x = vec.x * scalar;
    ret.y = vec.y * scalar;
    ret.z = vec.z * scalar;
    ret.w = 1.0f;
    return ret;
}

vec3 crossProduct(vec3 v1, vec3 v2){
    vec3 result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x- v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

float dotProduct(vec3 v1, vec3 v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

void normalizeVector(vec3* v){
    float normalVal = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    v->x /= normalVal;
    v->y /= normalVal;
    v->z /= normalVal;
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

quaternion multiplyQuaternion(quaternion quat1, quaternion quat2){
    quaternion temp;
    temp.real = (quat1.real * quat2.real - quat1.i * quat2.i - quat1.j * quat2.j - quat1.k * quat2.k);
    temp.i = (quat1.real * quat2.i + quat1.i * quat2.real + quat1.j * quat2.k - quat1.k * quat2.j);
    temp.j = (quat1.real * quat2.j - quat1.i * quat2.k + quat1.j * quat2.real + quat1.k * quat2.i);
    temp.k = (quat1.real * quat2.k + quat1.i * quat2.j - quat1.j * quat2.i + quat1.k * quat2.real);
    return temp;
}

quaternion createRotationQuaternion(float angle, float x, float y, float z){
    quaternion result;
    float radians = angle * 3.14159265f / 180.0f;
    result.real = cos(radians / 2);
    result.i = x * sin(radians / 2);
    result.j = y * sin(radians / 2);
    result.k = z * sin(radians / 2);
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

quaternion vectorToQuaternion(vec3 v){
    quaternion temp;
    temp.real = 0;
    temp.i = v.x;
    temp.j = v.y;
    temp.k = v.z;
    return temp;
}

vec3 quaternionToVector(quaternion quat){
    vec3 temp;
    temp.x = quat.i;
    temp.y = quat.j;
    temp.z = quat.k;
    return temp;
}

void rotateVectorViaQuaternion(vec3* v, quaternion rotationQuat){
    quaternion vquat = vectorToQuaternion(*v);
    quaternion conjugate = createConjugate(rotationQuat);
    quaternion temp = multiplyQuaternion(rotationQuat, vquat);
    quaternion resultQuat = multiplyQuaternion(temp, conjugate);
    vec3 result = quaternionToVector(resultQuat);
    v->x = result.x; v->y = result.y; v->z = result.z;
}

//vector operations
vec4 homogenizeVector(vec3 v){
    vec4 result;
    result.x = v.x;
    result.y = v.y;
    result.z = v.z;
    result.w = 1.0;
    return result;
}

vec3 dehomogenizeVector(vec4 v){
    vec3 result;
    result.x = v.x;
    result.y = v.y;
    result.z = v.z;
    return result;
}

vec3 dehomogenizeVectorWithPerspective(vec4 v){
    vec3 result;
    result.x = v.x / v.w;
    result.y = v.y / v.w;
    result.z = v.z / v.w;
    return result; 
}

//Misc
float max(float f1, float f2){
    if(f1>f2) return f1;
    return f2;
}

void expandDepthRange(vec4* v,float bias, float scale){
    v->z = bias + scale * v->z;
}