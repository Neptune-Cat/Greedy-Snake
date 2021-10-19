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
