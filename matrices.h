#include <math.h>

void createRotationMatrix(float angle, float x, float y, float z, float matrix[16]){
    float radians = angle * 3.14159265f / 180.0f;
    float magnitude = sqrt(x * x + y * y + z * z);
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    matrix[0] = (1 - cos(radians)) * x * x + cos(radians);         matrix[4] = (1 - cos(radians)) * x * y - sin(radians) * z;   matrix[8] = (1 - cos(radians)) * x * z + sin(radians) * y;    matrix[12] = 0.0f;
    matrix[1] = (1 - cos(radians)) * x * y + sin(radians) * z;     matrix[5] = (1 - cos(radians)) * y * y + cos(radians);       matrix[9] = (1 - cos(radians)) * y * z - sin(radians) * x;    matrix[13] = 0.0f;
    matrix[2] = (1 - cos(radians)) * x * z - sin(radians) * y;     matrix[6] = (1 - cos(radians)) * y * z + sin(radians) * x;   matrix[10] = (1 - cos(radians)) * z * z + cos(radians);       matrix[14] = 0.0f;
    matrix[3] = 0.0f;                                              matrix[7] = 0.0f;                                            matrix[11] = 0.0f;                                            matrix[15] = 1.0f;
}

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

void createRotationMatrixZ(float angle, float matrix[16]) {
    float radians = angle * 3.14159265f / 180.0f;
    matrix[0] = cosf(radians);  matrix[4] = -sinf(radians); matrix[8] = 0.0f;   matrix[12] = 0.0f;
    matrix[1] = sinf(radians);  matrix[5] = cosf(radians);  matrix[9] = 0.0f;   matrix[13] = 0.0f;
    matrix[2] = 0.0;            matrix[6] = 0.0f;           matrix[10] = 1.0f;  matrix[14] = 0.0f;
    matrix[3] = 0.0f;           matrix[7] = 0.0f;           matrix[11] = 0.0f;  matrix[15] = 1.0f;
}

void createScalingMatrix(float scaleFactor, float matrix[16]) {
    matrix[0] = scaleFactor;    matrix[4] = 0.0f;           matrix[8] = 0.0f;         matrix[12] = 0.0f;
    matrix[1] = 0.0f;           matrix[5] = scaleFactor;    matrix[9] = 0.0;          matrix[13] = 0.0f;
    matrix[2] = 0.0f;           matrix[6] = 0.0f;           matrix[10] = scaleFactor; matrix[14] = 0.0f;
    matrix[3] = 0.0f;           matrix[7] = 0.0f;           matrix[11] = 0.0f;        matrix[15] = 1.0f;
}

void createTranslationMatrix(float x, float y, float z, float matrix[16]){
    matrix[0] = 1.0f;    matrix[4] = 0.0f;   matrix[8] = 0.0f;    matrix[12] = x;
    matrix[1] = 0.0f;    matrix[5] = 1.0f;   matrix[9] = 0.0f;    matrix[13] = y;
    matrix[2] = 0.0f;    matrix[6] = 0.0f;   matrix[10] = 1.0f;   matrix[14] = z;
    matrix[3] = 0.0f;    matrix[7] = 0.0f;   matrix[11] = 0.0f;   matrix[15] = 1.0f;
}

void createPerspectiveProjectionMatrix(float FOVdegrees, float nearPlane, float farPlane, float aspectRatio, float matrix[16]){
    float FOVradians = FOVdegrees * 3.14159265f / 180.0f;
    float yScale = 1.0f / tan(FOVradians / 2.0f);
    float xScale = yScale / aspectRatio;
    float frustumDepth = farPlane - nearPlane;
    matrix[0] = xScale;    matrix[4] = 0.0f;      matrix[8] = 0.0f;                                    matrix[12] = 0.0f;
    matrix[1] = 0.0f;      matrix[5] = yScale;    matrix[9] = 0.0f;                                    matrix[13] = 0.0f;
    matrix[2] = 0.0f;      matrix[6] = 0.0f;      matrix[10] = (farPlane + nearPlane)/frustumDepth;   matrix[14] = 2 * farPlane * nearPlane/frustumDepth;
    matrix[3] = 0.0f;      matrix[7] = 0.0f;      matrix[11] = 1.0f;                                  matrix[15] = 0.0f;
}


void createAlternativePerspectiveProjectionMatrix(float FOVdegrees, float nearPlane, float farPlane, float aspectRatio, float matrix[16]){
    float FOVradians = FOVdegrees * 3.14159265f / 180.0f;
    float yScale = 1.0f / tan(FOVradians / 2.0f);
    float xScale = yScale - aspectRatio;
    float frustumDepth = farPlane - nearPlane;
    matrix[0] = xScale;    matrix[4] = 0.0f;      matrix[8] = 0.0f;                     matrix[12] = 0.0f;
    matrix[1] = 0.0f;      matrix[5] = yScale;    matrix[9] = 0.0f;                     matrix[13] = 0.0f;
    matrix[2] = 0.0f;      matrix[6] = 0.0f;      matrix[10] = (farPlane)/frustumDepth; matrix[14] = (farPlane * nearPlane/frustumDepth);
    matrix[3] = 0.0f;      matrix[7] = 0.0f;      matrix[11] = 1.0f;                    matrix[15] = 0.0f;
}

//this might not make sense
void createNDCToScreenSpaceMatrix(float width, float height, float matrix[16]){
    //dont compose this matrix with others, reset w coords before use
    //1 for w
    //figuring out the scaling of the z values still
    matrix[0] = (width / 2.0f);     matrix[4] = 0.0f;               matrix[8] = 0.0f;               matrix[12] = (width / 2.0f);
    matrix[1] = 0.0f;               matrix[5] = (height / 2.0f);    matrix[9] = 0.0;                matrix[13] = (height / 2.0f);
    matrix[2] = 0.0;                matrix[6] = 0.0f;               matrix[10] = (height / 2.0f);   matrix[14] = (height / 2.0f);
    matrix[3] = 0.0f;               matrix[7] = 0.0f;               matrix[11] = 0.0f;              matrix[15] = 1.0f;
}
