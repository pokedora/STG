#pragma once

//####### �w�b�_�[�t�@�C���ǂݍ��� ########
#include "DxLib.h"

class FPS
{
private:
	int value; //FPS�l
	double drawValue; //Draw����Ƃ���FPS�l
	DWORD calcStartTime; //0�t���[���ڂ̊J�n����
	DWORD calcEndTime; //�ݒ肵���t���[���̏I������
	DWORD flameCount; //�t���[���̃J�E���g
	double calcAverage; //FPS���v�Z���邽�߂̕��σT���v����

public:
	//�R���X�g���N�^
	FPS(int);

	//�w�肵��FPS�ɂȂ�悤�ɑ҂�
	VOID Wait(VOID);

	//��ʍX�V�̎������擾
	VOID Update(VOID);

	//FPS�̒l��\��
	VOID Draw(int, int);

	//FPS�l���擾
	int Getvalue(VOID);

	//�f�X�g���N�^
	virtual ~FPS();
};

extern FPS *fps;