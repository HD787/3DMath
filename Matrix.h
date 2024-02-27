#include <math.h>

void createRotationMatrixY(float angle, float matrix[16]) {
    float radians = angle * 3.14159265f / 180.0f;
    matrix[0] = cosf(radians);  matrix[4] = 0.0f; matrix[8] = sinf(radians);  matrix[12] = 0.0f;
    matrix[1] = 0.0f;           matrix[5] = 1.0f; matrix[9] = 0.0f;           matrix[13] = 0.0f;
    matrix[2] = -sinf(radians); matrix[6] = 0.0f; matrix[10] = cosf(radians); matrix[14] = 0.0f;
    matrix[3] = 0.0f;           matrix[7] = 0.0f; matrix[11] = 0.0f;          matrix[15] = 1.0f;
}

void createRotationMatrixX(float angle, float matrix[16]) {
    float radians = angle * 3.14159265f / 180.0f;
    matrix[0] = 1.0f;           matrix[4] = 0.0f;           matrix[8] = 0.0f;           matrix[12] = 0.0f;
    matrix[1] = 0.0f;           matrix[5] = cosf(radians);  matrix[9] = -sinf(radians); matrix[13] = 0.0f;
    matrix[2] = 0.0;            matrix[6] = sinf(radians);  matrix[10] = cosf(radians); matrix[14] = 0.0f;
    matrix[3] = 0.0f;           matrix[7] = 0.0f;           matrix[11] = 0.0f;          matrix[15] = 1.0f;
}

void createRotationMatrixX(float angle, float matrix[16]) {
    float radians = angle * 3.14159265f / 180.0f;
    matrix[0] = cosf(radians);  matrix[4] = -sinf(radians); matrix[8] = 0.0f;   matrix[12] = 0.0f;
    matrix[1] = sinf(radians);  matrix[5] = cosf(radians);  matrix[9] = 0.0f;   matrix[13] = 0.0f;
    matrix[2] = 0.0;            matrix[6] = 0.0f;           matrix[10] = 1.0f;  matrix[14] = 0.0f;
    matrix[3] = 0.0f;           matrix[7] = 0.0f;           matrix[11] = 0.0f;  matrix[15] = 1.0f;
}

void createScalingMatrix(float scaleFactor, float matrix[16]) {
    matrix[0] = scaleFactor;    matrix[4] = 0.0f;           matrix[8] = 0.0f;         matrix[12] = 0.0f;
    matrix[1] = 0.0f;           matrix[5] = scaleFactor;    matrix[9] = 0.0;          matrix[13] = 0.0f;
    matrix[2] = 0.0;            matrix[6] = 0.0f;           matrix[10] = scaleFactor; matrix[14] = 0.0f;
    matrix[3] = 0.0f;           matrix[7] = 0.0f;           matrix[11] = 0.0f;        matrix[15] = 1.0f;
}
//unsure whether or not I want to include a speed paramater here to scale the values or just do that when gathering input
void createTranslationMatrix(float x, float y, float z, float matrix[16]){
    matrix[0] = 1.0;    matrix[4] = 0.0f;   matrix[8] = 0.0f;   matrix[12] = x;
    matrix[1] = 0.0f;   matrix[5] = 1.0;    matrix[9] = 0.0;    matrix[13] = y;
    matrix[2] = 0.0;    matrix[6] = 0.0f;   matrix[10] = 1.0;   matrix[14] = z;
    matrix[3] = 0.0f;   matrix[7] = 0.0f;   matrix[11] = 0.0f;  matrix[15] = 1.0f;
}
