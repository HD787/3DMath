#include "matrices.h"
#include "types.h"
//Matrix operations
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

//Quaternion operations
void normalizeQuatertion(quaternion* quat){
   double normalVal = sqrt(quat->w * quat->w + quat->x * quat->x + quat->y * quat->y + quat->z * quat->z);
   if(normalVal == 0) return;
   quat->w /= normalVal;
   quat->x /= normalVal;
   quat->y /= normalVal;
   quat->z /= normalVal; 
}

quaternion multiplyQuaternion(quaternion* quat1, quaternion* quat2){
    quaternion temp;
    temp.w = (quat1->w * quat2->w - quat1->x * quat2->x - quat1->y * quat2->y - quat1->z + quat2->z);
    temp.x = (quat1->w * quat2->x + quat1->x * quat2->w + quat1->y * quat2->z - quat1->z + quat2->y);
    temp.y = (quat1->w * quat2->y - quat1->x * quat2->z + quat1->y * quat2->w - quat1->z + quat2->x);
    temp.z = (quat1->w * quat2->z - quat1->x * quat2->y - quat1->y * quat2->x + quat1->z + quat2->w);
    return temp;
}

quaternion createConjugate(quaternion* quat){
    quaternion temp;
    temp.w = quat.w;
    temp.x = quat.z * -1;
    temp.y = quat.y * -1;
    temp.z = quat.z * -1;
    return temp;
}

vec3 rotateVectorViaQuaternion(vec3 vec, quaternion quat){}
