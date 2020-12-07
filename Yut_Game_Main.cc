#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <map>

using namespace std;

map<int,pair<int,int>>PLAYER;

int Check_Who_Win() // Find who does not have no horse
{
	int who_win;
	return who_win;
}

void Win_Print(int a) // Print who win the game
{
}
/*** YUTs ***/
int Roll_Yut(string roll) // Roll Yuts using random function
{
}

void Yut_Print(int a) // Print 6 cases of Yuts
{
}



/**** Board ****/
void Board_Init() // Init Board_State
{
	
}
void Board_Update(int player,int horse) // update the board when the horse's position changed
{
}

void Board_Print() // print the Yut_board with player's horse
{
}

/**** Horse ****/
void Horse_State() // check each player's horse state
{
}

int Move_Horse(int player, int horse, int yut) // After roll the yuts, find the horse where it can move 
{
	int catch_other;
	return catch_other;
}

/**** Accumulation ****/
int* Init_Accumulation(int* accumulation)
{
	for(int i=0;i<6;i++)
		accumulation[i]=0;

	return accumulation;
}

int main()
{
	int yut,player_turn=1,horse, move_num=1,i,choose;
	int check_who_win=0, yut_or_mo=0, catch_other=0;
	int *accumulation=new int(6);
	string roll="N";
	srand((unsigned int)time(NULL));
	cout<<"--------------------------------------------"<<endl;
	cout<<"    THis game is Yut_Nori for 2 players"<<endl;
	cout<<"--------------------------------------------"<<endl;

	cout<<"------------------------------"<<endl;
	cout<<"       GAME    START!!"<<endl;
	cout<<"------------------------------"<<endl;

	PLAYER[1]={1,1};
	PLAYER[2]={1,1};


	while(1)
	{
		move_num=1;
		cout<<endl<<"!!!!!!!!!!!!!!!  Player"<<player_turn<<"'s turn  !!!!!!!!!!!!!!!"<<endl;

		accumulation=Init_Accumulation(accumulation);

		while(1)
		{
			cout<<"   ROLL THE YUTS!!! (press the button [R])"<<endl;
			cin>>roll;
			while(1)
			{
				if(roll=="R")
					break;
				cout<<"HEY Click the button [R] exactly!!!"<<endl;
				cin>>roll;
			}
			yut=Roll_Yut(roll);
			Yut_Print(yut);

			if(yut==-1)
				accumulation[0]++;
			else
				accumulation[yut]++;

			if(yut==4 || yut==5)
			{
				yut_or_mo=1;
				move_num++;
			}
			else
				yut_or_mo=0;

			if(!yut_or_mo)
				break;
		}
		
		if(check_who_win) // The End of Game
		{
			Win_Print(check_who_win);
			break;
		}
	}

	return 0;
}
