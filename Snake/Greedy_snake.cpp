#include<stdio.h>
#include<graphics.h>

using namespace std;

int main()
{
	//初始化 图形窗口
	initgraph(800, 600);
	//设置背景
	IMAGE image1;
	loadimage(&image1, L, 100, 100);
	putimage(0, 0, &image1);
	cleardevice();
	while (1)
	{

	}
}