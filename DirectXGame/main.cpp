#include <Windows.h>

// KamataEngineのインクルード
#include "KamataEngine.h"
// Sceneのインクルード
#include "GameScene.h"
using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	// KamataEngineの初期化
	KamataEngine::Initialize(L"LD2A_05_ババ_イブキ_AL3");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// ゲームシーンのインスタンス作成と初期化
	GameScene* gameScene = new GameScene();
	gameScene->Initialize();

	while (true) {
		// KamataEngineの更新
		if (KamataEngine::Update()) {
			break;
		}

		// ゲームシーンの更新
		gameScene->Update();

		// 描画開始
		dxCommon->PreDraw();

		// ここに描画処理を記述する
		gameScene->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの開放
	delete gameScene;
	gameScene = nullptr;

	// KamataEngineの終了
	KamataEngine::Finalize();

	return 0;
}
