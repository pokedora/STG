#pragma once

//####### ヘッダーファイル読み込み ########
#include "DxLib.h"

class FPS
{
private:
	int value; //FPS値
	double drawValue; //DrawするときのFPS値
	DWORD calcStartTime; //0フレーム目の開始時刻
	DWORD calcEndTime; //設定したフレームの終了時刻
	DWORD flameCount; //フレームのカウント
	double calcAverage; //FPSを計算するための平均サンプル数

public:
	//コンストラクタ
	FPS(int);

	//指定したFPSになるように待つ
	VOID Wait(VOID);

	//画面更新の時刻を取得
	VOID Update(VOID);

	//FPSの値を表示
	VOID Draw(int, int);

	//FPS値を取得
	int Getvalue(VOID);

	//デストラクタ
	virtual ~FPS();
};

extern FPS *fps;