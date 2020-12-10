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
	for(who_win = 1;who_win<=2;who_win++)
	{
		if(PLAYER[who_win].first == -1 && PLAYER[who_win].second == -1)
			return who_win;
	}
	return 0;
}

void Win_Print(int a) // Print who win the game
{
	cout<<" --------------------- "<<endl;
	cout<<"      Score Result "<<endl;
	cout<<" --------------------- "<<endl;
	cout<<" |                    | "<<endl;
	for(int i=1 ; i<3;i++)
	{
		if(i == a)
		{
			cout<<" |    Player"<<i<<" Win!    | "<<endl;
			cout<<" |♥  Congratulation ♥ |"<<endl;
			cout<<" |                    | "<<endl;
		}
		else
		{
			cout<<" |    Player"<<i<<" lose!   | "<<endl;
			cout<<" |                    | "<<endl;
		}
	}
	cout<<" --------------------- "<<endl;
}

/*** YUTs ***/
int Roll_Yut(string roll) // Roll Yuts using random function
{
	int yut;

	if(roll!="R")
		return -2;

	yut=rand()%(16);

	if(yut==0)
		yut=-1;
	else if(yut>=1 && yut<=3)
		yut=1;
	else if(yut>=4 && yut<=9)
		yut=2;
	else if(yut>=10 && yut<=13)
		yut=3;
	else if(yut==14)
		yut=4;
	else
		yut=5;

	return yut;
}

void Yut_Print(int a) // Print 6 cases of Yuts
{
	if(a == -1)
	{
		cout<<"  ---     ---     ---     --- "<<endl;
		cout<<" | - |   | x |   | x |   | x |"<<endl;
		cout<<" | - |   | x |   | x |   | x |"<<endl;
		cout<<" | - |   | x |   | x |   | x |"<<endl;
		cout<<" | - |   | x |   | x |   | x |"<<endl;
		cout<<"  ---     ---     ---     --- "<<endl;
	}
	else if(a == 1)
	{
		cout<<" ---    ---     ---     --- "<<endl;
		cout<<" | |   | x |   | x |   | x |"<<endl;
		cout<<" | |   | x |   | x |   | x |"<<endl;
		cout<<" | |   | x |   | x |   | x |"<<endl;
		cout<<" | |   | x |   | x |   | x |"<<endl;
		cout<<" ---    ---     ---     --- "<<endl;
	}
	else if(a == 2)
	{
		cout<<" ---   ---    ---     --- "<<endl;
		cout<<" | |   | |   | x |   | x |"<<endl;
		cout<<" | |   | |   | x |   | x |"<<endl;
		cout<<" | |   | |   | x |   | x |"<<endl;
		cout<<" | |   | |   | x |   | x |"<<endl;
		cout<<" ---   ---    ---     --- "<<endl;
	}
	else if(a == 3)
	{
		cout<<" ---   ---   ---    --- "<<endl;
		cout<<" | |   | |   | |   | x |"<<endl;
		cout<<" | |   | |   | |   | x |"<<endl;
		cout<<" | |   | |   | |   | x |"<<endl;
		cout<<" | |   | |   | |   | x |"<<endl;
		cout<<" ---   ---   ---    --- "<<endl;
	}
	else if(a == 4)
	{
		cout<<" ---   ---   ---   --- "<<endl;
		cout<<" | |   | |   | |   | |"<<endl;
		cout<<" | |   | |   | |   | |"<<endl;
		cout<<" | |   | |   | |   | |"<<endl;
		cout<<" | |   | |   | |   | |"<<endl;
		cout<<" ---   ---   ---   --- "<<endl;
	}
	else if(a == 5)
	{
		cout<<"  ---     ---     ---     --- "<<endl;
		cout<<" | x |   | x |   | x |   | x |"<<endl;
		cout<<" | x |   | x |   | x |   | x |"<<endl;
		cout<<" | x |   | x |   | x |   | x |"<<endl;
		cout<<" | x |   | x |   | x |   | x |"<<endl;
		cout<<"  ---     ---     ---     --- "<<endl;
	}
	return;
}



/**** Board ****/
int FIRST_STATE[21][21]={
{2,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{2,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2},
};

int BOARD_STATE[21][21];

void Board_Init() // Init Board_State
{
	int i,j;
	for(i=0;i<21;i++)
	for(j=0;j<21;j++)
	BOARD_STATE[i][j]=FIRST_STATE[i][j];
}

/***   Horse position match with matrix coordinate       ***/
pair<int,int> Pos_To_Coord(int horse_pos)
{
	map<int,pair<int,int>> coord;

	return coord[horse_pos];
}

int Coord_TO_Pos(pair<int,int> coord)
{
	map<pair<int,int>,int> horse_pos;
	return horse_pos[{coord.first,coord.second}];
}
/***********************************************************/

void Board_Update(int player,int horse) // update the board when the horse's position changed
{
	pair<int,int> coord;

	if(horse==1)
	{	
		if(PLAYER[player].first != 1)
		{
			coord=Pos_To_Coord(PLAYER[player].first);
			BOARD_STATE[coord.first][coord.second]=3;
		}

		if(PLAYER[player+2].first != 1 && PLAYER[player+2].first != PLAYER[player].second && PLAYER[player+2].first != PLAYER[player].first)
		{
			coord=Pos_To_Coord(PLAYER[player+2].first);
			BOARD_STATE[coord.first][coord.second]=FIRST_STATE[coord.first][coord.second];
		}

	}
	else
	{
		if(PLAYER[player].second != 1)
		{
			coord=Pos_To_Coord(PLAYER[player].second);
			BOARD_STATE[coord.first][coord.second]=3;
		}


		if(PLAYER[player+2].second != 1 && PLAYER[player+2].second != PLAYER[player].first && PLAYER[player+2].second != PLAYER[player].second)
		{
			coord=Pos_To_Coord(PLAYER[player+2].second);
			BOARD_STATE[coord.first][coord.second]=FIRST_STATE[coord.first][coord.second];
		}
	}
	if(PLAYER[player].first==PLAYER[player].second)
	{
		coord=Pos_To_Coord(PLAYER[player+2].second);
		BOARD_STATE[coord.first][coord.second]=FIRST_STATE[coord.first][coord.second];
	}
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
	int catch_other=0;
	int horse_pos;
	int prev_pos;
	if(horse==1)
	{
		prev_pos=PLAYER[player+2].first;
		horse_pos=PLAYER[player].first;
		PLAYER[player+2].first=horse_pos;
	}
	else
	{
		prev_pos=PLAYER[player+2].second;
		horse_pos=PLAYER[player].second;
		PLAYER[player+2].second=horse_pos;
	}

	if(PLAYER[player].first==PLAYER[player].second && PLAYER[player].first!=1) // the horses overlapped
	{
		PLAYER[player+2].first=horse_pos;
		PLAYER[player+2].second=horse_pos;
	}

	if(yut==-1) // Back_Do.. go back 1 block.. direction is where the horse comes from...
	{
		if(horse_pos==1)
			return 0;

		if(horse_pos==2)
			horse_pos=30;
		else if(horse_pos==16)
		{
			if(prev_pos<16)
				horse_pos--;
			else
				horse_pos+=9;
		}
		else if(horse_pos==23)
		{
			if(prev_pos == 11 || prev_pos ==26 || prev_pos ==27)
				horse_pos+=4;
			else
				horse_pos--;
		}
		else
			horse_pos--;
	}
	else if(yut>0)
	{
		if(horse_pos<21 && horse_pos != 6 && horse_pos !=11 && horse_pos !=16 )
		{
			horse_pos+=yut;
			if(horse_pos>20)
				horse_pos+=9;
		}
		else if(horse_pos==6)
		{
			horse_pos+=yut+14;
		}
		else if(horse_pos==11)
		{
			if(yut==3)
				horse_pos=23;
			else
			{
				if(yut<3)
					horse_pos+=yut+14;
				else
					horse_pos+=yut+13;
			}
		}
		else if(horse_pos==23)
		{
			horse_pos+=yut+4;
		}
		else if(horse_pos<26)
		{
			horse_pos+=yut;
			if(horse_pos>25)
				horse_pos-=10;
		}
		else
		{
			horse_pos+=yut;
			if(horse_pos==28)
				horse_pos=23;
			else if(horse_pos>28)
				horse_pos+=-1;	
		}
	}

	///horse out!!...////
	if(horse_pos>30)
		horse_pos=-1;


	////catch or not/////
	if(player==1)
	{
		if(horse_pos==PLAYER[2].first && horse_pos<31)
		{
			PLAYER[2].first=1;
			PLAYER[4].first=1;
			catch_other=1;
		}

		if(horse_pos==PLAYER[2].second && horse_pos<31)
		{
			PLAYER[2].second=1;
			PLAYER[4].second=1;
			catch_other=1;
		}
	}
	else
	{
		if(horse_pos==PLAYER[1].first && horse_pos<31)
		{
			PLAYER[1].first=1;
			PLAYER[3].first=1;
			catch_other=1;
		}

		if(horse_pos==PLAYER[1].second && horse_pos<31)
		{
			PLAYER[1].second=1;
			PLAYER[3].second=1;
			catch_other=1;
		}
	}
	/////////////////////

	if(PLAYER[player].first==PLAYER[player].second && PLAYER[player].first!=1)
	{
		PLAYER[player].first=horse_pos;
		PLAYER[player].second=horse_pos;
	}
	else{
		if(horse==1)
			PLAYER[player].first=horse_pos;
		else
			PLAYER[player].second=horse_pos;
	}

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
