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
		Quaternion rotation = MakeRotateAxisAngleQuaternion(Normalize(Vector3{1.0f,0.4f,-0.2f}),0.45f);
		Vector3 point = {2.1f, -0.9f, 1.3f};
		Matrix4x4 rotateMatrix = MakeRotateMatrix(rotation);
		Vector3 rotateByQuaternion = RotateVector(point, rotation);
		Vector3 rotateByMatrix = Transform(point, rotateMatrix);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		
		// VectorScreenPrintf(-20, 0, cross, "Cross");

		ImGui::Begin("window");

		ImGui::End();
		QuaternionScreenPrintf(0, kRowHeight * 0, rotation, " : rotation");
		MatrixScreenPrintf(0, kRowHeight * 6, rotateMatrix, " : rotateMatrix");
		VectorScreenPrintf(0, kRowHeight * 11, rotateByQuaternion, " : rotateByQuaternion");
		VectorScreenPrintf(0, kRowHeight * 12, rotateByMatrix, " : rotateByMatrix");

		
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
