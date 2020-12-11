#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <map>

using namespace std;

void Set_Console_View()
{
	system(" mode con cols=100 lines=50 ");
}

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
		cout<<"  ---     ---     ---     --- "<<endl;
		cout<<" |   |   | x |   | x |   | x |"<<endl;
		cout<<" |   |   | x |   | x |   | x |"<<endl;
		cout<<" |   |   | x |   | x |   | x |"<<endl;
		cout<<" |   |   | x |   | x |   | x |"<<endl;
		cout<<"  ---     ---     ---     --- "<<endl;
	}
	else if(a == 2)
	{
		cout<<"  ---     ---     ---     --- "<<endl;
		cout<<" |   |   |   |   | x |   | x |"<<endl;
		cout<<" |   |   |   |   | x |   | x |"<<endl;
		cout<<" |   |   |   |   | x |   | x |"<<endl;
		cout<<" |   |   |   |   | x |   | x |"<<endl;
		cout<<"  ---     ---     ---     --- "<<endl;
	}
	else if(a == 3)
	{
		cout<<"  ---     ---     ---     --- "<<endl;
		cout<<" |   |   |   |   |   |   | x |"<<endl;
		cout<<" |   |   |   |   |   |   | x |"<<endl;
		cout<<" |   |   |   |   |   |   | x |"<<endl;
		cout<<" |   |   |   |   |   |   | x |"<<endl;
		cout<<"  ---     ---     ---     --- "<<endl;
	}
	else if(a == 4)
	{
		cout<<"  ---     ---     ---     --- "<<endl;
		cout<<" |   |   |   |   |   |   |   |"<<endl;
		cout<<" |   |   |   |   |   |   |   |"<<endl;
		cout<<" |   |   |   |   |   |   |   |"<<endl;
		cout<<" |   |   |   |   |   |   |   |"<<endl;
		cout<<"  ---     ---     ---     --- "<<endl;
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

	coord[11] = {0,0};
	coord[10] = {0,4};
	coord[9] = {0,8};
	coord[8] = {0,12};
	coord[7] = {0,16};
	coord[6] = {0,20};
	coord[5] = {4,20};
	coord[4] = {8,20};
	coord[3] = {12,20};
	coord[2] = {16,20};
	coord[1] = {1,1};
	coord[20] = {20,16};
	coord[19] = {20,12};
	coord[18] = {20,8};
	coord[17] = {20,4};
	coord[16] = {20,0};
	coord[15] = {16,0};
	coord[14] = {12,0};
	coord[13] = {8,0};
	coord[12] = {4,0};
	coord[26] = {4,4};
	coord[27] = {7,7};
	coord[23] = {10,10};
	coord[28] = {13,13};
	coord[29] = {16,16};
	coord[21] = {4,16};
	coord[22] = {7,13};
	coord[24] = {13,7};
	coord[25] = {16,4};
	coord[30] = {20,20};

	return coord[horse_pos];
}

int Coord_To_Pos(pair<int,int> coord)
{
	map<pair<int,int>,int> horse_pos;

	horse_pos[{0,0}]=11;
	horse_pos[{0,4}]=10;
	horse_pos[{0,8}]=9;
	horse_pos[{0,12}]=8;
	horse_pos[{0,16}]=7;
	horse_pos[{0,20}]=6;
	horse_pos[{4,20}]=5;
	horse_pos[{8,20}]=4;
	horse_pos[{12,20}]=3;
	horse_pos[{16,20}]=2;
	horse_pos[{20,16}]=20;
	horse_pos[{20,12}]=19;
	horse_pos[{20,8}]=18;
	horse_pos[{20,4}]=17;
	horse_pos[{20,0}]=16;
	horse_pos[{16,0}]=15;
	horse_pos[{12,0}]=14;
	horse_pos[{8,0}]=13;
	horse_pos[{4,0}]=12;
	horse_pos[{4,4}]=26;
	horse_pos[{7,7}]=27;
	horse_pos[{10,10}]=23;
	horse_pos[{13,13}]=28;
	horse_pos[{16,16}]=29;
	horse_pos[{4,16}]=21;
	horse_pos[{7,13}]=22;
	horse_pos[{13,7}]=24;
	horse_pos[{16,4}]=25;
	horse_pos[{20,20}]=30;

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
	int i,j,horse_pos;
	cout<<endl;
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			if(BOARD_STATE[i][j] == 1)
				cout<<"●";
			else if(BOARD_STATE[i][j] == 2)
				cout<<"◎";
			else if(BOARD_STATE[i][j] ==3)
			{
				horse_pos=Coord_To_Pos({i,j});

				if(PLAYER[1].first == PLAYER[1].second && PLAYER[1].first == horse_pos)
					cout<<"▣ ";
				else if(PLAYER[2].first == PLAYER[2].second && PLAYER[2].first == horse_pos)
					cout<<"◈";
				else if(horse_pos==PLAYER[1].first)
					cout<<"□";
				else if(horse_pos==PLAYER[1].second)
					cout<<"■";
				else if(horse_pos==PLAYER[2].first)
					cout<<"◇";
				else
					cout<<"◆";
			}
			else
				cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return;
}


/**** Horse ****/
void Horse_State() // check each player's horse state
{

	Sleep(2000);
	system("cls");
	Sleep(1000);

	cout<<" --------------------------- "<<endl;
	cout<<"         Horse state "<<endl;
	cout<<" --------------------------- "<<endl;

	for(int a = 1;a<=2;a++)
	{
		cout<<"           Horse1 Horse2"<<endl;
		if(a == 1)
		{
			if(PLAYER[a].first != -1 && PLAYER[a].second != -1)
			{
				cout<<" Player"<<a<<" :   □      ■ "<<endl;
			}
			else if(PLAYER[a].first == -1 && PLAYER[a].second != -1)
			{
				cout<<" Player"<<a<<" :        ■ "<<endl;
			}
			else if(PLAYER[a].first != -1 && PLAYER[a].second == -1)
			{
				cout<<" Player"<<a<<" :   □ "<<endl;
			}
			else
			{
				cout<<" Player"<<a<<" finish! "<<endl;
			}

		}
		else
		{
			if(PLAYER[a].first != -1 && PLAYER[a].second != -1)
			{
				cout<<" Player"<<a<<" :   ◇      ◆ "<<endl;
			}
			else if(PLAYER[a].first == -1 && PLAYER[a].second != -1)
			{
				cout<<" Player"<<a<<" :        ◆ "<<endl;
			}
			else if(PLAYER[a].first != -1 && PLAYER[a].second == -1)
			{
				cout<<" Player"<<a<<" :   ◇ "<<endl;
			}
			else
			{
				cout<<" Player"<<a<<" finish! "<<endl;
			}
		}
	}
	cout<<endl;
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
		else if(horse_pos==26)
			horse_pos=11;
		else if(horse_pos=28)
			horse_pos=23;
		else if(horse_pos=21)
			horse_pos=6;
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
		else if(horse_pos==30)
			horse_pos=-1;
		else if(horse_pos==26 || horse_pos==27)
		{
			horse_pos+=yut;
			if(horse_pos==28)
				horse_pos=23;
			else if(horse_pos>28)
				horse_pos+=-1;	
		}
		else
		{
			horse_pos+=yut;
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

int Overlap_Horse(int player_turn)
{
	if(PLAYER[player_turn].first==PLAYER[player_turn].second && PLAYER[player_turn].first!=1)
		return 1;
	else
		return 0;
}

/**** Accumulation ****/
int *accumulation=new int(6);

void Init_Accumulation()
{
	for(int i=0;i<6;i++)
		accumulation[i]=0;
}

int Record_Yut(int yut)
{
	int yut_or_mo;

	if(yut==-1)
		accumulation[0]++;
	else				
		accumulation[yut]++;

	if(yut==4 || yut==5)
	{
		yut_or_mo=1;
	}
	else
		yut_or_mo=0;

	return yut_or_mo;
}
//////////////////////////

int main()
{
	Set_Console_View();
	int yut,player_turn=1,horse, move_num=1,i,choose, select, overlap;
	int check_who_win=0, yut_or_mo=0,catch_other=0;
	string roll="N";
	srand((unsigned int)time(NULL));
	cout<<"--------------------------------------------"<<endl;
	cout<<"    THis game is Yut_Nori for 2 players"<<endl;
	cout<<"--------------------------------------------"<<endl;

	cout<<"------------------------------"<<endl;
	cout<<"       GAME    START!!"<<endl;
	cout<<"------------------------------"<<endl;

	Board_Init();
	PLAYER[1]={1,1};
	PLAYER[2]={1,1};
	PLAYER[3]={1,1};//player1 prev not player3!
	PLAYER[4]={1,1};//player2 prev not player4!

	Horse_State();
	Board_Print();



	while(1)
	{
		move_num=1;
		cout<<endl<<"!!!!!!!!!!!!!!!  Player"<<player_turn<<"'s turn  !!!!!!!!!!!!!!!"<<endl;

		Init_Accumulation();

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
			yut_or_mo=Record_Yut(yut);

			if(!yut_or_mo)
				break;

			move_num++;
		}
		
		if(move_num==1) // not yut_or_mo
		{
			if(yut==-1 && (PLAYER[player_turn].first==-1 || PLAYER[player_turn].first==1) && (PLAYER[player_turn].second==-1 || PLAYER[player_turn].second==1))
			{
				cout<< " There is no horse to move (Back-DO)!!!!!!)"<<endl;
				catch_other=0;
			}
			else{
				while(1)
				{
					overlap=Overlap_Horse(player_turn);
					if(!overlap)
					{
						cout<<" Select the horse what you want! [1/2]"<<endl;
						cin>>horse;
					}
					else
						horse=1;

					select=1;
					if(horse==1)
						if(PLAYER[player_turn].first==-1)
							select=0;
					else
						if(PLAYER[player_turn].second==-1)
							select=0;
					if(select)
						break;

					cout<<"Player"<<player_turn<<"'s "<<horse<<"'s horse is already gone.. choose other horse!"<<endl;
						
				}	
				catch_other=Move_Horse(player_turn,horse,yut);
				Board_Update(player_turn,horse);
			}
			Horse_State();
			Board_Print();
		}
		else // yut_or_mo
		{
			i=0;
			while(1)
			{
				check_who_win=Check_Who_Win();
				if(check_who_win)
					break;
				cout<<"Player"<<player_turn<<"'s turn! Check the list what you have!"<<endl;
				cout<<"Back_Do : "<<accumulation[0]<<" Do : "<<accumulation[1]<<" Gae : "<<accumulation[2]<<" Girl : "<<accumulation[3]<<" Yut : "<<accumulation[4]<<" Mo : "<<accumulation[5]<<endl;
				while(1)
				{				
					cout<<" What do you want? Back_Do[0] Do[1] Gae[2] Girl[3] Yut[4] Mo{5]"<<endl;
					cin>>choose;
					if(accumulation[choose]>0)
						break;
					else
						cout<<"You don't have... Select again"<<endl;
				}

				while(1)
				{
					overlap=Overlap_Horse(player_turn);
					if(!overlap)
					{
						cout<<" Select the horse what you want! [1/2]"<<endl;
						cin>>horse;
					}
					else
						horse=1;

					select=1;
					if(horse==1)
						if(PLAYER[player_turn].first==-1)
							select=0;
					else
						if(PLAYER[player_turn].second==-1)
							select=0;
					if(select)
						break;

					cout<<"Player"<<player_turn<<"'s "<<horse<<"'s horse is already gone.. choose other horse!"<<endl;
					
				}

				accumulation[choose]--;

				if(choose==0)
					choose=-1;

				catch_other=Move_Horse(player_turn,horse,choose);
			
				Board_Update(player_turn,horse);
				Horse_State();
				Board_Print();

				if(catch_other)
				{
					move_num++;
					while(1)
					{
						cout<<endl<<"  Player"<<player_turn<<"' catches other player's horse!!"<<endl<<endl;
						cout<<"   ROLL THE YUTS!!! (press the button [R])"<<endl;
						cin>>roll;
						yut=Roll_Yut(roll);
						Yut_Print(yut);
						yut_or_mo=Record_Yut(yut);

						if(!yut_or_mo)
							break;
						move_num++;
					}
				}

				i++;

				if(i>=move_num)
					break;
			}
		}


		if(catch_other) // catch other player's horses
			cout<<"  Player"<<player_turn<<"' catches other player's horse!!"<<endl;
		else
		{
			if(player_turn==1)
				player_turn=2;
			else
				player_turn=1;
		}

		check_who_win=Check_Who_Win();//judge the game end
		if(check_who_win)
		{
			Win_Print(check_who_win);
			break;
		}
	}
	return 0;
}
