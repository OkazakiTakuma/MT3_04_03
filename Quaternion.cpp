#include "Quaternion.h"
#include <Novice.h>
#include <cmath>
Quaternion Multiply(const Quaternion& q1, const Quaternion& q2) {
	Quaternion result;
	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return result;
}

Quaternion IdentityQuaternion() {

	Quaternion result = {0.0f, 0.0f, 0.0f, 1.0f};
	return result;
}

Quaternion Normalize(const Quaternion& q) {
	Quaternion result;
	float norm = Norm(q);
	result.w = q.w / norm;
	result.x = q.x / norm;
	result.y = q.y / norm;
	result.z = q.z / norm;
	return result;
}

Quaternion Conjugate(const Quaternion& q) {
	Quaternion result;
	result.w = q.w;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	return result;
}

float Norm(const Quaternion& q) { return sqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z); }

Quaternion Inverse(const Quaternion& q) {
	Quaternion result;
	float normSq = q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;
	Quaternion conj = Conjugate(q);
	result.w = conj.w / normSq;
	result.x = conj.x / normSq;
	result.y = conj.y / normSq;
	result.z = conj.z / normSq;
	return result;
}

void QuaternionScreenPrintf(int x, int y, const Quaternion& q, const char* label) {
	const int kRowHeight = 20;
	Novice::ScreenPrintf(x, y, "%s", label);
	Novice::ScreenPrintf(x, y + kRowHeight * 1, "x:%6.02f", q.x);
	Novice::ScreenPrintf(x, y + kRowHeight * 2, "y:%6.02f", q.y);
	Novice::ScreenPrintf(x, y + kRowHeight * 3, "a:%6.02f", q.z);
	Novice::ScreenPrintf(x, y + kRowHeight * 4, "w:%6.02f", q.w);
}
