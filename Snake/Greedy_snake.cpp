#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>  //����̨�������ͷ�ļ�
#include<stdlib.h>

#define SNAKE_NUM 400000  //�ߵ�������

//�ߵĽṹ
struct Snake
{
	int size;  //�ߵĽ���
	int dir;  //����
	int speed;  //�ٶ�
	POINT coor[SNAKE_NUM];  //����
}snake;

//���ݳ�ʼ��
void GameInit()
{
	//��ʼ��ͼ�δ���
	initgraph(800, 600);
	// ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir;
	for (int i = snake.size - 1; i >= 0; i--)
	{
		snake.coor[i].x = 10 * i + 400;
		snake.coor[i].y = 300;
	}
}

//��ͼ
void GameDraw()
{
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, L"C:\\Users\\15971\\source\\repos\\Greedy Snake\\Snake\\bk.jpg", wide, height);
	putimage(0, 0, &img);
	//������
	setfillcolor(RGB(126, 239, 123));
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
}

//�ƶ���
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