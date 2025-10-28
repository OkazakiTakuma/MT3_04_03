#pragma once
struct Quaternion {
	float x, y, z, w;
};


Quaternion Multiply(const Quaternion& q1, const Quaternion& q2);

Quaternion IdentityQuaternion();

Quaternion Normalize(const Quaternion& q);

Quaternion Conjugate(const Quaternion& q);

float Norm(const Quaternion& q);

Quaternion Inverse(const Quaternion& q);

void QuaternionScreenPrintf(int x, int y, const Quaternion& q, const char* label);