#include "matrices.h"
#include "types.h"
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