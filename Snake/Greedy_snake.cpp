#include<stdio.h>
#include<graphics.h>

using namespace std;

int main()
{
	//��ʼ�� ͼ�δ���
	initgraph(800, 600);
	//���ñ���
	IMAGE image1;
	loadimage(&image1, L, 100, 100);
	putimage(0, 0, &image1);
	cleardevice();
	while (1)
	{

	}
}