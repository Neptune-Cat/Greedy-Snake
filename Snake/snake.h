#pragma once
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>  //��ý���豸�ӿ�
#pragma comment(lib,"winmm.lib")  //���ؾ�̬��
#include<conio.h>  //����̨�������ͷ�ļ�
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

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
			while (1)
			{
				if (_getch() == 'p' && _getch() == 'P')
					return;
			}
			break;
		}
	}
}

//�ߵ������ж�      ����ֵΪ��
bool snakeDead()
{
	return true;
}


//ʳ��ṹ
struct Food
{
	int x;
	int y;
	int r;  //ʳ���С
	bool flag;  //ʳ���Ƿ񱻳�
	DWORD color;  //ʳ����ɫ
}food;

//�Ե���ʵ���߼ӳ����÷֣���ʳ��ˢ��
void EatFoodScore()
{
	if (food.flag && snake.coor[0].x >= food.x - 2 - food.r && snake.coor[0].x <= food.x + 1 + food.r &&
		snake.coor[0].y >= food.y - 2 - food.r && snake.coor[0].y <= food.y + food.r)
	{
		food.flag = false;
		snake.size++;
	}
	//ʳ��ˢ�£������
	if (!food.flag)
	{
		food.x = rand() % 790;
		food.y = rand() % 590;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = 5;
		food.flag = true;
	}
}

//�Ե���ʵ����ټ��Ʋ��ж�
void EatFoodQ()
{

}

//�Ե���ʵ����ټ��Ʋ��ж�
void EatFoodS()
{

}

//���ٰ�������Ч��
void SpeedQuicky()
{

}

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

//���ƹ�ʵ���ߺ���Ϸ����
void GameDrawF()
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

//������Ƭ
void GameDrawP()
{

}

//�Ե���Ƭ��÷֣���Ƭˢ��
void EatP()
{

}

//�ش̣����ơ��Ʋ���
void TrapS()
{

}

//�ƶ�ǽ�����ơ��ƶ����Ʋ�����
void TrapW()
{

}

//������������ж����Ʋ���
void GetStar()
{

}



//��ҳ�����ӡ�����������ҳ����ж������룺����ĵ�����ꣻ�������
void gamebegin(int mouseX, int mouseY)
{

}

//��������ҳ����ж������룺���Խ�����ҳ��ĵ�����ꣻ�������
void gameset(int, int)
{

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

//��Ϸ����ҳ�棬��ӡ��Ϸ�������룺�ޣ��������
void gamerule()
{

}

//�˳���Ϸ����
void gamebyebye()
{

}

//��Ϸģʽѡ��ҳ�档���룺���ꣻ�������
void gameplay(int, int)
{

}
