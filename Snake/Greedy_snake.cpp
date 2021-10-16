#include<stdio.h>
#include<graphics.h>

int main()
{
	//初始化 图形窗口
	initgraph(800, 600);
	//设置背景
	IMAGE img;
	int wide = 800, height = 600;
	loadimage(&img, L"C:\\Users\\15971\\source\\repos\\Greedy Snake\\Snake\\bk.jpg", wide, height);
	putimage(0, 0, &img);

	while (1)
	{

	}
}