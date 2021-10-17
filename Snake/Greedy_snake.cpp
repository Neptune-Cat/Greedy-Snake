#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>  //��ý���豸�ӿ�
#pragma comment(lib,"winmm.lib")  //���ؾ�̬��
#include<conio.h>  //����̨�������ͷ�ļ�
#include<stdlib.h>
#include<time.h>

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

//ʳ��ṹ
struct Food
{
	int x;
	int y;
	int r;  //ʳ���С
	bool flag;  //ʳ���Ƿ񱻳�
	DWORD color;  //ʳ����ɫ
}food;

//���ݳ�ʼ��
void GameInit()
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
	food.x = rand() % 800;
	food.y = rand() % 600;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = 5;
	food.flag = true;
}

//��ͼ
void GameDraw()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���Ʊ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, "./hwx.jpg", wide, height);
	putimage(0, 0, &img);
	//������
	setfillcolor(RGB(126, 239, 123));
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//����ʳ��
	if (food.flag)
	{
		solidcircle(food.x, food.y, food.r);
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
			while (1)
			{
				if (_getch() == 'p' && _getch() == 'P')
					return;
			}
			break;
		}
	}
}

void EatFood()
{
	if (food.flag && snake.coor[0].x >= food.x - food.r && snake.coor[0].x <= food.x + food.r && 
		snake.coor[0].y >= food.y - food.r && snake.coor[0].y <= food.y + food.r)
	{
		food.flag = false;
		snake.size++;
	}
	//ʳ��ˢ��
	if (!food.flag)
	{
		food.x = rand() % 800;
		food.y = rand() % 600;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = 5;
		food.flag = true;
	}
}

void BGM()
{
	mciSendString("open ./", 0, 0, 0);
	mciSendString("play ./", 0, 0, 0);
}

int main()
{

	GameInit();
	BGM();
	
	while (1)
	{
		GameDraw();
		snakeMove();
		keyControl();
		EatFood();
		Sleep(80);
	}
	return 0;
}