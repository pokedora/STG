#include "FPS.hpp"

//########### クラスの定義 ##########

//コンストラクタ
FPS::FPS(int fps_value)
{
	this->value = fps_value;
	this->drawValue = 0;
	this->calcStartTime = 0;
	this->calcEndTime = 0;
	this->flameCount = 0;
	this->calcAverage = (double)value;

	return;
}

//指定したFPSになるように待つ
VOID FPS::Wait(VOID)
{
	//現在の時刻をミリ秒で取得
	DWORD nowTime = GetTickCount();

	//1フレーム目から実際にかかった時間を計算	
	DWORD keikaTime = nowTime - this->calcStartTime;

	//ゼロ除算対策
	if (this->value > 0)
	{
		//待つべき時間＝フレーム数ごとにかかる時間ー実際にかかった時間
		int wait_tm = (this->flameCount * 1000 / this->value) - (keikaTime);

		//待つべき時間があった場合
		if (wait_tm > 0)
		{
			//ミリ秒分、処理を中断
			Sleep(wait_tm);
		}

	}
	return;
}

//画面更新の時刻を取得
VOID FPS::Update(VOID)
{
	//1フレーム目なら時刻を記憶
	if (this->flameCount == 0)
	{
		this->calcStartTime = GetTickCount();
	}

	//指定フレームの最後なら、平均を計算
	if (this->flameCount == this->calcAverage)
	{
		//windowsが起動してから現在までの時刻をミリ秒で取得
		this->calcEndTime = GetTickCount();

		//平均的なFPS値を取得
		this->drawValue = 1000.0f / ((this->calcEndTime - this->calcStartTime) / this->calcAverage);

		//次のFPS値の計算の準備
		this->calcStartTime = this->calcEndTime;

		//カウント初期化
		this->flameCount = 0;
	}
	//フレーム数カウントアップ
	this->flameCount++;

	return;
}

//FPS値を表示
VOID FPS::Draw(int drawX,int drawY)
{
	//文字列を描画
	DrawFormatString(drawX, drawY, GetColor(255, 255, 255), "FPS:%.1f", this->drawValue);
	return;
}

//FPS値を取得
int FPS::Getvalue(VOID)
{
	return this->value;
}

//デストラクタ
FPS::~FPS()
{
	return;
}
