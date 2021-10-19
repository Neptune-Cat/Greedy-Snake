#include"snake.h"




int main()
{

	GameInit();
	BGM();
	
	while (1)
	{
		GameDraw();
		snakeMove();
		keyControl();
		EatFoodScore();
		


		Sleep(80);
	}

	
	return 0;
}