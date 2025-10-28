#include "Matrix.h"
#include "Physics.h"
#include "Screen3.h"
#include "Vector3.h"
#include <Novice.h>
#include <algorithm>
#include <cmath>
#include <imgui.h>
#include"Quaternion.h"

const char kWindowTitle[] = "LD2B_01_オカザキ_タクマ";
static const int kRowHeight = 20;
static const int kColumnWidth = 60;
static const float p = 3.1415f;
static const int kWindowsWidth = 1280;
static const int kWindowsHeight = 720;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowsWidth, kWindowsHeight);
	

	
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	int mousePosX = 0;
	int mousePosY = 0;


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition(&mousePosX, &mousePosY);

		///
		/// ↓更新処理ここから
		///
		Quaternion q1 = {2.0f, 3.0f, 4.0f, 1.0f};
		Quaternion q2 = {1.0f, 3.0f, 5.0f, 2.0f};
		Quaternion identity = IdentityQuaternion();
		Quaternion conjugate = Conjugate(q1);
		Quaternion normalize = Normalize(q1);
		Quaternion inverse = Inverse(q1);
		Quaternion multiply1 = Multiply(q1, q2);
		Quaternion multiply2 = Multiply(q2, q1);
		float norm = Norm(q1);

	
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		
		// VectorScreenPrintf(-20, 0, cross, "Cross");

		ImGui::Begin("window");

		ImGui::End();
		QuaternionScreenPrintf(0, 0, identity, "Identity");
		QuaternionScreenPrintf(0, kRowHeight * 5, conjugate, "Conjugate");
		QuaternionScreenPrintf(0, kRowHeight * 10, inverse, "Inverse");
		QuaternionScreenPrintf(0, kRowHeight * 15, normalize, "Normalize");
		QuaternionScreenPrintf(kColumnWidth * 5, 0, multiply1, "Multyply(q1, q2)");
		QuaternionScreenPrintf(kColumnWidth * 5, kRowHeight * 5, multiply2, "Multyply(q2, q1)");
		Novice::ScreenPrintf(kColumnWidth * 5, kRowHeight * 10, "Norm:%6.02f", norm);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
