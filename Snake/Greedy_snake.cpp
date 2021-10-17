#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>  //控制台输入输出头文件
#include<stdlib.h>

#define SNAKE_NUM 400000  //蛇的最大节数

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
	snake.dir;
	for (int i = snake.size - 1; i >= 0; i--)
	{
		snake.coor[i].x = 10 * i + 400;
		snake.coor[i].y = 300;
	}
}

//绘图
void GameDraw()
{
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
}

//移动蛇
void snakeMove()
{

}

int main()
{

	GameInit();
	GameDraw();

	
	while (1)
	{

	}
	return 0;
}