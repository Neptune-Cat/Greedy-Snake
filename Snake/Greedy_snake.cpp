#include<stdio.h>
#include<graphics.h>

int main()
{
	//��ʼ�� ͼ�δ���
	initgraph(800, 600);
	//���ñ���
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, L"C:\\Users\\15971\\source\\repos\\Greedy Snake\\Snake\\bk.jpg", wide, height);
	putimage(0, 0, &img);

	while (1)
	{

	}
}