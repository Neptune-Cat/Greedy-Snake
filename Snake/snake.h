#pragma once
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>  //��ý���豸�ӿ�
#pragma comment(lib,"winmm.lib")  //���ؾ�̬��
#include<conio.h>  //����̨�������ͷ�ļ�
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<easyx.h>
#include<conio.h>
extern "C"
{
#include"snake.h"
}

int n01 = 0;//��ҳ�ķ���ֵ���жϽ������õ�ҳ��
int n02 = 0;//���õķ���ֵ���жϽ�����Ч��ҳ��
int n03 = 0;//��ʼ��Ϸ�ķ���ֵ�жϽ��������Ϸģʽ
int n04 = 0;//����ģʽѡ���н��޽����
int n05 = 0;//����ģʽѡ��ؿ�����

#define SNAKE_NUM 400000  //�ߵ�������

int a = 325, A = 200, b = 340, B = 275;//ǽ�����꣬����ȫ�ֱ�����
int z = 180, Z = 445, g = 195, G = 495;//ǽ�����꣬����ȫ�ֱ�����
int c = 700, C = 260, d = 785, D = 275;//ǽ�����꣬����ȫ�ֱ�����
int count = 1000;
int T1 = 445;//����ȫ�ֱ���T1��ʵ�ַ���ı�
int T2 = 400;//����ȫ�ֱ���T2��ʵ�ַ���ı�
int T3 = 565;//����ȫ�ֱ���T3��ʵ�ַ���ı�
int e = 0;  //��ʵ�����
int E = 1; //��Ƭ
int a5 = 250, A5 = 290, b5 = 250, B5 = 372;//�ؿ�1�ƶ�ǽ
int a6 = 715, A6 = 235, b6 = 800, B6 = 235;
int t5 = 210;
int t6 = 465;
//�ؿ���3��ǽ
int a1 = 330, A1 = 450, b1 = 470, B1 = 460;
int a2 = 530, A2 = 340, b2 = 600, B2 = 350;
int a3 = 520, A3 = 70, b3 = 530, B3 = 160;
int t3 = 10;
int t2 = 385;
int t1 = 280;
//�ؿ�4�ƶ�ǽ
int a8 = 450, A8 = 575, b8 = 450, B8 = 600;
int a9 = 150, A9 = 450, b9 = 300, B9 = 450;
int t8 = 500;
int t9 = 75;

//�ߵķ���
enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

//�ߵĽṹ
struct Snake
{
	int size;  //�ߵĽ���
	int dir;  //����
	int speed;  //�ٶ�
	POINT coor[SNAKE_NUM];  //����
}snake;

//�ƶ���
void snakeMove()
{
	//����
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];
	}
	//�ƶ��ı�
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y -= snake.speed;
		if (snake.coor[0].y <= 0)
		{
			snake.coor[0].y = 600;
		}
		break;
	case DOWN:
		snake.coor[0].y += snake.speed;
		if (snake.coor[0].y >= 600)
		{
			snake.coor[0].y = 0;
		}
		break;
	case LEFT:
		snake.coor[0].x -= snake.speed;
		if (snake.coor[0].x <= 0)
		{
			snake.coor[0].x = 800;
		}
		break;
	case RIGHT:
		snake.coor[0].x += snake.speed;
		if (snake.coor[0].x >= 800)
		{
			snake.coor[0].x = 0;
		}
		break;
	}

}

//ͨ�������ı��ߵ��ƶ�����
void keyControl()
{
	//�ж���û�а���,��������򷵻�true
	if (_kbhit())
	{
		//72 80 75 77 ��������
		switch (_getch())
		{
		case'w':
		case'W':
			if (snake.dir != DOWN)
			{
				snake.dir = UP;
			}
			break;
		case's':
		case'S':
			if (snake.dir != UP)
			{
				snake.dir = DOWN;
			}
			break;
		case'a':
		case'A':
			if (snake.dir != RIGHT)
			{
				snake.dir = LEFT;
			}
			break;
		case'd':
		case'D':
			if (snake.dir != LEFT)
			{
				snake.dir = RIGHT;
			}
			break;
			//��Ϸ��ͣ
		case 'p':
		case 'P':
			system("pause>nu1");
			break;
		}
	}
}


//�ߵ������ж�      ����ֵΪ��
bool snakeDead1()
{
	if (snake.coor[0].x <= 0 || snake.coor[0].x >= 800 || snake.coor[0].y <= 0 || snake.coor[0].y >= 600 || ((snake.coor[0].x >= 0 && snake.coor[0].x <= 100) && (snake.coor[0].y >= 150 && snake.coor[0].y <= 150)) ||
		((snake.coor[0].x >= 0 && snake.coor[0].x <= 150) && (snake.coor[0].y >= 300 && snake.coor[0].y <= 300)) || ((snake.coor[0].x >= 0 && snake.coor[0].x <= 100) && (snake.coor[0].y >= 450 && snake.coor[0].y <= 450))
		|| ((snake.coor[0].x >= 100 && snake.coor[0].x <= 100) && (snake.coor[0].y >= 0 && snake.coor[0].y >= 100)) || ((snake.coor[0].x >= 100 && snake.coor[0].x <= 100)
			&& (snake.coor[0].y >= 395 && snake.coor[0].y <= 450)) || ((snake.coor[0].x >= 200 && snake.coor[0].x <= 300) && (snake.coor[0].y >= 525 && snake.coor[0].y <= 600))
		|| ((snake.coor[0].x >= 300 && snake.coor[0].x <= 300) && (snake.coor[0].y >= 525 && snake.coor[0].y <= 600)) || ((snake.coor[0].x >= 200 && snake.coor[0].x <= 200)
			&& (snake.coor[0].y >= 100 && snake.coor[0].y <= 125)) || ((snake.coor[0].x >= 200 && snake.coor[0].x <= 300) && (snake.coor[0].y >= 100 && snake.coor[0].y <= 100))
		|| ((snake.coor[0].x >= 250 && snake.coor[0].x <= 250) && (snake.coor[0].y >= 0 && snake.coor[0].y <= 125)) || ((snake.coor[0].x >= 215 && snake.coor[0].x <= 515)
			&& (snake.coor[0].y >= 215 && snake.coor[0].y <= 215)) || ((snake.coor[0].x >= 250 && snake.coor[0].x <= 250) && (snake.coor[0].y >= 290 && snake.coor[0].y <= 375))
		|| ((snake.coor[0].x >= 100 && snake.coor[0].x <= 250) && (snake.coor[0].y >= 375 && snake.coor[0].y <= 375)) || ((snake.coor[0].x >= 250 && snake.coor[0].x <= 320)
			&& (snake.coor[0].y >= 375 && snake.coor[0].y <= 385)) || ((snake.coor[0].x >= 300 && snake.coor[0].x <= 300) && (snake.coor[0].y >= 175 && snake.coor[0].y <= 215))
		|| ((snake.coor[0].x >= 100 && snake.coor[0].x <= 100) && (snake.coor[0].y >= 375 && snake.coor[0].y <= 450)) || ((snake.coor[0].x >= 405 && snake.coor[0].x <= 615)
			&& (snake.coor[0].y >= 105 && snake.coor[0].y <= 105)) || ((snake.coor[0].x >= 405 && snake.coor[0].x <= 405) && (snake.coor[0].y >= 105 && snake.coor[0].y <= 135))
		|| ((snake.coor[0].x >= 565 && snake.coor[0].x <= 565) && (snake.coor[0].y >= 105 && snake.coor[0].y <= 200)) || ((snake.coor[0].x >= 515 && snake.coor[0].x <= 615)
			&& (snake.coor[0].y >= 175 && snake.coor[0].y <= 175)) || ((snake.coor[0].x >= 515 && snake.coor[0].x <= 515) && (snake.coor[0].y >= 175 && snake.coor[0].y <= 215))
		|| ((snake.coor[0].x >= 435 && snake.coor[0].x <= 435) && (snake.coor[0].y >= 215 && snake.coor[0].y <= 275)) || ((snake.coor[0].x >= 435 && snake.coor[0].x <= 515)
			&& (snake.coor[0].y >= 275 && snake.coor[0].y <= 275)) || ((snake.coor[0].x >= 515 && snake.coor[0].x <= 515) && (snake.coor[0].y >= 275 && snake.coor[0].y <= 375))
		|| ((snake.coor[0].x >= 405 && snake.coor[0].x >= 515) && (snake.coor[0].y >= 375 && snake.coor[0].y <= 375)) || ((snake.coor[0].x >= 450 && snake.coor[0].x <= 515)
			&& (snake.coor[0].y >= 375 && snake.coor[0].y <= 375)) || ((snake.coor[0].x >= 405 && snake.coor[0].x <= 500) && (snake.coor[0].y >= 500 && snake.coor[0].y <= 500))
		|| ((snake.coor[0].x >= 500 && snake.coor[0].x >= 570) && (snake.coor[0].y >= 450 && snake.coor[0].y <= 450)) || ((snake.coor[0].x >= 515 && snake.coor[0].x <= 515)
			&& (snake.coor[0].y >= 0 && snake.coor[0].y <= 50)) || ((snake.coor[0].x >= 615 && snake.coor[0].x <= 615) && (snake.coor[0].y >= 125 && snake.coor[0].y <= 200))
		|| ((snake.coor[0].x >= 615 && snake.coor[0].x <= 615) && (snake.coor[0].y >= 65 && snake.coor[0].y <= 105)) || ((snake.coor[0].x >= 685 && snake.coor[0].x <= 685)
			&& (snake.coor[0].y >= 100 && snake.coor[0].y <= 155)) || ((snake.coor[0].x >= 680 && snake.coor[0].x <= 730) && (snake.coor[0].y >= 130 && snake.coor[0].y <= 130))
		|| ((snake.coor[0].x >= 740 && snake.coor[0].x <= 740) && (snake.coor[0].y >= 200 && snake.coor[0].y <= 235)) || ((snake.coor[0].x >= 715 && snake.coor[0].x <= 735)
			&& (snake.coor[0].y >= 235 && snake.coor[0].y <= 235)) || ((snake.coor[0].x >= 600 && snake.coor[0].x <= 600) && (snake.coor[0].y >= 265 && snake.coor[0].x <= 350))
		|| ((snake.coor[0].x >= 600 && snake.coor[0].x <= 725) && (snake.coor[0].y >= 350 && snake.coor[0].y <= 350)) || ((snake.coor[0].x >= 675 && snake.coor[0].x <= 675)
			&& (snake.coor[0].y >= 300 && snake.coor[0].y <= 350)) || ((snake.coor[0].x >= 675 && snake.coor[0].x <= 675) && (snake.coor[0].y >= 350 && snake.coor[0].y <= 385))
		|| ((snake.coor[0].x >= 725 && snake.coor[0].x <= 725) && (snake.coor[0].y >= 350 && snake.coor[0].y <= 480)) || ((snake.coor[0].x >= 695 && snake.coor[0].x <= 800)
			&& (snake.coor[0].y >= 420 && snake.coor[0].y <= 420)) || ((snake.coor[0].x >= 595 && snake.coor[0].x <= 630) && (snake.coor[0].y >= 550 && snake.coor[0].y <= 550))
		|| ((snake.coor[0].x >= 595 && snake.coor[0].x <= 565) && (snake.coor[0].y >= 550 && snake.coor[0].y <= 600)) || ((snake.coor[0].x >= 800 && snake.coor[0].x <= 800)
			&& (snake.coor[0].y >= 370 && snake.coor[0].y <= 420)) || ((snake.coor[0].x >= 0 && snake.coor[0].x <= 300) && (snake.coor[0].y >= 600 && snake.coor[0].y <= 600))
		|| /*((snake.coor[0].x >= 405 && snake.coor[0].x <= 800)*/  ((snake.coor[0].x >= 800 && snake.coor[0].x <= 800)
			&& (snake.coor[0].y >= 0 && snake.coor[0].y <= 250)) || ((snake.coor[0].x > 800 && snake.coor[0].x <= 800) && (snake.coor[0].y <= 390 && snake.coor[0].y <= 600))
		/*|| ((snake.coor[0].x >= 250 && snake.coor[0].x <= 405) && (snake.coor[0].y >= 375 && snake.coor[0].y <= 375)) || ((snake.coor[0].x >= 100 && snake.coor[0].x <= 100)
			&& (snake.coor[0].y >= 75 && snake.coor[0].y <= 150))*/ || ((snake.coor[0].x >= 0 && snake.coor[0].x <= 150) && (snake.coor[0].y >= 300 && snake.coor[0].y <= 300))
		|| ((snake.coor[0].x >= 595 && snake.coor[0].x <= 800) && (snake.coor[0].y >= 600 && snake.coor[0].y <= 600)))
	{
		return false;
	}
	else
		return true;
	for (int i = 1; i < snake.size - 1; i++)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
		{
			return false;
		}
	}
}

//�ߵ������ж�      ����ֵΪ��
bool snakeDead2()
{
	if (snake.coor[0].x == 15 || snake.coor[0].x == 785 || snake.coor[0].y >= 585 || snake.coor[0].y == 15)
	{
		return false;
	}
	else if ((snake.coor[0].x == 65 && snake.coor[0].y <= 110 && snake.coor[0].y >= 15) || (snake.coor[0].x == 85 && snake.coor[0].y <= 110 && snake.coor[0].y >= 15))
	{
		return false;
	}
	else if ((snake.coor[0].x >= 15 && snake.coor[0].x <= 200 && snake.coor[0].y == 225) || (snake.coor[0].x >= 15 && snake.coor[0].x <= 200 && snake.coor[0].y == 210))
	{
		return false;
	}

	else if ((snake.coor[0].x == 185 && snake.coor[0].y >= 225 && snake.coor[0].y <= 310) || (snake.coor[0].x == 200 && snake.coor[0].y >= 225 && snake.coor[0].y <= 310))
	{
		return false;
	}
	else if ((snake.coor[0].x >= 15 && snake.coor[0].x <= 100 && snake.coor[0].y == 430) || (snake.coor[0].x >= 15 && snake.coor[0].x <= 100 && snake.coor[0].y == 445))
	{
		return false;
	}
	else if ((snake.coor[0].y >= 395 && snake.coor[0].y <= 510 && snake.coor[0].x == 100) || (snake.coor[0].y >= 395 && snake.coor[0].y <= 510 && snake.coor[0].x == 115))
	{
		return false;
	}
	else if ((snake.coor[0].x >= 115 && snake.coor[0].x <= 415 && snake.coor[0].y == 495) || (snake.coor[0].x >= 115 && snake.coor[0].x <= 415 && snake.coor[0].y == 510))
	{
		return false;
	}
	else if ((snake.coor[0].y >= Z && snake.coor[0].y <= G && snake.coor[0].x == z) || (snake.coor[0].y >= Z && snake.coor[0].y <= G && snake.coor[0].x == g))
	{
		return false;
	}

	else if ((snake.coor[0].y >= 400 && snake.coor[0].y <= 495 && snake.coor[0].x == 325) || (snake.coor[0].y >= 400 && snake.coor[0].y <= 495 && snake.coor[0].x == 340))
	{
		return false;
	}
	else if ((snake.coor[0].y >= A && snake.coor[0].y <= B && snake.coor[0].x == a) || (snake.coor[0].y >= A && snake.coor[0].y <= B && snake.coor[0].x == b))
	{
		return false;
	}

	else if ((snake.coor[0].y >= 15 && snake.coor[0].y <= 110 && snake.coor[0].x == 325) || (snake.coor[0].y >= 15 && snake.coor[0].y <= 110 && snake.coor[0].x == 340))
	{
		return false;
	}
	else if ((snake.coor[0].y >= 60 && snake.coor[0].y <= 400 && snake.coor[0].x == 460) || (snake.coor[0].y >= 60 && snake.coor[0].y <= 400 && snake.coor[0].x == 475))
	{
		return false;
	}
	else if ((snake.coor[0].x >= 460 && snake.coor[0].x <= 650 && snake.coor[0].y == 400) || (snake.coor[0].x >= 460 && snake.coor[0].x <= 650 && snake.coor[0].y == 415))
	{
		return false;
	}
	else if ((snake.coor[0].x >= 460 && snake.coor[0].x <= 565 && snake.coor[0].y == 85) || (snake.coor[0].x >= 460 && snake.coor[0].x <= 565 && snake.coor[0].y == 100))
	{
		return false;
	}
	else if ((snake.coor[0].y >= 100 && snake.coor[0].y <= 315 && snake.coor[0].x == 550) || (snake.coor[0].y >= 100 && snake.coor[0].y <= 315 && snake.coor[0].x == 565))
	{
		return false;
	}
	else if ((snake.coor[0].y >= 415 && snake.coor[0].y <= 495 && snake.coor[0].x == 635) || (snake.coor[0].y >= 415 && snake.coor[0].y <= 495 && snake.coor[0].x == 650))
	{
		return false;
	}
	else if ((snake.coor[0].y >= C && snake.coor[0].y <= D && snake.coor[0].x == c) || (snake.coor[0].y >= C && snake.coor[0].y <= D && snake.coor[0].x == d))
	{
		return false;
	}
	else if ((snake.coor[0].y >= 15 && snake.coor[0].y <= 125 && snake.coor[0].x == 660) || (snake.coor[0].y >= 15 && snake.coor[0].y <= 125 && snake.coor[0].x == 675))
	{
		return false;
	}
	else if ((count <= 500) && (snake.coor[0].x >= 640 - 40 && snake.coor[0].x <= 640 + 40 && snake.coor[0].y >= 540 - 40 && snake.coor[0].y <= 540 + 40))
	{
		return false;
	}
	else
		return true;
	count = count - 5;
	if (count == 0)
	{
		count = 1000;
		return false;
	}
	for (int i = 1; i < snake.size - 1; i++)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
		{
			return false;
		}
	}
}

//�ߵ������ж�      ����ֵΪ��
bool snakeDead3()
{
	int x = snake.coor[0].x, y = snake.coor[0].y;
	if ((snake.coor[0].x >= 0 && snake.coor[0].x <= 800 && snake.coor[0].y >= 0 && snake.coor[0].y <= 10)
		|| (snake.coor[0].x >= 0 && snake.coor[0].x <= 10 && snake.coor[0].y >= 10 && snake.coor[0].y <= 590)
		|| (snake.coor[0].x >= 790 && snake.coor[0].x <= 800 && snake.coor[0].y >= 800 && snake.coor[0].y <= 590)
		|| (snake.coor[0].x >= 0 && snake.coor[0].x <= 800 && snake.coor[0].y >= 590 && snake.coor[0].y <= 600)
		|| (snake.coor[0].x >= 10 && snake.coor[0].x <= 200 && snake.coor[0].y >= 60 && snake.coor[0].y <= 70)
		|| (snake.coor[0].x >= 10 && snake.coor[0].x <= 60 && snake.coor[0].y >= 250 && snake.coor[0].y <= 260)
		|| (snake.coor[0].x >= 10 && snake.coor[0].x <= 160 && snake.coor[0].y >= 460 && snake.coor[0].y <= 470)
		|| (snake.coor[0].x >= 60 && snake.coor[0].x <= 130 && snake.coor[0].y >= 520 && snake.coor[0].y <= 530)
		|| (snake.coor[0].x >= 110 && snake.coor[0].x <= 270 && snake.coor[0].y >= 140 && snake.coor[0].y <= 150)
		|| (snake.coor[0].x >= 70 && snake.coor[0].x <= 250 && snake.coor[0].y >= 250 && snake.coor[0].y <= 260)
		|| (snake.coor[0].x >= 140 && snake.coor[0].x <= 290 && snake.coor[0].y >= 340 && snake.coor[0].y <= 350)
		|| (snake.coor[0].x >= 280 && snake.coor[0].x <= 470 && snake.coor[0].y >= 170 && snake.coor[0].y <= 180)
		|| (snake.coor[0].x >= 280 && snake.coor[0].x <= 370 && snake.coor[0].y >= 300 && snake.coor[0].y <= 310)
		|| (snake.coor[0].x >= 330 && snake.coor[0].x <= 470 && snake.coor[0].y >= 450 && snake.coor[0].y <= 460)
		|| (snake.coor[0].x >= 250 && snake.coor[0].x <= 440 && snake.coor[0].y >= 520 && snake.coor[0].y <= 530)
		|| (snake.coor[0].x >= 440 && snake.coor[0].x <= 520 && snake.coor[0].y >= 100 && snake.coor[0].y <= 110)
		|| (snake.coor[0].x >= 370 && snake.coor[0].x <= 680 && snake.coor[0].y >= 250 && snake.coor[0].y <= 260)
		|| (snake.coor[0].x >= 530 && snake.coor[0].x <= 600 && snake.coor[0].y >= 340 && snake.coor[0].y <= 350)
		|| (snake.coor[0].x >= 480 && snake.coor[0].x <= 590 && snake.coor[0].y >= 400 && snake.coor[0].y <= 410)
		|| (snake.coor[0].x >= 530 && snake.coor[0].x <= 650 && snake.coor[0].y >= 100 && snake.coor[0].y <= 110)
		|| (snake.coor[0].x >= 590 && snake.coor[0].x <= 700 && snake.coor[0].y >= 50 && snake.coor[0].y <= 60)
		|| (snake.coor[0].x >= 590 && snake.coor[0].x <= 790 && snake.coor[0].y >= 160 && snake.coor[0].y <= 170)
		|| (snake.coor[0].x >= 620 && snake.coor[0].x <= 770 && snake.coor[0].y >= 460 && snake.coor[0].y <= 470)
		|| (snake.coor[0].x >= 530 && snake.coor[0].x <= 740 && snake.coor[0].y >= 520 && snake.coor[0].y <= 530)
		|| (snake.coor[0].x >= 740 && snake.coor[0].x <= 790 && snake.coor[0].y >= 310 && snake.coor[0].y <= 320)
		|| (snake.coor[0].x >= 60 && snake.coor[0].x <= 70 && snake.coor[0].y >= 200 && snake.coor[0].y <= 320)
		|| (snake.coor[0].x >= 130 && snake.coor[0].x <= 140 && snake.coor[0].y >= 310 && snake.coor[0].y <= 410)
		|| (snake.coor[0].x >= 60 && snake.coor[0].x <= 70 && snake.coor[0].y >= 530 && snake.coor[0].y <= 590)
		|| (snake.coor[0].x >= 130 && snake.coor[0].x <= 140 && snake.coor[0].y >= 310 && snake.coor[0].y <= 410)
		|| (snake.coor[0].x >= 200 && snake.coor[0].x <= 210 && snake.coor[0].y >= 410 && snake.coor[0].y <= 590)
		|| (snake.coor[0].x >= 270 && snake.coor[0].x <= 280 && snake.coor[0].y >= 70 && snake.coor[0].y <= 210)
		|| (snake.coor[0].x >= 270 && snake.coor[0].x <= 280 && snake.coor[0].y >= 350 && snake.coor[0].y <= 520)
		|| (snake.coor[0].x >= 370 && snake.coor[0].x <= 380 && snake.coor[0].y >= 10 && snake.coor[0].y <= 70)
		|| (snake.coor[0].x >= 370 && snake.coor[0].x <= 380 && snake.coor[0].y >= 180 && snake.coor[0].y <= 400)
		|| (snake.coor[0].x >= 430 && snake.coor[0].x <= 440 && snake.coor[0].y >= 95 && snake.coor[0].y <= 170)
		|| (snake.coor[0].x >= 520 && snake.coor[0].x <= 530 && snake.coor[0].y >= 70 && snake.coor[0].y <= 160)
		|| (snake.coor[0].x >= 520 && snake.coor[0].x <= 530 && snake.coor[0].y >= 410 && snake.coor[0].y <= 560)
		|| (snake.coor[0].x >= 560 && snake.coor[0].x <= 570 && snake.coor[0].y >= 260 && snake.coor[0].y <= 345)
		|| (snake.coor[0].x >= 650 && snake.coor[0].x <= 660 && snake.coor[0].y >= 70 && snake.coor[0].y <= 170)
		|| (snake.coor[0].x >= 650 && snake.coor[0].x <= 660 && snake.coor[0].y >= 300 && snake.coor[0].y <= 470)
		|| (snake.coor[0].x >= 740 && snake.coor[0].x <= 750 && snake.coor[0].y >= 70 && snake.coor[0].y <= 160))
	{
		return false;
	}
	else
		return true;
	for (int i = 1; i < snake.size - 1; i++)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
		{
			return false;
		}
	}
}

////�ߵ������ж�      ����ֵΪ��
//bool snakeDead4()
//{
//	if ((snake.coor[0].x <= 0 && snake.coor[0].x >= 800 || snake.coor[0].y <= 0 && snake.coor[0].y >= 600 || snake.coor[0].x >= 75 && snake.coor[0].x <= 75 || snake.coor[0].y >= 0 && snake.coor[0].y <= 100)
//		|| (snake.coor[0].x >= 0 && snake.coor[0].x <= 800 || snake.coor[0].y >= 600 && snake.coor[0].y <= 600 || snake.coor[0].x >= 50 && snake.coor[0].x <= 100 || snake.coor[0].y >= 100 && snake.coor[0].y <= 100)
//		|| (snake.coor[0].x >= 0 && snake.coor[0].x <= 0 || snake.coor[0].y >= 0 && snake.coor[0].y >= 150 || snake.coor[0].x >= 0 && snake.coor[0].x <= 0)
//		|| (snake.coor[0].y >= 0 && snake.coor[0].y <= 150 || snake.coor[0].x >= 0 && snake.coor[0].x <= 0 || snake.coor[0].y >= 450 && snake.coor[0].y <= 600)
//		|| (snake.coor[0].x >= 0 && snake.coor[0].x <= 75 || snake.coor[0].y >= 450 && snake.coor[0].y <= 450 || snake.coor[0].x >= 0 && snake.coor[0].x <= 25)
//		|| (snake.coor[0].y >= 300 && snake.coor[0].y <= 300 || snake.coor[0].x >= 95 && snake.coor[0].x <= 125 || snake.coor[0].y >= 300 && snake.coor[0].y <= 300)
//		|| (snake.coor[0].x >= 150 && snake.coor[0].x <= 300 || snake.coor[0].y >= 450 && snake.coor[0].y <= 450 || snake.coor[0].x >= 75 && snake.coor[0].x <= 75)
//		|| (snake.coor[0].y >= 520 && snake.coor[0].y <= 520 || snake.coor[0].x >= 325 && snake.coor[0].x <= 325 || snake.coor[0].y >= 0 && snake.coor[0].y <= 400)
//		|| (snake.coor[0].x >= 375 && snake.coor[0].x <= 375 || snake.coor[0].y >= 400 && snake.coor[0].y <= 550 || snake.coor[0].x >= 400 && snake.coor[0].x <= 400)
//		|| (snake.coor[0].y <= 75 && snake.coor[0].y <= 250 || snake.coor[0].x >= 400 && snake.coor[0].x <= 450 || snake.coor[0].y >= 250 && snake.coor[0].y <= 250)
//		|| (snake.coor[0].x >= 450 && snake.coor[0].x <= 450 || snake.coor[0].y >= 250 && snake.coor[0].y <= 500 || snake.coor[0].x >= 450 && snake.coor[0].x <= 450)
//		|| (snake.coor[0].y >= 575 && snake.coor[0].y <= 600 || snake.coor[0].x >= 600 && snake.coor[0].x <= 600 || snake.coor[0].y >= 55 && snake.coor[0].y <= 350)
//		|| (snake.coor[0].x >= 600 && snake.coor[0].x <= 600 || snake.coor[0].y >= 450 && snake.coor[0].y <= 600 || snake.coor[0].x >= 600 && snake.coor[0].x <= 650)
//		|| (snake.coor[0].y >= 125 && snake.coor[0].y <= 125 || snake.coor[0].x >= 650 && snake.coor[0].x <= 650 || snake.coor[0].y >= 0 && snake.coor[0].y <= 125)
//		|| (snake.coor[0].x >= 700 && snake.coor[0].x <= 720 || snake.coor[0].y >= 300 && snake.coor[0].y <= 300 || snake.coor[0].x >= 700 && snake.coor[0].x <= 700)
//		|| (snake.coor[0].y >= 300 && snake.coor[0].y <= 500 || snake.coor[0].x >= 700 && snake.coor[0].x <= 700 || snake.coor[0].y >= 575 && snake.coor[0].y <= 600)
//		|| (snake.coor[0].x >= 775 && snake.coor[0].x >= 800 || snake.coor[0].y >= 25 && snake.coor[0].y <= 25 || snake.coor[0].x >= 775 && snake.coor[0].x <= 775)
//		|| (snake.coor[0].y >= 25 && snake.coor[0].y <= 95 || snake.coor[0].x >= 775 && snake.coor[0].x <= 800 || snake.coor[0].y >= 95 && snake.coor[0].y <= 95)
//		|| (snake.coor[0].x >= 775 && snake.coor[0].x >= 800 || snake.coor[0].y >= 225 && snake.coor[0].y <= 225 || snake.coor[0].x >= 775 && snake.coor[0].x <= 775)
//		|| (snake.coor[0].y >= 225 && snake.coor[0].y <= 350 || snake.coor[0].x >= 745 && snake.coor[0].x <= 775 || snake.coor[0].y >= 350 && snake.coor[0].y <= 350)
//		|| (snake.coor[0].x >= 745 && snake.coor[0].x <= 745 || snake.coor[0].y >= 350 && snake.coor[0].y <= 450 || snake.coor[0].x >= 800 && snake.coor[0].x <= 800)
//		|| (snake.coor[0].y >= 0 && snake.coor[0].y <= 25 || snake.coor[0].x >= 800 && snake.coor[0].x <= 800 || snake.coor[0].y >= 25 && snake.coor[0].y <= 350)
//		|| (snake.coor[0].x >= 800 && snake.coor[0].x <= 800 || snake.coor[0].y >= 350 && snake.coor[0].y <= 600 || snake.coor[0].x >= 325 && snake.coor[0].x <= 375)
//		|| (snake.coor[0].y >= 400 && snake.coor[0].y <= 400 || snake.coor[0].x >= 250 && snake.coor[0].x <= 250 || snake.coor[0].y >= 0 && snake.coor[0].x <= 125)
//		|| (snake.coor[0].x >= 175 && snake.coor[0].x <= 250 || snake.coor[0].y >= 125 && snake.coor[0].y <= 125 || snake.coor[0].x >= 175 && snake.coor[0].x <= 175)
//		|| (snake.coor[0].y >= 125 && snake.coor[0].y <= 250 || snake.coor[0].x >= 175 && snake.coor[0].x <= 250 || snake.coor[0].y >= 250 && snake.coor[0].y <= 250)
//		|| (snake.coor[0].x >= 250 && snake.coor[0].x <= 250 || snake.coor[0].y >= 250 && snake.coor[0].y <= 350 || snake.coor[0].x >= 450 && snake.coor[0].x <= 550)
//		|| (snake.coor[0].y >= 125 && snake.coor[0].y <= 125 || snake.coor[0].x >= 450 && snake.coor[0].x <= 450 || snake.coor[0].y >= 125 && snake.coor[0].y <= 165)
//		|| (snake.coor[0].x >= 450 && snake.coor[0].x <= 550 || snake.coor[0].y >= 165 && snake.coor[0].y <= 165 || snake.coor[0].x >= 550 && snake.coor[0].x <= 550)
//		|| (snake.coor[0].y >= 125 && snake.coor[0].y <= 165 || snake.coor[0].x >= 800 && snake.coor[0].x <= 800 || snake.coor[0].y >= 25 && snake.coor[0].y <= 95)
//		|| (snake.coor[0].x >= 775 && snake.coor[0].x <= 800 || snake.coor[0].y >= 350 && snake.coor[0].y <= 350 || snake.coor[0].x >= 450 && snake.coor[0].x <= 550)
//		|| (snake.coor[0].y >= 125 && snake.coor[0].y <= 125 || snake.coor[0].x > 450 && snake.coor[0].x <= 450 || snake.coor[0].y <= 125 && snake.coor[0].y <= 165)
//		|| (snake.coor[0].x = 550 && snake.coor[0].x <= 550 || snake.coor[0].y >= 125 && snake.coor[0].y <= 165 || snake.coor[0].x >= 450 && snake.coor[0].x <= 450)
//		|| (snake.coor[0].y >= 165 && snake.coor[0].y <= 165 || snake.coor[0].x >= 100 && snake.coor[0].x <= 100 || snake.coor[0].y >= 100 && snake.coor[0].y <= 150)
//		|| (snake.coor[0].x >= 25 && snake.coor[0].x <= 95 || snake.coor[0].y >= 300 && snake.coor[0].y <= 300 || snake.coor[0].x >= 75 && snake.coor[0].x <= 150)
//		|| (snake.coor[0].y >= 450 && snake.coor[0].y <= 450 || snake.coor[0].x >= 450 && snake.coor[0].x <= 450 || snake.coor[0].y >= 500 && snake.coor[0].y <= 575)
//		|| (snake.coor[0].x >= 450 && snake.coor[0].x <= 700 || snake.coor[0].y >= 300 && snake.coor[0].y <= 300 || snake.coor[0].x >= 600 && snake.coor[0].x <= 600)
//		|| (snake.coor[0].y >= 350 && snake.coor[0].y <= 450 || snake.coor[0].x >= 700 && snake.coor[0].x <= 700 || snake.coor[0].y >= 450 && snake.coor[0].y <= 575)
//		|| (snake.coor[0].x >= 745 && snake.coor[0].x <= 800 || snake.coor[0].y >= 450 && snake.coor[0].y <= 450))
//	{
//		return false;
//	}
//	else
//		return true;
//	for (int i = 1; i < snake.size - 1; i++)
//	{
//		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
//		{
//			return false;
//		}
//	}
//}


//ʳ��ṹ
struct Food
{
	int x;
	int y;
	int r;  //��ʵ�Ĵ�С
	bool flag;  //��ʵ�Ƿ񱻳�
	bool Peice1;  //��Ƭ�Ƿ񱻳�
	bool Peice2;
	bool Peice3;
	bool Peice4;
	bool Peice5;
	bool Peice6;
	bool Peice7;
	bool Peice8;
	bool Peice9;
	bool Peice10;
	bool Peice11;
	bool Peice12;
	DWORD color;  //ʳ����ɫ
}food;

//�Ե���ʵ���ߵ÷֣���ʵˢ�£�ģʽ2)
void EatFruitScore2()
{
	if (food.flag && snake.coor[0].x >= food.x - 2 - food.r && snake.coor[0].x <= food.x + 2 + food.r &&
		snake.coor[0].y >= food.y - 2 - food.r && snake.coor[0].y <= food.y + 2 + food.r)
	{
		food.flag = false;
		snake.size++;
	}
	//��ʵˢ�£������
	if (!food.flag)
	{
		food.x = rand() % 790;
		food.y = rand() % 590;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = 5;
		food.flag = true;
	}
}

//�Ե���Ƭ���ߵ÷֣���Ƭˢ�£��ؿ�1��2��3��4)
void EatPScore2()
{
	int x = food.x, y = food.y;
	switch (E)
	{
	case 1:
		if (food.Peice1 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice1 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice1)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice2 = true;
			++E;
		}
		break;
	case 2:
		if (food.Peice2 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice2 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice2)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice3 = true;
		}
		break;
	case 3:
		if (food.Peice3 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice3 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice3)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice4 = true;
		}
		break;
	case 4:
		if (food.Peice4 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice4 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice4)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice5 = true;
		}
		break;
	case 5:
		if (food.Peice5 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice5 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice5)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice6 = true;
		}
		break;
	case 6:
		if (food.Peice6 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice6 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice6)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice7 = true;
		}
		break;
	case 7:
		if (food.Peice7 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice7 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice7)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice8 = true;
		}
		break;
	case 8:
		if (food.Peice8 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice8 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice8)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice9 = true;
		}
		break;
	case 9:
		if (food.Peice9 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice9 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice9)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice10 = true;
		}
		break;
	case 10:
		if (food.Peice10 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice10 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice10)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice11 = true;
		}
		break;
	case 11:
		if (food.Peice11 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice11 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice11)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice12 = true;
		}
		break;
	case 12:
		if (food.Peice12 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice12 = false;
				snake.size++;
				++E;
		}
		break;
	}
}

void EatPScore1()
{
	switch (E)
	{
	case 1:
		if (food.Peice1 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice1 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice1)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice2 = true;
			++E;
		}
		break;
	case 2:
		if (food.Peice2 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice2 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice2)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice3 = true;
			++E;
		}
		break;
	case 3:
		if (food.Peice3 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice3 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice3)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice4 = true;
			++E;
		}
		break;
	case 4:
		if (food.Peice4 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice4 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice4)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice5 = true;
			++E;
		}
		break;
	case 5:
		if (food.Peice5 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice5 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice5)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice6 = true;
			++E;
		}
		break;
	case 6:
		if (food.Peice6 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice6 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice6)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice7 = true;
			++E;
		}
		break;
	case 7:
		if (food.Peice7 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice7 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice7)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice8 = true;
			++E;
		}
		break;
	case 8:
		if (food.Peice8 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice8 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice8)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice9 = true;
			++E;
		}
		break;
	case 9:
		if (food.Peice9 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice9 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice9)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice10 = true;
			++E;
		}
		break;
	case 10:
		if (food.Peice10 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice10 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice10)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice11 = true;
			++E;
		}
		break;
	case 11:
		if (food.Peice11 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice11 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice11)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice12 = true;
			++E;
		}
		break;
	case 12:
		if (food.Peice12 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice12 = false;
			snake.size++;
			++E;
		}
		break;
	}
}

void EatPScore3()
{
	int x = food.x, y = food.y;
	switch (E)
	{
	case 1:
		if (food.Peice1 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice1 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice1)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice2 = true;
		}
		break;
	case 2:
		if (food.Peice2 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice2 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice2)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice3 = true;
		}
		break;
	case 3:
		if (food.Peice3 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
				food.Peice3 = false;
				snake.size++;
				++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice3)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice4 = true;
		}
		break;
	case 4:
		if (food.Peice4 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice4 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice4)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice5 = true;
		}
		break;
	case 5:
		if (food.Peice5 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice5 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice5)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice6 = true;
		}
		break;
	case 6:
		if (food.Peice6 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice6 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice6)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice7 = true;
		}
		break;
	case 7:
		if (food.Peice7 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
		    food.Peice7 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice7)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice8 = true;
		}
		break;
	case 8:
		if (food.Peice8 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice8 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice8)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice9 = true;
		}
		break;
	case 9:
		if (food.Peice9 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice9 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice9)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice10 = true;
		}
		break;
	case 10:
		if (food.Peice10 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice10 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice10)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice11 = true;
			++E;
		}
		break;
	case 11:
		if (food.Peice11 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice11 = false;
			snake.size++;
			++E;
		}
		//��Ƭˢ�£������
		if (!food.Peice11)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice12 = true;
		}
		break;
	case 12:
		if (food.Peice12 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice12 = false;
			snake.size++;
			++E;
		}
		break;
	}
}

void EatPScore4()
{
	switch (E)
	{
	case 1:
		if (food.Peice1 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice1 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice1)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice2 = true;
			++E;
		}
		break;
	case 2:
		if (food.Peice2 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice2 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice2)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.Peice3 = true;
			++E;
		}
		break;
	case 3:
		if (food.Peice3 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice3 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice3)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice4 = true;
			++E;
		}
		break;
	case 4:
		if (food.Peice4 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice4 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice4)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice5 = true;
			++E;
		}
		break;
	case 5:
		if (food.Peice5 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice5 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice5)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice6 = true;
			++E;
		}
		break;
	case 6:
		if (food.Peice6 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice6 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice6)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice7 = true;
			++E;
		}
		break;
	case 7:
		if (food.Peice7 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice7 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice7)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice8 = true;
			++E;
		}
		break;
	case 8:
		if (food.Peice8 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice8 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice8)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice9 = true;
			++E;
		}
		break;
	case 9:
		if (food.Peice9 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice9 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice9)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice10 = true;
			++E;
		}
		break;
	case 10:
		if (food.Peice10 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice10 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice10)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice11 = true;
			++E;
		}
		break;
	case 11:
		if (food.Peice11 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice11 = false;
			snake.size++;
		}
		//��Ƭˢ�£������
		if (!food.Peice11)
		{
			food.x = rand() % 790;
			food.y = rand() % 590;
			food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
			food.r = 5;
			food.Peice12 = true;
			++E;
		}
		break;
	case 12:
		if (food.Peice12 && snake.coor[0].x >= food.x && snake.coor[0].x <= food.x + 20 &&
			snake.coor[0].y >= food.y && snake.coor[0].y <= food.y + 20)
		{
			food.Peice12 = false;
			snake.size++;
			++E;
		}
		break;
	}
}

//�Ե���ʵ���߱��ٵ÷֣�ʳ��ˢ��
void EatFruitScore1()
{
	if (food.flag && snake.coor[0].x >= food.x - 2 - food.r && snake.coor[0].x <= food.x + 2 + food.r &&
		snake.coor[0].y >= food.y - 2 - food.r && snake.coor[0].y <= food.y + 2 + food.r)
	{
		e = rand() % 4;
		switch (e)
		{
		case 1:snake.size++;
			break;
		case 2:snake.speed = snake.speed - 1;
			break;
		case 3:snake.speed = snake.speed + 3;
			break;
		}
		food.flag = false;
	}
	//ʳ��ˢ�£������
	if (!food.flag)
	{
		food.x = rand() % 780;
		food.y = rand() % 580;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = 5;
		food.flag = true;
	}
}


//�Ե���ʵ����ټ��Ʋ��ж�
//void EatFoodQ()
//{
//
//}
//
//�Ե���ʵ����ټ��Ʋ��ж�
//void EatFoodS()
//{
//
//}
//
//���ٰ�������Ч��
//void SpeedQuicky()
//{
//
//}


//���ݳ�ʼ��(��ǽ)
void GameInitF1()
{
	//��ʼ��ͼ�δ���
	initgraph(800, 600);
	//�������������
	srand(GetTickCount());
	// ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//��ʼ��ʳ��
	food.x = rand() % 780;
	food.y = rand() % 580;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.flag = true;
}

//���ݳ�ʼ��
void GameInitF2()
{
	//��ʼ��ͼ�δ���
	initgraph(800, 600);
	//�������������
	srand(GetTickCount());
	// ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//��ʼ��ʳ��
	food.x = rand() % 790;
	food.y = rand() % 590;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.flag = true;
}

//���ݳ�ʼ��(�ؿ�1)
void GameInitP1()
{
	//��ʼ��ͼ�δ���
	initgraph(800, 600);
	//�������������
	srand(GetTickCount());
	// ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//��ʼ��ʳ��
	food.x = 730;
	food.y = 500;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.Peice1 = true;
}

//���ݳ�ʼ��(�ؿ�2)
void GameInitP2()
{
	//��ʼ��ͼ�δ���
	initgraph(800, 600);
	//�������������
	srand(GetTickCount());
	// ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//��ʼ��ʳ��
	food.x = 650;
	food.y = 450;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.Peice1 = true;
}

//���ݳ�ʼ��(�ؿ�3)
void GameInitP3()
{
	//��ʼ��ͼ�δ���
	initgraph(800, 600);
	//�������������
	srand(GetTickCount());
	// ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 430 - 10 * i;
		snake.coor[i].y = 300;
	}
	//��ʼ��ʳ��
	food.x = 650;
	food.y = 450;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.Peice1 = true;
}

//���ݳ�ʼ��(�ؿ�4)
void GameInitP4()
{
	//��ʼ��ͼ�δ���
	initgraph(800, 600);
	//�������������
	srand(GetTickCount());
	// ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 300 - 10 * i;
		snake.coor[i].y = 300;
	}
	//��ʼ��ʳ��
	food.x = 650;
	food.y = 450;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.Peice1 = true;
}

//���ƹ�ʵ���ߺ���Ϸ����(ģʽ1  ��ǽ)
void GameDrawF1()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./sx.jpg", wide, height);
	putimage(0, 0, &img);
	//��ӡǽ
	setfillcolor(RGB(140, 80, 120));
	solidrectangle(0, 0, 10, 600);
	solidrectangle(0, 0, 800, 10);
	solidrectangle(0, 590, 800, 600);
	solidrectangle(790, 0, 800, 600);
	//������ͷ
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, snake.speed / 2);
	}
	//��������
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, snake.speed / 2);
	}
	//����ʳ������
	if (food.flag)
	{
		setfillcolor(RGB(140, 80, 120));
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}

//�����ж�����ǽ��
bool snakedead1()
{
	if (snake.coor[0].x > 790 || snake.coor[0].x < 10 || snake.coor[0].y>590 || snake.coor[0].y < 10)
	{
		return false;
	}
	else
		return true;
	for (int i = 1; i < snake.size - 1; i++)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
		{
			return false;
		}
	}
}

//���ƹ�ʵ���ߺ���Ϸ����
void GameDrawF2()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./hwx.jpg", wide, height);
	putimage(0, 0, &img);
	//������ͷ
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//��������
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//����ʳ������
	if (food.flag)
	{
		setfillcolor(RGB(140, 80, 120));
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}

//�����ж�����ǽ��
bool snakedead2()
{
	for (int i = 1; i < snake.size - 1; i++)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
		{
			return false;
		}
		else
			return true;
	}
}


//������Ƭ���ߡ�����
void GameDrawP1()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./twx.jpg", wide, height);
	putimage(0, 0, &img);
	//������ͷ
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//��������
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//������Ƭ�������
	if (food.Peice1)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��3��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice2)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��3��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice3)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��3��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice4)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��3��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice5)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��2��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice6)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��2��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice7)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��2��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice8)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��2��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice9)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��1��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice10)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��1��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice11)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��1��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice12)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ˮ��1��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}

	EndBatchDraw();
}

void GameDrawP2()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./tx.jpg", wide, height);
	putimage(0, 0, &img);
	//������ͷ
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//��������
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//������Ƭ�������
	if (food.Peice1)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��3��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice2)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��3��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice3)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��3��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice4)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��3��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice5)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��2��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice6)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��2��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice7)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��2��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice8)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��2��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice9)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��1��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice10)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��1��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice11)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��1��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice12)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./ľ��1��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}

	EndBatchDraw();
}

void GameDrawP3()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./jx.jpg", wide, height);
	putimage(0, 0, &img);
	//������ͷ
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//��������
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//������Ƭ�������
	if (food.Peice1)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����3��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice2)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����3��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice3)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����3��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice4)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����3��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice5)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����2��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice6)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����2��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice7)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����2��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice8)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����2��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice9)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����1��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice10)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����1��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice11)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����1��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice12)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����1��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}

	EndBatchDraw();
}

void GameDrawP4()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./mx.jpg", wide, height);
	putimage(0, 0, &img);
	//������ͷ
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//��������
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//������Ƭ�������
	if (food.Peice1)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����3��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice2)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����3��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice3)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����3��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice4)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����3��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice5)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����2��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice6)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����2��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice7)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����2��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice8)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����2��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice9)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����1��Ƭ (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice10)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����1��Ƭ (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice11)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����1��Ƭ (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//������Ƭ�������
	if (food.Peice12)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./����1��Ƭ (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}

	EndBatchDraw();
}


//�Ե���Ƭ����Ƭˢ��
//void EatP()
//{
//
//}


//�ش̣����ơ��Ʋ���
void TrapS()
{
	//˫�����ͼ
	BeginBatchDraw();
	if (count <= 500)
	{
		circle(630, 540, 40);
		circle(630, 550, 40);
		circle(640, 540, 40);
		circle(640, 550, 40);
	}
	EndBatchDraw();
}


//�ƶ�ǽ�����ơ��ƶ����Ʋ�����
void TrapW11()
{
	if (t5 == 525)
	{
		A5++, B5++;
		if (A5 == 525)
		{
			t5 = 210;
		}
	}

	else if (t5 == 210)
	{
		A5--, B5--;
		if (A5 == 210)
		{
			t5 = 525;
		}
	}
}

void TrapW12()
{
	if (t6 == 465)
	{
		a6--, b6--;
		if (a6 == 465)
		{
			t6 = 715;
		}
	}
	else if (t6 == 715)
	{
		a6++, b6++;
		if (a6 == 715)
		{
			t6 = 465;
		}
	}
}

//�ƶ�ǽ�����ơ��ƶ����Ʋ�����
void TrapW21()
{
	if (T1 == 445)
	{
		Z--, G--;
		if (Z == 310)
		{
			T1 = 310;
		}
	}
	else if (T1 == 310)
	{
		Z++, G++;
		if (Z == 445)
		{
			T1 = 445;
		}
	}
}

void TrapW22()
{
	if (T2 == 400)
	{
		A--, B--;
		if (A == 100)
		{
			T2 = 100;
		}
	}
	else if (T2 == 100)
	{
		A++, B++;
		if (A == 330)
		{
			T2 = 400;
		}
	}
}

void TrapW23()
{
	if (T3 == 565)
	{
		c--, d--;
		if (c == 565)
		{
			T3 = 785;
		}
	}
	else if (T3 == 785)
	{
		c++, d++;
		if (c == 700)
		{
			T3 = 565;
		}
	}
}

//�ƶ�ǽ�����ơ��ƶ����Ʋ�����
void TrapW31()
{
	if (t1 == 280)
	{
		a1--, b1--;
		if (a1 == 200)
		{
			t1 = 520;
		}
	}
	else if (t1 == 520)
	{
		a1++, b1++;
		if (a1 == 520)
		{
			t1 = 280;
		}
	}
}

void TrapW32()
{

	if (t2 == 385)
	{
		a2--, b2--;
		if (a2 == 385)
		{
			t2 = 650;
		}
	}
	else if (t2 == 650)
	{
		a2++, b2++;
		if (a2 == 650)
		{
			t2 = 385;
		}
	}
}

void TrapW33()
{
	if (t3 == 10)
	{
		A3--, B3--;
		if (A3 == 10)
		{
			t3 = 250;
		}
	}
	else if (t3 == 250)
	{
		A3++, B3++;
		if (A3 == 250)
		{
			t3 = 10;
		}
	}

}

//�ƶ�ǽ�����ơ��ƶ����Ʋ�����
void TrapW41()
{
	if (t8 == 500)
	{
		A8--, B8--;
		if (A8 == 500)
		{
			t8 = 575;
		}
	}
	else if (t8 == 575)
	{
		A8++, B8++;
		if (A8 == 575)
		{
			t8 = 500;
		}
	}
}

void TrapW42()
{
	if (t9 == 75)
	{
		a9--, b9--;
		if (a9 == 75)
		{
			t9 = 695;
		}
	}
	else if (t9 == 695)
	{
		a9++, b9++;
		if (a9 == 695)
		{
			t9 = 75;
		}
	}
}


//������������ж����Ʋ���
void GetStar()
{

}

//����ģʽ���ؿ�1��
void DrawW1()
{
	BeginBatchDraw();
	setlinestyle(PS_SOLID, 5);
	setlinecolor(RED);
	line(a5, A5, b5, B5);//�ƶ���
	line(a6, A6, b6, B6);//�ƶ���
	line(0, 0, 800, 0);
	line(0, 0, 0, 600);
	line(0, 150, 100, 150);
	line(0, 300, 150, 300);
	line(0, 450, 100, 450);

	line(100, 0, 100, 75);
	line(100, 395, 100, 450);
	line(200, 525, 300, 525);
	line(300, 525, 300, 600);

	line(200, 100, 200, 125);
	line(200, 100, 300, 100);
	line(250, 0, 250, 125);
	line(225, 215, 515, 215);


	line(250, 290, 250, 375);
	line(100, 375, 250, 375);
	line(250, 375, 320, 375);
	line(300, 175, 300, 215);
	line(100, 375, 100, 450);
	line(405, 105, 615, 105);

	line(405, 105, 405, 135);
	line(565, 105, 565, 200);
	line(515, 175, 615, 175);
	line(515, 175, 515, 215);
	line(435, 215, 435, 275);
	line(435, 275, 515, 275);
	line(515, 275, 515, 375);
	line(405, 375, 515, 375);
	line(405, 375, 405, 600);
	line(450, 375, 515, 375);
	line(405, 500, 500, 500);
	line(500, 450, 500, 500);
	line(500, 450, 570, 450);
	line(515, 0, 515, 50);
	line(565, 125, 565, 200);
	line(615, 65, 615, 105);
	line(685, 100, 685, 155);
	line(680, 130, 730, 130);
	line(740, 200, 740, 235);
	line(715, 235, 735, 235);
	line(715, 235, 800, 235);
	line(600, 265, 600, 350);
	line(600, 350, 725, 350);
	line(675, 300, 675, 350);
	line(650, 350, 650, 385);
	line(725, 350, 725, 480);
	line(695, 420, 800, 420);

	line(595, 550, 630, 550);
	line(595, 550, 595, 600);
	line(800, 370, 800, 420);
	line(0, 600, 300, 600);
	line(405, 600, 800, 600);
	line(800, 0, 800, 250);
	line(800, 390, 800, 600);
	if (count <= 500)
	{
		circle(75, 300, 75);
		circle(75, 300, 50);
		circle(698, 600, 103);
		circle(698, 600, 80);
	}
	count = count - 5;
	if (count == 0)
	{
		count = 1000;
	}
	EndBatchDraw();
}

//����ģʽ���ؿ�2��
void DrawW2()
{
	//˫����
	BeginBatchDraw();
	setfillcolor(RGB(140, 80, 120));
	solidrectangle(z, Z, g, G);//�ƶ�ǽ
	solidrectangle(a, A, b, B);//�ƶ�ǽ
	solidrectangle(c, C, d, D);//�ƶ�ǽ
	solidrectangle(0, 0, 15, 600);
	solidrectangle(15, 0, 800, 15);
	solidrectangle(785, 15, 800, 600);
	solidrectangle(15, 585, 785, 800);
	solidrectangle(65, 15, 80, 110);
	solidrectangle(15, 210, 200, 225);
	solidrectangle(185, 225, 200, 310);
	solidrectangle(15, 430, 100, 445);
	solidrectangle(100, 395, 115, 510);
	solidrectangle(115, 495, 415, 510);
	solidrectangle(325, 400, 340, 495);
	solidrectangle(325, 15, 340, 110);
	solidrectangle(460, 60, 475, 400);
	solidrectangle(460, 400, 650, 415);
	solidrectangle(460, 85, 565, 100);
	solidrectangle(550, 100, 565, 315);
	solidrectangle(635, 415, 650, 495);
	solidrectangle(660, 15, 675, 125);
	if (count <= 500)
	{
		circle(630, 540, 40);
		circle(630, 550, 40);
		circle(640, 540, 40);
		circle(640, 550, 40);
	}
	count = count - 5;
	if (count == 0)
	{
		count = 1000;
	}
	EndBatchDraw();
}

//����ģʽ���ؿ�3��
void DrawW3()
{
	BeginBatchDraw();
	setfillcolor(RGB(255, 255, 255));
	solidrectangle(a1, A1, b1, B1);//�ƶ�ǽ
	solidrectangle(a2, A2, b2, B2);//�ƶ�ǽ
	solidrectangle(a3, A3, b3, B3);//�ƶ�ǽ
	solidrectangle(0, 0, 800, 10);
	solidrectangle(0, 10, 10, 590);
	solidrectangle(790, 10, 800, 590);
	solidrectangle(0, 590, 800, 600);
	solidrectangle(10, 60, 200, 70);
	solidrectangle(10, 250, 60, 260);
	solidrectangle(10, 460, 160, 470);
	solidrectangle(60, 520, 130, 530);
	solidrectangle(110, 140, 270, 150);
	solidrectangle(70, 250, 250, 260);
	solidrectangle(140, 340, 290, 350);
	solidrectangle(280, 170, 470, 180);
	solidrectangle(280, 300, 370, 310);
	solidrectangle(330, 450, 470, 460);
	solidrectangle(250, 520, 440, 530);
	solidrectangle(440, 100, 520, 110);
	solidrectangle(370, 250, 680, 260);
	solidrectangle(530, 340, 600, 350);
	solidrectangle(480, 400, 590, 410);
	solidrectangle(530, 100, 650, 110);
	solidrectangle(590, 50, 700, 60);
	solidrectangle(590, 160, 790, 170);
	solidrectangle(620, 460, 770, 470);
	solidrectangle(530, 520, 740, 530);
	solidrectangle(740, 310, 790, 320);
	solidrectangle(60, 200, 70, 320);
	solidrectangle(130, 310, 140, 410);
	solidrectangle(60, 530, 70, 590);
	solidrectangle(130, 310, 140, 410);
	solidrectangle(200, 410, 210, 590);
	solidrectangle(270, 70, 280, 210);
	solidrectangle(270, 350, 280, 520);
	solidrectangle(370, 10, 380, 70);
	solidrectangle(370, 180, 380, 400);
	solidrectangle(430, 95, 440, 170);
	solidrectangle(520, 70, 530, 160);
	solidrectangle(520, 410, 530, 560);
	solidrectangle(560, 260, 570, 345);
	solidrectangle(650, 70, 660, 170);
	solidrectangle(650, 300, 660, 470);
	solidrectangle(740, 70, 750, 160);
	if (count <= 500)
	{
		circle(200, 200, 40);
		circle(200, 200, 30);
		circle(200, 200, 20);
		circle(200, 200, 10);
	}
	count = count - 5;
	if (count == 0)
	{
		count = 1000;
	}
	EndBatchDraw();
}

//����ģʽ���ؿ�4��
void DrawW4()
{
	BeginBatchDraw();
	setlinestyle(PS_SOLID, 5);
	setlinecolor(RED);
	line(a9, A9, b9, B9);//�ƶ�ǽ
	line(a8, A8, b8, B8);//�ƶ�ǽ

	line(75, 0, 75, 100);
	line(0, 0, 800, 0);
	line(0, 150, 100, 150);
	line(0, 600, 800, 600);
	line(50, 100, 100, 100);
	line(0, 0, 0, 150);
	line(0, 150, 0, 450);
	line(0, 450, 0, 600);//��300�ĳ���450
	line(0, 450, 75, 450);
	line(0, 300, 25, 300);
	line(95, 300, 125, 300);
	line(150, 450, 300, 450);
	line(75, 520, 375, 520);
	line(325, 0, 325, 400);
	line(375, 400, 375, 550);
	line(400, 75, 400, 250);
	line(400, 250, 450, 250);
	line(450, 250, 450, 500);
	line(450, 575, 450, 600);
	line(600, 55, 600, 350);
	line(600, 450, 600, 600);
	line(600, 125, 650, 125);
	line(650, 0, 650, 125);
	line(700, 300, 720, 300);
	line(700, 300, 700, 500);
	line(700, 575, 700, 600);
	line(775, 25, 800, 25);
	line(775, 25, 775, 95);
	line(775, 95, 800, 95);
	line(775, 225, 800, 225);
	line(775, 225, 775, 350);
	line(745, 350, 775, 350);
	line(745, 350, 745, 450);
	line(800, 0, 800, 25);
	line(800, 25, 800, 350);//225�ĳ���25
	line(800, 350, 800, 600);
	line(325, 400, 375, 400);
	line(250, 0, 250, 125);
	line(175, 125, 250, 125);
	line(175, 125, 175, 250);
	line(175, 250, 250, 250);
	line(250, 250, 250, 350);
	line(450, 125, 550, 125);
	line(450, 125, 450, 165);
	line(450, 165, 550, 165);
	line(550, 125, 550, 165);
	line(800, 25, 800, 95);
	line(775, 350, 800, 350);
	EndBatchDraw();
}


//��ҳ�����ӡ�����������ҳ����ж������룺����ĵ�����ꣻ�������
int gamebegin(int x, int y, int w, int h)
{

	initgraph(800, 600, EW_SHOWCONSOLE);
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./bjt.jpg", wide, height);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	setfillcolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	/*BGM();*/
	BeginBatchDraw();

	for (int i = 1; i < 5; i++)
	{
		fillroundrect(x, y * i, x + w, y * i + h, 10, 10);
	}
	EndBatchDraw();

	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "����");

	strcpy(p, "����");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 1) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "��ʼ��Ϸ");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "��Ϸ����");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 3) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "�˳���Ϸ");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 4) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	/*BGM();*/

	ExMessage msg;
	while (1) {
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 1, x + w, y * 1 + h, 10, 10);
					strcpy(p, "����");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 1) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 1, x + w, y * 1 + h, 10, 10);
					strcpy(p, "����");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 1) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n01 = 1;
					printf("1");
					return n01;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 2 && msg.y <= (y * 2) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "��ʼ��Ϸ");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "��ʼ��Ϸ");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n01 = 2;
					printf("2");
					return n01;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 3 && msg.y <= (y * 3) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "��Ϸ����");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "��Ϸ����");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n01 = 3;
					printf("3");
					return n01;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 4 && msg.y <= (y * 4) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 4, x + w, y * 4 + h, 10, 10);
					strcpy(p, "�˳���Ϸ");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 4) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 4, x + w, y * 4 + h, 10, 10);
					strcpy(p, "�˳���Ϸ");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 4) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n01 = 4;
					printf("4");
					return n01;
				}
			default:
				break;
			}
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

//��������ҳ����ж������룺���Խ�����ҳ��ĵ�����ꣻ�������
int gameset(int x, int y, int w, int h)
{
	POINT pts[] = { {0,20} ,{35,0}, {35,40} };
	initgraph(800, 600, EW_SHOWCONSOLE);
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./mwx.jpg", wide, height);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	setfillcolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	BeginBatchDraw();
	fillpolygon(pts, 3);
	for (int i = 1; i < 5; i++)
	{
		fillroundrect(x, y * i, x + w, y * i + h, 10, 10);
	}
	EndBatchDraw();

	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "����");

	strcpy(p, "��Ч");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 1) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "��������");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "�ٶ�");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 3) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "Ƥ��");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 4) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	ExMessage msg;

	while (1) {
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 1, x + w, y * 1 + h, 10, 10);
					strcpy(p, "��Ч");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 1) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 1, x + w, y * 1 + h, 10, 10);
					strcpy(p, "��Ч");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 1) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n02 = 1;
					printf("1");
					return n02;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 2 && msg.y <= (y * 2) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "��������");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "��������");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n02 = 2;
					printf("2");
					return n02;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 3 && msg.y <= (y * 3) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "�ٶ�");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "�ٶ�");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n02 = 3;
					printf("3");
					return n02;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 4 && msg.y <= (y * 4) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 4, x + w, y * 4 + h, 10, 10);
					strcpy(p, "Ƥ��");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 4) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 4, x + w, y * 4 + h, 10, 10);
					strcpy(p, "Ƥ��");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 4) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n02 = 4;
					printf("4");
					return n02;
				}
				if (msg.x >= 0 && msg.x <= 35 && msg.y >= 0 && msg.y <= 40)
				{
					setlinecolor(RED);
					fillpolygon(pts, 3);
					Sleep(100);
					setlinecolor(WHITE);
					fillpolygon(pts, 3);
					n02 = 5;
					printf("5");
					return n02;
				}
			default:
				break;
			}
		}
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

//��Ϸ����ҳ�棬��ӡ��Ϸ�������룺�ޣ��������
int gamerule()
{
	POINT pts[] = { {0,20} ,{35,0}, {35,40} };
	initgraph(800, 600, EW_SHOWCONSOLE);
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./hx.jpg", wide, height);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	setfillcolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	fillpolygon(pts, 3);
	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(18, 0, "����");

	strcpy(p, "����ģʽһ���б䳤����ٹ�ʵ������ģʽ����ֻ�б䳤��������ģʽ��ͨ������Ϊ������Ƭ��");
	int kx = (800 - textwidth(p)) / 2;
	int ky = (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);
	ExMessage msg;
	while (1) {
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:

				if (msg.x >= 0 && msg.x <= 35 && msg.y >= 0 && msg.y <= 40)
				{
					setlinecolor(RED);
					fillpolygon(pts, 3);
					Sleep(100);
					setlinecolor(WHITE);
					fillpolygon(pts, 3);
					n02 = 5;
					printf("5");
					return n02;
				}
			default:
				break;
			}
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

//�˳�����
int gamebyebye01()
{
	initgraph(800, 600);
	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "����");

	strcpy(p, "��Ϸ�˳�");
	int kx = (800 - textwidth(p)) / 2;
	int ky = (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "�������Ͻǰ���");
	kx = (800 - textwidth(p)) / 2;
	ky = textheight(p) + (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "3����Զ��˳�");
	kx = (800 - textwidth(p)) / 2;
	ky = textheight(p) * 2 + (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);
	Sleep(1000);

	strcpy(p, "2����Զ��˳�");
	kx = (800 - textwidth(p)) / 2;
	ky = textheight(p) * 2 + (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);
	Sleep(1000);

	strcpy(p, "1����Զ��˳�");
	kx = (800 - textwidth(p)) / 2;
	ky = textheight(p) * 2 + (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);


	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	return 0;
}

//�˳�����
int gamebyebye02()
{
	initgraph(800, 600, EW_NOCLOSE);

	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "����");

	strcpy(p, "��Ϸ�˳�");
	int kx1 = (800 - textwidth(p)) / 2;
	int ky1 = (600 - textheight(p)) / 2;
	outtextxy(kx1, ky1, p);

	strcpy(p, "��������");
	int kx2 = (800 - textwidth(p)) / 2;
	int ky2 = textheight(p) + (600 - textheight(p)) / 2;
	outtextxy(kx2, ky2, p);

	int kx3 = (800 - textwidth(p)) / 2;
	int ky3 = textheight(p) * 2 + (600 - textheight(p)) / 2;

	int kx4 = (800 - textwidth(p)) / 2;
	int ky4 = textheight(p) * 3 + (600 - textheight(p)) / 2;

	int kx5 = (800 - textwidth(p)) / 2;
	int ky5 = textheight(p) * 4 + (600 - textheight(p)) / 2;

	ExMessage msg;

	while (1) {
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if ((msg.x >= kx1 && msg.x <= kx1 + textwidth("��Ϸ�˳�") && msg.y >= ky1 && msg.y <= ky2 + textheight("��Ϸ�˳�"))
					|| (msg.x >= kx2 && msg.x <= kx2 + textwidth("��������") && msg.y >= ky2 && msg.y <= ky2 + textheight("��������")))
				{
					strcpy(p, "����û�����ˡ�����");
					outtextxy(kx3, ky3, p);
				}
				if (/*(msg.x >= kx1 && msg.x <= kx1 + textwidth("��Ϸ�˳�") && msg.y >= ky1 && msg.y <= ky2 + textheight("��Ϸ�˳�"))
					| (msg.x >= kx2 && msg.x <= kx2 + textwidth("�������Ͻǰ���") && msg.y >= ky2 && msg.y <= ky2 + textheight("�������Ͻǰ���"))
					|*/(msg.x >= kx3 && msg.x <= kx3 + textwidth("����û�����ˡ�����") && msg.y >= ky3 && msg.y <= ky3 + textheight("����û�����ˡ�����")))
				{
					strcpy(p, "��û������");
					outtextxy(kx4, ky4, p);
				}
				if (msg.x >= kx4 && msg.x <= kx4 + textwidth("��û������") && msg.y >= ky4 && msg.y <= ky4 + textheight("��û������"))
				{
					strcpy(p, "������һ����");
					outtextxy(kx5, ky5, p);
				}
				if (msg.x >= kx5 && msg.x <= kx5 + textwidth("������һ����") && msg.y >= ky5 && msg.y <= ky5 + textheight("������һ����"))
				{
					return n03 = 1;
				}
				//case msg.x>=:
			default:
				break;
			}
		}
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	return 0;
}

//��Ϸģʽѡ��ҳ�档���룺���ꣻ�������
int gameplay(int x, int y, int w, int h)
{
	POINT pts[] = { {0,20} ,{35,0}, {35,40} };
	initgraph(800, 600, EW_SHOWCONSOLE);
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./ty.jpg", wide, height);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	setfillcolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	BeginBatchDraw();
	fillpolygon(pts, 3);
	for (int i = 2; i < 4; i++)
	{
		fillroundrect(x, y * i, x + w, y * i + h, 10, 10);
	}
	EndBatchDraw();

	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "����");

	strcpy(p, "����ģʽ");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "����ģʽ");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 3) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	ExMessage msg;

	while (1) {
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 2 && msg.y <= (y * 2) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "����ģʽ");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "����ģʽ");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n03 = 1;
					printf("1");
					return n03;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 3 && msg.y <= (y * 3) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "����ģʽ");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					strcpy(p, "����ģʽ");
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					n03 = 2;
					printf("2");
					return n03;
				}
				if (msg.x >= 0 && msg.x <= 35 && msg.y >= 0 && msg.y <= 40)
				{
					setlinecolor(RED);
					fillpolygon(pts, 3);
					Sleep(100);
					setlinecolor(WHITE);
					fillpolygon(pts, 3);
					n02 = 5;
					printf("5");
					return n02;
				}
			default:
				break;
			}
		}
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}


int gamefree(int x, int y, int w, int h)
{
	POINT pts[] = { {0,20} ,{35,0}, {35,40} };
	initgraph(800, 600, EW_SHOWCONSOLE);
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./sx.jpg", wide, height);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	setfillcolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	BeginBatchDraw();
	fillpolygon(pts, 3);
	for (int i = 2; i < 4; i++)
	{
		fillroundrect(x, y * i, x + w, y * i + h, 10, 10);
	}
	EndBatchDraw();

	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "����");

	strcpy(p, "�н�");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "�޽�");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 3) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	ExMessage msg;

	while (1) {
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 2 && msg.y <= (y * 2) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "�н�");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					GameInitF1();
					while (1)
					{
						snakeMove();
						keyControl();
						EatFruitScore1();
						GameDrawF1();
						if (!snakedead1())
						{
							break;
						}
						Sleep(80);
					}
					setlinecolor(WHITE);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "game over");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(800);
					gamebyebye02();
					n04 = 1;
					printf("1");
					return n04;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 3 && msg.y <= (y * 3) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "�޽�");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					GameInitF2();
					while (1)
					{
						snakeMove();
						keyControl();
						EatFruitScore2();
						GameDrawF2();
						if (!snakedead2())
						{
							break;
						}
						Sleep(80);
					}
					setlinecolor(WHITE);
					strcpy(p, "game over");
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(800);
					gamebyebye02();
					n04 = 2;
					printf("2");
					return n04;
				}
				if (msg.x >= 0 && msg.x <= 35 && msg.y >= 0 && msg.y <= 40)
				{
					setlinecolor(RED);
					fillpolygon(pts, 3);
					Sleep(100);
					setlinecolor(WHITE);
					fillpolygon(pts, 3);
					n01 = 2;
					printf("5");
					return n01;
				}
			default:
				break;
			}
		}
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

}

int gamebreak(int x, int y, int w, int h)
{
	POINT pts[] = { {0,20} ,{35,0}, {35,40} };
	initgraph(800, 600, EW_SHOWCONSOLE);
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./hwx.jpg", wide, height);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	setfillcolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	BeginBatchDraw();
	fillpolygon(pts, 3);
	for (int i = 1; i < 5; i++)
	{
		fillroundrect(x, y * i, x + w, y * i + h, 10, 10);
	}
	EndBatchDraw();

	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "����");

	strcpy(p, "�ؿ�1");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 1) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "�ؿ�2");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "�ؿ�3");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 3) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "δ�����");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 4) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	ExMessage msg;
	while (1) {
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 1, x + w, y * 1 + h, 10, 10);
					strcpy(p, "�ؿ�1");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 1) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					GameInitP1();
					while (1)
					{
						snakeMove();
						keyControl();
						GameDrawP1();
						EatPScore1();
						DrawW1();
						TrapW11();
						TrapW12();
						if (!snakeDead1())
						{
							break;
						}
						if (E == 13)
						{
							break;
						}
						Sleep(80);

					}
					food.Peice1 = true;
					food.Peice2 = true;
					food.Peice3 = true;
					food.Peice4 = true;
					food.Peice5 = true;
					food.Peice6 = true;
					food.Peice7 = true;
					food.Peice8 = true;
					food.Peice9 = true;
					food.Peice10 = true;
					food.Peice11 = true;
					food.Peice12 = true;
					E = 1;
					setlinecolor(WHITE);
					fillroundrect(x, y * 1, x + w, y * 1 + h, 10, 10);
					strcpy(p, "game over");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 1) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(800);
					gamebreak(320, 120, 140, 60);
					n05 = 1;
					printf("1");
					return n05;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 2 && msg.y <= (y * 2) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "�ؿ�2");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					GameInitP1();
					while (1)
					{
						snakeMove();
						keyControl();
						GameDrawP2();
						EatPScore2();
						DrawW2();
						TrapW21();
						TrapW22();
						TrapW23();
						if (!snakeDead2())
						{
							break;
						}
						if (E == 13)
						{
							break;
						}
						Sleep(80);

					}
					food.Peice1 = true;
					food.Peice2 = true;
					food.Peice3 = true;
					food.Peice4 = true;
					food.Peice5 = true;
					food.Peice6 = true;
					food.Peice7 = true;
					food.Peice8 = true;
					food.Peice9 = true;
					food.Peice10 = true;
					food.Peice11 = true;
					food.Peice12 = true;
					E = 1;
					setlinecolor(WHITE);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "game over");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(800);
					gamebreak(320, 120, 140, 60);
					n05 = 2;
					printf("2");
					return n05;
				}
				if (msg.x >= x && msg.x <= x + w && msg.y >= y * 3 && msg.y <= (y * 3) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "�ؿ�3");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					GameInitP1();
					while (1)
					{
						snakeMove();
						keyControl();
						GameDrawP3();
						EatPScore3();
						DrawW3();
						TrapW31();
						TrapW32();
						TrapW33();
						if (!snakeDead3())
						{
							break;
						}
						if (E == 13)
						{
							break;
						}
						Sleep(80);

					}
					food.Peice1 = true;
					food.Peice2 = true;
					food.Peice3 = true;
					food.Peice4 = true;
					food.Peice5 = true;
					food.Peice6 = true;
					food.Peice7 = true;
					food.Peice8 = true;
					food.Peice9 = true;
					food.Peice10 = true;
					food.Peice11 = true;
					food.Peice12 = true;
					E = 1;
					setlinecolor(WHITE);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "game over");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(800);
					gamebreak(320, 120, 140, 60);
					n05 = 3;
					printf("3");
					return n05;
				}
				/*if (msg.x >= x && msg.x <= x + w && msg.y >= y * 4 && msg.y <= (y * 4) + h)
				{
					setlinecolor(RED);
					fillroundrect(x, y * 4, x + w, y * 4 + h, 10, 10);
					strcpy(p, "�ؿ�4");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 4) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					GameInitP1();
					while (1)
					{
						snakeMove();
						keyControl();
						GameDrawP4();
						EatPScore4();
						DrawW4();
						TrapW41();
						TrapW42();
						if (!snakeDead4())
						{
							break;
						}
						if (E == 13)
						{
							break;
						}
						Sleep(80);

					}
					food.Peice1 = true;
					food.Peice2 = true;
					food.Peice3 = true;
					food.Peice4 = true;
					food.Peice5 = true;
					food.Peice6 = true;
					food.Peice7 = true;
					food.Peice8 = true;
					food.Peice9 = true;
					food.Peice10 = true;
					food.Peice11 = true;
					food.Peice12 = true;
					E = 1;
					setlinecolor(WHITE);
					fillroundrect(x, y * 4, x + w, y * 4 + h, 10, 10);
					strcpy(p, "game over");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 4) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					gamebreak(320, 120, 140, 60);
					n05 = 4;
					printf("4");
					return n05;
				}*/
				if (msg.x >= 0 && msg.x <= 35 && msg.y >= 0 && msg.y <= 40)
				{
					setlinecolor(RED);
					fillpolygon(pts, 3);
					Sleep(100);
					setlinecolor(WHITE);
					fillpolygon(pts, 3);
					n01 = 2;
					printf("5");
					return n01;
				}
			default:
				break;
			}
		}
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

}



//����Ϸ������С�����룺���ռ���������ĸ�ı���  �������
void gamesound(char)
{

}

//���ó�ʼ�������֣�������Ϸ�ı������֡����룺��Ļ�ϵ������  �������
void gamemusic(int, int)
{

}

//���ߵ��ٶȡ��������ɻ򴳹�ģʽ���档���룺���ռ���������ĸ�ı��� �������  �������
void snakespeed(char, int, int)
{

}

//������Ƥ���޸ĺ���Ϸ�����޸����ġ����룺������  �������
void gamecover(int, int)
{

}

//��Ƥ���޸ġ����룺������  �������
void snakecover(int, int)
{

}

//��Ϸ�����޸ġ����룻������  �������
void background(int, int)
{

}

//�˳���Ϸ����
void gamebyebye()
{

}