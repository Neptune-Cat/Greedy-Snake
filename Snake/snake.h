#pragma once
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>  //多媒体设备接口
#pragma comment(lib,"winmm.lib")  //加载静态库
#include<conio.h>  //控制台输入输出头文件
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

int n01 = 0;//首页的返回值，判断进入设置等页面
int n02 = 0;//设置的返回值，判断进入音效等页面
int n03 = 0;//开始游戏的返回值判断进入何种游戏模式
int n04 = 0;//自由模式选择有界无界参数
int n05 = 0;//闯关模式选择关卡参数

#define SNAKE_NUM 400000  //蛇的最大节数

int a = 325, A = 200, b = 340, B = 275;//墙体坐标，引入全局变量；
int z = 180, Z = 445, g = 195, G = 495;//墙体坐标，引入全局变量；
int c = 700, C = 260, d = 785, D = 275;//墙体坐标，引入全局变量；
int count = 1000;
int T1 = 445;//引入全局变量T1，实现方向改变
int T2 = 400;//引入全局变量T2，实现方向改变
int T3 = 565;//引入全局变量T3，实现方向改变
int e = 0;  //果实随机数
int E = 1; //碎片
int a5 = 250, A5 = 290, b5 = 250, B5 = 372;//关卡1移动墙
int a6 = 715, A6 = 235, b6 = 800, B6 = 235;
int t5 = 210;
int t6 = 465;
//关卡移3动墙
int a1 = 330, A1 = 450, b1 = 470, B1 = 460;
int a2 = 530, A2 = 340, b2 = 600, B2 = 350;
int a3 = 520, A3 = 70, b3 = 530, B3 = 160;
int t3 = 10;
int t2 = 385;
int t1 = 280;
//关卡4移动墙
int a8 = 450, A8 = 575, b8 = 450, B8 = 600;
int a9 = 150, A9 = 450, b9 = 300, B9 = 450;
int t8 = 500;
int t9 = 75;

//蛇的方向
enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

//蛇的结构
struct Snake
{
	int size;  //蛇的节数
	int dir;  //方向
	int speed;  //速度
	POINT coor[SNAKE_NUM];  //坐标
}snake;

//移动蛇
void snakeMove()
{
	//联动
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];
	}
	//移动改变
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

//通过按键改变蛇的移动方向
void keyControl()
{
	//判断有没有按键,如果按键则返回true
	if (_kbhit())
	{
		//72 80 75 77 上下左右
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
			//游戏暂停
		case 'p':
		case 'P':
			system("pause>nu1");
			break;
		}
	}
}


//蛇的死亡判定      返回值为真
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

//蛇的死亡判定      返回值为真
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

//蛇的死亡判定      返回值为真
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

////蛇的死亡判定      返回值为真
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


//食物结构
struct Food
{
	int x;
	int y;
	int r;  //果实的大小
	bool flag;  //果实是否被吃
	bool Peice1;  //碎片是否被吃
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
	DWORD color;  //食物颜色
}food;

//吃到果实后蛇得分，果实刷新（模式2)
void EatFruitScore2()
{
	if (food.flag && snake.coor[0].x >= food.x - 2 - food.r && snake.coor[0].x <= food.x + 2 + food.r &&
		snake.coor[0].y >= food.y - 2 - food.r && snake.coor[0].y <= food.y + 2 + food.r)
	{
		food.flag = false;
		snake.size++;
	}
	//果实刷新（随机）
	if (!food.flag)
	{
		food.x = rand() % 790;
		food.y = rand() % 590;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = 5;
		food.flag = true;
	}
}

//吃到碎片后蛇得分，碎片刷新（关卡1、2、3、4)
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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
		//碎片刷新（随机）
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

//吃到果实后蛇变速得分，食物刷新
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
	//食物刷新（随机）
	if (!food.flag)
	{
		food.x = rand() % 780;
		food.y = rand() % 580;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = 5;
		food.flag = true;
	}
}


//吃到果实后加速及计步判定
//void EatFoodQ()
//{
//
//}
//
//吃到果实后减速及计步判定
//void EatFoodS()
//{
//
//}
//
//加速按键及其效果
//void SpeedQuicky()
//{
//
//}


//数据初始化(有墙)
void GameInitF1()
{
	//初始化图形窗口
	initgraph(800, 600);
	//设置随机数种子
	srand(GetTickCount());
	// 初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//初始化食物
	food.x = rand() % 780;
	food.y = rand() % 580;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.flag = true;
}

//数据初始化
void GameInitF2()
{
	//初始化图形窗口
	initgraph(800, 600);
	//设置随机数种子
	srand(GetTickCount());
	// 初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//初始化食物
	food.x = rand() % 790;
	food.y = rand() % 590;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.flag = true;
}

//数据初始化(关卡1)
void GameInitP1()
{
	//初始化图形窗口
	initgraph(800, 600);
	//设置随机数种子
	srand(GetTickCount());
	// 初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//初始化食物
	food.x = 730;
	food.y = 500;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.Peice1 = true;
}

//数据初始化(关卡2)
void GameInitP2()
{
	//初始化图形窗口
	initgraph(800, 600);
	//设置随机数种子
	srand(GetTickCount());
	// 初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//初始化食物
	food.x = 650;
	food.y = 450;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.Peice1 = true;
}

//数据初始化(关卡3)
void GameInitP3()
{
	//初始化图形窗口
	initgraph(800, 600);
	//设置随机数种子
	srand(GetTickCount());
	// 初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 430 - 10 * i;
		snake.coor[i].y = 300;
	}
	//初始化食物
	food.x = 650;
	food.y = 450;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.Peice1 = true;
}

//数据初始化(关卡4)
void GameInitP4()
{
	//初始化图形窗口
	initgraph(800, 600);
	//设置随机数种子
	srand(GetTickCount());
	// 初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 300 - 10 * i;
		snake.coor[i].y = 300;
	}
	//初始化食物
	food.x = 650;
	food.y = 450;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.Peice1 = true;
}

//绘制果实、蛇和游戏背景(模式1  有墙)
void GameDrawF1()
{
	//双缓冲绘图
	BeginBatchDraw();
	//绘制背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./sx.jpg", wide, height);
	putimage(0, 0, &img);
	//打印墙
	setfillcolor(RGB(140, 80, 120));
	solidrectangle(0, 0, 10, 600);
	solidrectangle(0, 0, 800, 10);
	solidrectangle(0, 590, 800, 600);
	solidrectangle(790, 0, 800, 600);
	//绘制蛇头
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, snake.speed / 2);
	}
	//绘制蛇身
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, snake.speed / 2);
	}
	//绘制食物（随机）
	if (food.flag)
	{
		setfillcolor(RGB(140, 80, 120));
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}

//死亡判定（有墙）
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

//绘制果实、蛇和游戏背景
void GameDrawF2()
{
	//双缓冲绘图
	BeginBatchDraw();
	//绘制背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./hwx.jpg", wide, height);
	putimage(0, 0, &img);
	//绘制蛇头
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制蛇身
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制食物（随机）
	if (food.flag)
	{
		setfillcolor(RGB(140, 80, 120));
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}

//死亡判定（无墙）
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


//绘制碎片、蛇、背景
void GameDrawP1()
{
	//双缓冲绘图
	BeginBatchDraw();
	//绘制背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./twx.jpg", wide, height);
	putimage(0, 0, &img);
	//绘制蛇头
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制蛇身
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制碎片（随机）
	if (food.Peice1)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星3碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice2)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星3碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice3)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星3碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice4)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星3碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice5)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星2碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice6)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星2碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice7)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星2碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice8)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星2碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice9)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星1碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice10)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星1碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice11)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星1碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice12)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./水星1碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}

	EndBatchDraw();
}

void GameDrawP2()
{
	//双缓冲绘图
	BeginBatchDraw();
	//绘制背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./tx.jpg", wide, height);
	putimage(0, 0, &img);
	//绘制蛇头
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制蛇身
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制碎片（随机）
	if (food.Peice1)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星3碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice2)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星3碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice3)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星3碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice4)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星3碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice5)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星2碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice6)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星2碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice7)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星2碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice8)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星2碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice9)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星1碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice10)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星1碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice11)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星1碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice12)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./木星1碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}

	EndBatchDraw();
}

void GameDrawP3()
{
	//双缓冲绘图
	BeginBatchDraw();
	//绘制背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./jx.jpg", wide, height);
	putimage(0, 0, &img);
	//绘制蛇头
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制蛇身
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制碎片（随机）
	if (food.Peice1)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星3碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice2)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星3碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice3)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星3碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice4)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星3碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice5)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星2碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice6)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星2碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice7)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星2碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice8)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星2碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice9)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星1碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice10)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星1碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice11)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星1碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice12)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./金星1碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}

	EndBatchDraw();
}

void GameDrawP4()
{
	//双缓冲绘图
	BeginBatchDraw();
	//绘制背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./mx.jpg", wide, height);
	putimage(0, 0, &img);
	//绘制蛇头
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制蛇身
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制碎片（随机）
	if (food.Peice1)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星3碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice2)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星3碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice3)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星3碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice4)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星3碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice5)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星2碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice6)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星2碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice7)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星2碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice8)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星2碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice9)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星1碎片 (1).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice10)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星1碎片 (2).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice11)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星1碎片 (3).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}
	//绘制碎片（随机）
	if (food.Peice12)
	{
		IMAGE img;
		int wide = 20, height = 20;
		loadimage(&img, "./火星1碎片 (4).jpg", wide, height);
		putimage(food.x, food.y, &img);
	}

	EndBatchDraw();
}


//吃到碎片，碎片刷新
//void EatP()
//{
//
//}


//地刺（绘制、计步）
void TrapS()
{
	//双缓冲绘图
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


//移动墙（绘制、移动、计步？）
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

//移动墙（绘制、移动、计步？）
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

//移动墙（绘制、移动、计步？）
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

//移动墙（绘制、移动、计步？）
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


//获得星星数量判定（计步）
void GetStar()
{

}

//闯关模式（关卡1）
void DrawW1()
{
	BeginBatchDraw();
	setlinestyle(PS_SOLID, 5);
	setlinecolor(RED);
	line(a5, A5, b5, B5);//移动线
	line(a6, A6, b6, B6);//移动线
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

//闯关模式（关卡2）
void DrawW2()
{
	//双缓冲
	BeginBatchDraw();
	setfillcolor(RGB(140, 80, 120));
	solidrectangle(z, Z, g, G);//移动墙
	solidrectangle(a, A, b, B);//移动墙
	solidrectangle(c, C, d, D);//移动墙
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

//闯关模式（关卡3）
void DrawW3()
{
	BeginBatchDraw();
	setfillcolor(RGB(255, 255, 255));
	solidrectangle(a1, A1, b1, B1);//移动墙
	solidrectangle(a2, A2, b2, B2);//移动墙
	solidrectangle(a3, A3, b3, B3);//移动墙
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

//闯关模式（关卡4）
void DrawW4()
{
	BeginBatchDraw();
	setlinestyle(PS_SOLID, 5);
	setlinecolor(RED);
	line(a9, A9, b9, B9);//移动墙
	line(a8, A8, b8, B8);//移动墙

	line(75, 0, 75, 100);
	line(0, 0, 800, 0);
	line(0, 150, 100, 150);
	line(0, 600, 800, 600);
	line(50, 100, 100, 100);
	line(0, 0, 0, 150);
	line(0, 150, 0, 450);
	line(0, 450, 0, 600);//把300改成了450
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
	line(800, 25, 800, 350);//225改成了25
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


//首页界面打印，所进入的子页面的判定。输入：定义的点的坐标；输出：无
int gamebegin(int x, int y, int w, int h)
{

	initgraph(800, 600, EW_SHOWCONSOLE);
	//绘制背景
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
	settextstyle(30, 0, "黑体");

	strcpy(p, "设置");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 1) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "开始游戏");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "游戏规则");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 3) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "退出游戏");
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
					strcpy(p, "设置");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 1) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 1, x + w, y * 1 + h, 10, 10);
					strcpy(p, "设置");
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
					strcpy(p, "开始游戏");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "开始游戏");
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
					strcpy(p, "游戏规则");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "游戏规则");
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
					strcpy(p, "退出游戏");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 4) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 4, x + w, y * 4 + h, 10, 10);
					strcpy(p, "退出游戏");
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

//所进入子页面的判定。输入：借以进入子页面的点的坐标；输出：无
int gameset(int x, int y, int w, int h)
{
	POINT pts[] = { {0,20} ,{35,0}, {35,40} };
	initgraph(800, 600, EW_SHOWCONSOLE);
	//绘制背景
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
	settextstyle(30, 0, "黑体");

	strcpy(p, "音效");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 1) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "背景音乐");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "速度");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 3) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "皮肤");
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
					strcpy(p, "音效");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 1) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 1, x + w, y * 1 + h, 10, 10);
					strcpy(p, "音效");
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
					strcpy(p, "背景音乐");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "背景音乐");
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
					strcpy(p, "速度");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 3, x + w, y * 3 + h, 10, 10);
					strcpy(p, "速度");
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
					strcpy(p, "皮肤");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 4) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 4, x + w, y * 4 + h, 10, 10);
					strcpy(p, "皮肤");
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

//游戏规则页面，打印游戏规则。输入：无；输出：无
int gamerule()
{
	POINT pts[] = { {0,20} ,{35,0}, {35,40} };
	initgraph(800, 600, EW_SHOWCONSOLE);
	//绘制背景
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
	settextstyle(18, 0, "黑体");

	strcpy(p, "自由模式一：有变长或变速果实。自由模式二：只有变长果。闯关模式：通关条件为集满碎片。");
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

//退出操作
int gamebyebye01()
{
	initgraph(800, 600);
	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "黑体");

	strcpy(p, "游戏退出");
	int kx = (800 - textwidth(p)) / 2;
	int ky = (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "请点击右上角按键");
	kx = (800 - textwidth(p)) / 2;
	ky = textheight(p) + (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "3秒后自动退出");
	kx = (800 - textwidth(p)) / 2;
	ky = textheight(p) * 2 + (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);
	Sleep(1000);

	strcpy(p, "2秒后自动退出");
	kx = (800 - textwidth(p)) / 2;
	ky = textheight(p) * 2 + (600 - textheight(p)) / 2;
	outtextxy(kx, ky, p);
	Sleep(1000);

	strcpy(p, "1秒后自动退出");
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

//退出操作
int gamebyebye02()
{
	initgraph(800, 600, EW_NOCLOSE);

	char* p = (char*)malloc(sizeof(char) * 64);
	settextstyle(30, 0, "黑体");

	strcpy(p, "游戏退出");
	int kx1 = (800 - textwidth(p)) / 2;
	int ky1 = (600 - textheight(p)) / 2;
	outtextxy(kx1, ky1, p);

	strcpy(p, "请点击文字");
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
				if ((msg.x >= kx1 && msg.x <= kx1 + textwidth("游戏退出") && msg.y >= ky1 && msg.y <= ky2 + textheight("游戏退出"))
					|| (msg.x >= kx2 && msg.x <= kx2 + textwidth("请点击文字") && msg.y >= ky2 && msg.y <= ky2 + textheight("请点击文字")))
				{
					strcpy(p, "后面没内容了···");
					outtextxy(kx3, ky3, p);
				}
				if (/*(msg.x >= kx1 && msg.x <= kx1 + textwidth("游戏退出") && msg.y >= ky1 && msg.y <= ky2 + textheight("游戏退出"))
					| (msg.x >= kx2 && msg.x <= kx2 + textwidth("请点击右上角按键") && msg.y >= ky2 && msg.y <= ky2 + textheight("请点击右上角按键"))
					|*/(msg.x >= kx3 && msg.x <= kx3 + textwidth("后面没内容了···") && msg.y >= ky3 && msg.y <= ky3 + textheight("后面没内容了···")))
				{
					strcpy(p, "真没内容了");
					outtextxy(kx4, ky4, p);
				}
				if (msg.x >= kx4 && msg.x <= kx4 + textwidth("真没内容了") && msg.y >= ky4 && msg.y <= ky4 + textheight("真没内容了"))
				{
					strcpy(p, "还想来一把吗？");
					outtextxy(kx5, ky5, p);
				}
				if (msg.x >= kx5 && msg.x <= kx5 + textwidth("还想来一把吗？") && msg.y >= ky5 && msg.y <= ky5 + textheight("还想来一把吗？"))
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

//游戏模式选择页面。输入：坐标；输出：无
int gameplay(int x, int y, int w, int h)
{
	POINT pts[] = { {0,20} ,{35,0}, {35,40} };
	initgraph(800, 600, EW_SHOWCONSOLE);
	//绘制背景
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
	settextstyle(30, 0, "黑体");

	strcpy(p, "自由模式");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "闯关模式");
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
					strcpy(p, "自由模式");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 2) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					fillroundrect(x, y * 2, x + w, y * 2 + h, 10, 10);
					strcpy(p, "自由模式");
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
					strcpy(p, "闯关模式");
					kx = x + (w - textwidth(p)) / 2;
					ky = (y * 3) + (h - textheight(p)) / 2;
					outtextxy(kx, ky, p);
					Sleep(100);
					setlinecolor(WHITE);
					strcpy(p, "闯关模式");
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
	//绘制背景
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
	settextstyle(30, 0, "黑体");

	strcpy(p, "有界");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "无界");
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
					strcpy(p, "有界");
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
					strcpy(p, "无界");
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
	//绘制背景
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
	settextstyle(30, 0, "黑体");

	strcpy(p, "关卡1");
	int kx = x + (w - textwidth(p)) / 2;
	int ky = (y * 1) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "关卡2");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 2) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "关卡3");
	kx = x + (w - textwidth(p)) / 2;
	ky = (y * 3) + (h - textheight(p)) / 2;
	outtextxy(kx, ky, p);

	strcpy(p, "未完待续");
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
					strcpy(p, "关卡1");
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
					strcpy(p, "关卡2");
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
					strcpy(p, "关卡3");
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
					strcpy(p, "关卡4");
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



//改游戏声音大小。输入：接收键盘所打字母的变量  输出：无
void gamesound(char)
{

}

//设置初始背景音乐，更改游戏的背景音乐。输入：屏幕上点的坐标  输出：无
void gamemusic(int, int)
{

}

//改蛇的速度、进入自由或闯关模式游玩。输入：接收键盘所打字母的变量 点的坐标  输出：无
void snakespeed(char, int, int)
{

}

//进入蛇皮肤修改和游戏背景修改中心。输入：点坐标  输出：无
void gamecover(int, int)
{

}

//蛇皮肤修改。输入：点坐标  输出：无
void snakecover(int, int)
{

}

//游戏背景修改。输入；点坐标  输出：无
void background(int, int)
{

}

//退出游戏操作
void gamebyebye()
{

}
#pragma once
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>  //多媒体设备接口
#pragma comment(lib,"winmm.lib")  //加载静态库
#include<conio.h>  //控制台输入输出头文件
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define SNAKE_NUM 400000  //蛇的最大节数

//蛇的方向
enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

//蛇的结构
struct Snake
{
	int size;  //蛇的节数
	int dir;  //方向
	int speed;  //速度
	POINT coor[SNAKE_NUM];  //坐标
}snake;

//移动蛇
void snakeMove()
{
	//联动
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];
	}
	//移动改变
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

//通过按键改变蛇的移动方向
void keyControl()
{
	//判断有没有按键,如果按键则返回true
	if (_kbhit())
	{
		//72 80 75 77 上下左右
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
			//游戏暂停
		case 'p':
		case 'P':
			while (1)
			{
				if (_getch() == 'p' && _getch() == 'P')
					return;
			}
			break;
		}
	}
}

//蛇的死亡判定
bool snakeDead()
{



	return true;
}


//食物结构
struct Food
{
	int x;
	int y;
	int r;  //食物大小
	bool flag;  //食物是否被吃
	DWORD color;  //食物颜色
}food;

//吃到食物（果实、碎片）后蛇加长（得分）
void EatFoodScore()
{
	if (food.flag && snake.coor[0].x >= food.x - 2 - food.r && snake.coor[0].x <= food.x + 1 + food.r &&
		snake.coor[0].y >= food.y - 2 - food.r && snake.coor[0].y <= food.y + food.r)
	{
		food.flag = false;
		snake.size++;
	}
	//食物刷新
	if (!food.flag)
	{
		food.x = rand() % 790;
		food.y = rand() % 590;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = 5;
		food.flag = true;
	}
}

//吃到果实后加速及计步判定
void EatFoodQ()
{

}

//吃到果实后减速及计步判定
void EatFoodS()
{

}

//加速按键及其效果
void SpeedQuicky()
{

}

//数据初始化
void GameInit()
{
	//初始化图形窗口
	initgraph(800, 600);
	//设置随机数种子
	srand(GetTickCount());
	// 初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
	//初始化食物
	food.x = rand() % 790;
	food.y = rand() % 590;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.flag = true;
}

//绘图(食物和蛇)
void GameDraw()
{
	//双缓冲绘图
	BeginBatchDraw();
	//绘制背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./hwx.jpg", wide, height);
	putimage(0, 0, &img);
	//绘制蛇头
	for (int i = 0; i < snake.size; i++)
	{
		setfillcolor(RGB(240, 240, 240));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制蛇身
	for (int i = 1; i < snake.size; i++)
	{
		setfillcolor(RGB(126, 239, 123));
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制食物
	if (food.flag)
	{
		setfillcolor(RGB(140, 80, 120));
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}


//设置背景音乐
void BGM()
{
	mciSendString("open ./", 0, 0, 0);
	mciSendString("play ./", 0, 0, 0);
}
