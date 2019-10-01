#pragma once

//###############�@�w�b�_�[�t�@�C���ǂݍ��݁@############
#include "DxLib.h"
#include <string>

//###############�@�}�N����`:�摜�t�@�C���p�X�Ɩ��O  ########
#define MY_IMG_DIR_JIKI R"(.\MY_IMG\JIKI\)"

#define MY_IMG_NAME_JIKI_1 R"(jiki_1_mini.png)"
#define MY_IMG_NAME_JIKI_2 R"(jiki_2_mini.png)"

//###############  �}�N����`:�G���[���b�Z�[�W  ############
#define IMAGE_ERROR_TITLE "IAMGE_ERROR"
#define IMAGE_ERROR_MSG "�摜���ǂݍ��߂܂���ł���"

//############ �N���X��`�@##########

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

	bool IsLoad;		//�ǂݍ��߂����H
	bool IsDraw;		//�`�悵�Ă��悢�H

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