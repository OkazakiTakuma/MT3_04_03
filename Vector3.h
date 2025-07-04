#pragma once
struct Vector3 {
	float x, y, z;
	Vector3& operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}
	Vector3& operator+=(const Vector3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vector3& operator-=(const Vector3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Vector3& operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}
};
// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2);
Vector3 operator+(const Vector3& v1, const Vector3& v2);
Vector3 operator+(const Vector3& v);


// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
Vector3 operator-(const Vector3& v1, const Vector3& v2) ;
Vector3 operator-(const Vector3& v);

// スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);
Vector3 operator*(float scalar, const Vector3& v);
Vector3 operator*(const Vector3& v, float scalar);
Vector3 operator*(const Vector3& v,const Vector3& v2);

Vector3 operator/(const Vector3& v, float scalar);
	

// 内積
float Dot(const Vector3& v1, const Vector3& v2);
// 長さ (ノルム)
float Length(const Vector3& v);
// 正規化
Vector3 Normalize(const Vector3& v);
// 数値の表記
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);
// クロス積
Vector3 Cross(const Vector3& v1, const Vector3& v2);