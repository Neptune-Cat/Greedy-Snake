#include"snake.h"




//int main()
//{
//	
//	GameInitF2();
//	while (1)
//	{
//		
//		
//		
//		
//		
//
//		while (1)
//				{
//					GameDrawF1();
//					keyControl();
//					snakeMove();
//					Sleep(80);
//				}
//
//
//
//	}
//	while (1)
//	{
//		gamebegin(320, 120, 140, 60);
//		
//	}
//
//
//	return 0;
//}
int main()
{

    gamebegin(320, 120, 140, 60);

    while (1)
    {

        while (n01 != 0)
        {
            if (n01 == 1)
            {
                n01 = 0;
                gameset(320, 120, 140, 60);
                break;
            }
            if (n01 == 2)
            {
                n01 = 0;
                gameplay(320, 120, 140, 60);
                break;
            }
            if (n01 == 3)
            {
                n01 = 0;
                gamerule();
                break;
            }
            if (n01 == 4)
            {
                n01 = 0;
                gamebyebye01();
                Sleep(1000);
                return n01;
            }
        }

        while (n02 != 0)
        {
            if (n02 == 1)
            {

            }
            if (n02 == 2)
            {

            }
            if (n02 == 3)
            {

            }
            if (n02 == 4)
            {

            }
            if (n02 == 5)
            {
                n02 = 0;
                gamebegin(320, 120, 140, 60);
                break;
            }
        }

        while (n03 != 0)
        {
            if (n03 == 1)
            {
                n03 = 0;
                gamefree(320, 120, 140, 60);
                break;
            }
            if (n03 == 2)
            {
                n03 = 0;
                gamebreak(320, 120, 140, 60);
                break;
            }
        }

    }
    return 0;
}
