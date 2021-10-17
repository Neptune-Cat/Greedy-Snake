#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>  //控制台输入输出头文件
#include<stdlib.h>

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

//数据初始化
void GameInit()
{
	//初始化图形窗口
	initgraph(800, 600);
	// 初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
}

//绘图
void GameDraw()
{
	//双缓冲绘图
	BeginBatchDraw();
	//绘制背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, L"C:\\Users\\15971\\source\\repos\\Greedy Snake\\Snake\\bk.jpg", wide, height);
	putimage(0, 0, &img);
	//绘制蛇
	setfillcolor(RGB(126, 239, 123));
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	EndBatchDraw();
}

//移动蛇
void snakeMove()
{
	//联动
	for (int i = snake.size-1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];
	}
	//移动改变
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y -= snake.speed;
		break;
	case DOWN:
		snake.coor[0].y += snake.speed;
		break;
	case LEFT:
		snake.coor[0].x -= snake.speed;
		break;
	case RIGHT:
		snake.coor[0].x += snake.speed;
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
		case 72:
			if (snake.dir != DOWN)
			{
				snake.dir = UP;
			}
			break;
		case's':
		case'S':
		case 80:
			if (snake.dir != UP)
			{
				snake.dir = DOWN;
			}
			break;
		case'a':
		case'A':
		case 75:
			if (snake.dir != RIGHT)
			{
				snake.dir = LEFT;
			}
			break;
		case'd':
		case'D':
		case 77:
			if (snake.dir != LEFT)
			{
				snake.dir = RIGHT;
			}
			break;
		}
	}
}

int main()
{

	GameInit();
	
	while (1)
	{
		GameDraw();
		snakeMove();
		keyControl();
		Sleep(80);
	}
	return 0;
}