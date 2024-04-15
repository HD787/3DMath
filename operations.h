#include "Matrix.h"
#include "types.h"
vec4 vecByMatrix4x4(vec4 vec, matrix4x4 matrix){
    vec4 result;
    result.x = vec.x * matrix[0] + vec.y * matrix[1] + vec.z * matrix[2] + vec.w * matrix[3];
    result.y = vec.x * matrix[4] + vec.y * matrix[5] + vec.z * matrix[6] + vec.w * matrix[7];
    result.z = vec.x * matrix[8] + vec.y * matrix[9] + vec.z * matrix[10] + vec.w * matrix[11];
    result.w = vec.x * matrix[12] + vec.y * matrix[13] + vec.z * matrix[14] + vec.w * matrix[15];
    return result;
}