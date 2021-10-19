#include"snake.h"




int main()
{

	GameInit();
	
	while (1)
	{
		GameDrawF();
		snakeMove();
		keyControl();
		EatFoodScore();
		


		Sleep(80);
	}

	
	return 0;
}