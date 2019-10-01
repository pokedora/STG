#pragma once

//###############　ヘッダーファイル読み込み　############
#include "DxLib.h"
#include <string>

//###############　マクロ定義:画像ファイルパスと名前  ########
#define MY_IMG_DIR_JIKI R"(.\MY_IMG\JIKI\)"

#define MY_IMG_NAME_JIKI_1 R"(jiki_1_mini.png)"
#define MY_IMG_NAME_JIKI_2 R"(jiki_2_mini.png)"

//###############  マクロ定義:エラーメッセージ  ############
#define IMAGE_ERROR_TITLE "IAMGE_ERROR"
#define IMAGE_ERROR_MSG "画像が読み込めませんでした"

//############ クラス定義　##########

class IMAGE
{
private:
	std::string FilePath;
	std::string FileName;

	int Handle;

	int X;
	int Y;
	int Width;
	int Height;

	bool IsLoad;		//読み込めたか？
	bool IsDraw;		//描画してもよい？

public:
	IMAGE(const char *, const char *);
   virtual ~IMAGE();

	   std::string GetFileName(void);

	   void SetX(int);
	   void SetY(int);
	   int GetX(void);
	   int GetY(void);
	   int GetWidth(void);
	   int GetHeight(void);

	   bool GetIsLoad(void);

	   void Draw(void);


};