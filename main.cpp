#include "Matrix.h"
#include "Physics.h"
#include "Quaternion.h"
#include "Screen3.h"
#include "Vector3.h"
#include <Novice.h>
#include <algorithm>
#include <cmath>
#include <imgui.h>

const char kWindowTitle[] = "LD2B_01_オカザキ_タクマ";
static const int kRowHeight = 20;
static const int kColumnWidth = 60;
static const float p = 3.141592f;
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

		Quaternion rotation0 = MakeRotateAxisAngleQuaternion({0.71f, 0.71f, 0.0f}, static_cast<float>(0.3f));
		Quaternion rotation1 = MakeRotateAxisAngleQuaternion({0.71f, 0.0f, 0.71f}, static_cast<float>(p));

		Quaternion interplate0 = Slerp(rotation0, rotation1, 0.0f);
		Quaternion interplate1 = Slerp(rotation0, rotation1, 0.3f);
		Quaternion interplate2 = Slerp(rotation0, rotation1, 0.5f);
		Quaternion interplate3 = Slerp(rotation0, rotation1, 0.7f);
		Quaternion interplate4 = Slerp(rotation0, rotation1, 1.0f);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// VectorScreenPrintf(-20, 0, cross, "Cross");

		ImGui::Begin("window");

		ImGui::End();
		QuaternionScreenPrintf(0, kRowHeight * 0, interplate0, " : interplate0");
		QuaternionScreenPrintf(0, kRowHeight * 5, interplate1, " : interplate1");
		QuaternionScreenPrintf(0, kRowHeight * 10, interplate2, " : interplate2");
		QuaternionScreenPrintf(300, kRowHeight * 0, interplate3, " : interplate3");
		QuaternionScreenPrintf(300, kRowHeight * 5, interplate4, " : interplate4");
		
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
