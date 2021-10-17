#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>  //����̨�������ͷ�ļ�
#include<stdlib.h>

#define SNAKE_NUM 400000  //�ߵ�������

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

//���ݳ�ʼ��
void GameInit()
{
	//��ʼ��ͼ�δ���
	initgraph(800, 600);
	// ��ʼ����
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 400 - 10 * i;
		snake.coor[i].y = 300;
	}
}

//��ͼ
void GameDraw()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, L"C:\\Users\\15971\\source\\repos\\Greedy Snake\\Snake\\hwx.jpg", wide, height);
	putimage(0, 0, &img);
	//������
	setfillcolor(RGB(126, 239, 123));
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	EndBatchDraw();
}

//�ƶ���
void snakeMove()
{
	//����
	for (int i = snake.size-1; i > 0; i--)
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