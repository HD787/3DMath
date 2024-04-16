#include "matrices.h"
#include "types.h"
void vecByMatrix4x4(vec4* vec, matrix4x4 matrix){
    float x = vec->x * matrix[0] + vec->y * matrix[1] + vec->z * matrix[2] + vec->w * matrix[3];
    float y = vec->x * matrix[4] + vec->y * matrix[5] + vec->z * matrix[6] + vec->w * matrix[7];
    float z = vec->x * matrix[8] + vec->y * matrix[9] + vec->z * matrix[10] + vec->w * matrix[11];
    float w = vec->x * matrix[12] + vec->y * matrix[13] + vec->z * matrix[14] + vec->w * matrix[15];
    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->w = w;
}