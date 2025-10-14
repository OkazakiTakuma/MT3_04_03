#include "Matrix.h"
#include "Physics.h"
#include "Screen3.h"
#include "Vector3.h"
#include <Novice.h>
#include <algorithm>
#include <cmath>
#include <imgui.h>

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
	Vector3 from0 = Normalize(Vector3{1.0f, 0.7f, 0.5f});
	Vector3 to0 = -from0;
	Vector3 from1 = Normalize(Vector3{-0.6f, 0.9f, 0.2f});
	Vector3 to1 = Normalize(Vector3{0.4f, 0.7f, -0.5f});
	
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

		Matrix4x4 rotateMatrix0 = DirectionToDirection(Normalize(Vector3{1.0f, 0.0f, 0.0f}), Normalize(Vector3{-1.0f, 0.0f, 0.0f}));
		Matrix4x4 rotateMatrix1 = DirectionToDirection(from0, to0);
		Matrix4x4 rotateMatrix2 = DirectionToDirection(from1, to1);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0, 0, rotateMatrix0, "RotateMatrix0");
		MatrixScreenPrintf(0, 100, rotateMatrix1, "RotateMatrix1");
		MatrixScreenPrintf(0, 200, rotateMatrix2, "RotateMatrix2");

		// VectorScreenPrintf(-20, 0, cross, "Cross");

		ImGui::Begin("window");

		ImGui::End();

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
