#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <map>
#include <Windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Set_Console_View()
{
    system(" mode con cols=100 lines=50 ");
}


map<int, pair<int, int>>PLAYER;


int Check_Who_Win() // Find who does not have no horse
{
    int who_win;
    for (who_win = 1; who_win <= 2; who_win++)
    {
        if (PLAYER[who_win].first == -1 && PLAYER[who_win].second == -1)
            return who_win;
    }
    return 0;
}

void Win_Print(int a) // Print who win the game
{
    cout << " --------------------- " << endl;
    cout << "      Score Result " << endl;
    cout << " --------------------- " << endl;
    cout << " |                    | " << endl;
    for (int i = 1; i < 3; i++)
    {
        if (i == a)
        {
            cout << " |    Player" << i << " Win!    | " << endl;
            cout << " |в╛  Congratulation в╛ |" << endl;
            cout << " |                    | " << endl;
        }
        else
        {
            cout << " |    Player" << i << " lose!   | " << endl;
            cout << " |                    | " << endl;
        }
    }
    cout << " --------------------- " << endl;
}

/*** YUTs ***/
int Roll_Yut(string roll) // Roll Yuts using random function
{
    int yut;

    if (roll != "R")
        return -2;

    yut = rand() % (16);

    if (yut == 0)
        yut = -1;
    else if (yut >= 1 && yut <= 3)
        yut = 1;
    else if (yut >= 4 && yut <= 9)
        yut = 2;
    else if (yut >= 10 && yut <= 13)
        yut = 3;
    else if (yut == 14)
        yut = 4;
    else
        yut = 5;

    return yut;
}

void Yut_Print(int a, int c) // Print 6 cases of Yuts
{
    //gotoxy(40,50);
    if (a == -1)
    {
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
        gotoxy(50, c); c++; cout << " | - |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " | - |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " | - |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " | - |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
    }
    else if (a == 1)
    {
        gotoxy(50, c); c++;   cout << "  ---     ---     ---     --- " << endl;
        gotoxy(50, c); c++; cout << " |   |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++;   cout << " |   |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " |   |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++;   cout << " |   |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
    }
    else if (a == 2)
    {
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
        gotoxy(50, c); c++; cout << " |   |   |   |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " |   |   |   |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " |   |   |   |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " |   |   |   |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
    }
    else if (a == 3)
    {
        gotoxy(50, c); c++;   cout << "  ---     ---     ---     --- " << endl;
        gotoxy(50, c); c++;   cout << " |   |   |   |   |   |   | x |" << endl;
        gotoxy(50, c); c++; cout << " |   |   |   |   |   |   | x |" << endl;
        gotoxy(50, c); c++; cout << " |   |   |   |   |   |   | x |" << endl;
        gotoxy(50, c); c++;   cout << " |   |   |   |   |   |   | x |" << endl;
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
    }
    else if (a == 4)
    {
        gotoxy(50, c); c++;   cout << "  ---     ---     ---     --- " << endl;
        gotoxy(50, c); c++;   cout << " |   |   |   |   |   |   |   |" << endl;
        gotoxy(50, c); c++; cout << " |   |   |   |   |   |   |   |" << endl;
        gotoxy(50, c); c++;   cout << " |   |   |   |   |   |   |   |" << endl;
        gotoxy(50, c); c++; cout << " |   |   |   |   |   |   |   |" << endl;
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
    }
    else if (a == 5)
    {
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
        gotoxy(50, c); c++; cout << " | x |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " | x |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " | x |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << " | x |   | x |   | x |   | x |" << endl;
        gotoxy(50, c); c++; cout << "  ---     ---     ---     --- " << endl;
    }
    return;
}



/**** Board ****/
int FIRST_STATE[21][21] = {
   { 2,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
   { 0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
   { 2,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2 },
};

int BOARD_STATE[21][21];

void Board_Init() // Init Board_State
{
    int i, j;
    for (i = 0; i < 21; i++)
        for (j = 0; j < 21; j++)
            BOARD_STATE[i][j] = FIRST_STATE[i][j];
}

/***   Horse position match with matrix coordinate       ***/
pair<int, int> Pos_To_Coord(int horse_pos)
{
    map<int, pair<int, int>> coord;

    coord[11] = { 0,0 };
    coord[10] = { 0,4 };
    coord[9] = { 0,8 };
    coord[8] = { 0,12 };
    coord[7] = { 0,16 };
    coord[6] = { 0,20 };
    coord[5] = { 4,20 };
    coord[4] = { 8,20 };
    coord[3] = { 12,20 };
    coord[2] = { 16,20 };
    coord[1] = { 1,1 };
    coord[20] = { 20,16 };
    coord[19] = { 20,12 };
    coord[18] = { 20,8 };
    coord[17] = { 20,4 };
    coord[16] = { 20,0 };
    coord[15] = { 16,0 };
    coord[14] = { 12,0 };
    coord[13] = { 8,0 };
    coord[12] = { 4,0 };
    coord[26] = { 4,4 };
    coord[27] = { 7,7 };
    coord[23] = { 10,10 };
    coord[28] = { 13,13 };
    coord[29] = { 16,16 };
    coord[21] = { 4,16 };
    coord[22] = { 7,13 };
    coord[24] = { 13,7 };
    coord[25] = { 16,4 };
    coord[30] = { 20,20 };

    return coord[horse_pos];
}

int Coord_To_Pos(pair<int, int> coord)
{
    map<pair<int, int>, int> horse_pos;

    horse_pos[{0, 0}] = 11;
    horse_pos[{0, 4}] = 10;
    horse_pos[{0, 8}] = 9;
    horse_pos[{0, 12}] = 8;
    horse_pos[{0, 16}] = 7;
    horse_pos[{0, 20}] = 6;
    horse_pos[{4, 20}] = 5;
    horse_pos[{8, 20}] = 4;
    horse_pos[{12, 20}] = 3;
    horse_pos[{16, 20}] = 2;
    horse_pos[{20, 16}] = 20;
    horse_pos[{20, 12}] = 19;
    horse_pos[{20, 8}] = 18;
    horse_pos[{20, 4}] = 17;
    horse_pos[{20, 0}] = 16;
    horse_pos[{16, 0}] = 15;
    horse_pos[{12, 0}] = 14;
    horse_pos[{8, 0}] = 13;
    horse_pos[{4, 0}] = 12;
    horse_pos[{4, 4}] = 26;
    horse_pos[{7, 7}] = 27;
    horse_pos[{10, 10}] = 23;
    horse_pos[{13, 13}] = 28;
    horse_pos[{16, 16}] = 29;
    horse_pos[{4, 16}] = 21;
    horse_pos[{7, 13}] = 22;
    horse_pos[{13, 7}] = 24;
    horse_pos[{16, 4}] = 25;
    horse_pos[{20, 20}] = 30;

    return horse_pos[{coord.first, coord.second}];
}
/***********************************************************/

void Board_Update(int player, int horse) // update the board when the horse's position changed
{
    pair<int, int> coord;

    if (horse == 1)
    {
        if (PLAYER[player].first != 1)
        {
            coord = Pos_To_Coord(PLAYER[player].first);
            BOARD_STATE[coord.first][coord.second] = 3;
        }

        if (PLAYER[player + 2].first != 1 && PLAYER[player + 2].first != PLAYER[player].second && PLAYER[player + 2].first != PLAYER[player].first)
        {
            coord = Pos_To_Coord(PLAYER[player + 2].first);
            BOARD_STATE[coord.first][coord.second] = FIRST_STATE[coord.first][coord.second];
        }

    }
    else
    {
        if (PLAYER[player].second != 1)
        {
            coord = Pos_To_Coord(PLAYER[player].second);
            BOARD_STATE[coord.first][coord.second] = 3;
        }


        if (PLAYER[player + 2].second != 1 && PLAYER[player + 2].second != PLAYER[player].first && PLAYER[player + 2].second != PLAYER[player].second)
        {
            coord = Pos_To_Coord(PLAYER[player + 2].second);
            BOARD_STATE[coord.first][coord.second] = FIRST_STATE[coord.first][coord.second];
        }
    }
    if (PLAYER[player].first == PLAYER[player].second)
    {
        coord = Pos_To_Coord(PLAYER[player + 2].second);
        BOARD_STATE[coord.first][coord.second] = FIRST_STATE[coord.first][coord.second];
    }
}


void Board_Print() // print the Yut_board with player's horse
{
    gotoxy(0, 0);
    int i, j, horse_pos;
    cout << endl;
    for (i = 0; i < 21; i++)
    {
        gotoxy(3, i + 2);
        for (j = 0; j < 21; j++)
        {
            if (BOARD_STATE[i][j] == 1)
                cout << "б▄";
            else if (BOARD_STATE[i][j] == 2)
                cout << "б▌";
            else if (BOARD_STATE[i][j] == 3)
            {
                horse_pos = Coord_To_Pos({ i,j });

                if (PLAYER[1].first == PLAYER[1].second && PLAYER[1].first == horse_pos)
                    cout << "в├ ";
                else if (PLAYER[2].first == PLAYER[2].second && PLAYER[2].first == horse_pos)
                    cout << "в┬";
                else if (horse_pos == PLAYER[1].first)
                    cout << "бр";
                else if (horse_pos == PLAYER[1].second)
                    cout << "бс";
                else if (horse_pos == PLAYER[2].first)
                    cout << "б▐";
                else
                    cout << "б▀";
            }
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
////////////////////////////////////////////////////////////

/**** Horse ****/
void Horse_State() // check each player's horse state
{

    Sleep(2000);
    system("cls");
    Sleep(1000);

    gotoxy(50, 0); cout << " --------------------------- " << endl;
    gotoxy(50, 1); cout << "         Horse state " << endl;
    gotoxy(50, 2); cout << " --------------------------- " << endl;

    for (int a = 1; a <= 2; a++)
    {
        if (a == 1)
        {
            gotoxy(50, 3); cout << "           Horse1 Horse2" << endl;
            if (PLAYER[a].first != -1 && PLAYER[a].second != -1)
            {
                gotoxy(50, 4); cout << " Player" << a << " :   бр    бс " << endl;
            }
            else if (PLAYER[a].first == -1 && PLAYER[a].second != -1)
            {
                gotoxy(50, 4); cout << " Player" << a << " :         бс " << endl;
            }
            else if (PLAYER[a].first != -1 && PLAYER[a].second == -1)
            {
                gotoxy(50, 4); cout << " Player" << a << " :   бр " << endl;
            }
            else
            {
                gotoxy(50, 4); cout << " Player" << a << " finish! " << endl;
            }

        }
        else
        {
            gotoxy(50, 5); cout << "           Horse1 Horse2" << endl;
            if (PLAYER[a].first != -1 && PLAYER[a].second != -1)
            {
                gotoxy(50, 6); cout << " Player" << a << " :   б▐    б▀ " << endl;
            }
            else if (PLAYER[a].first == -1 && PLAYER[a].second != -1)
            {
                gotoxy(50, 6); cout << " Player" << a << " :         б▀ " << endl;
            }
            else if (PLAYER[a].first != -1 && PLAYER[a].second == -1)
            {
                gotoxy(50, 6); cout << " Player" << a << " :   б▐ " << endl;
            }
            else
            {
                gotoxy(50, 6);   cout << " Player" << a << " finish! " << endl;
            }
        }
    }
    cout << endl;
}


int Move_Horse(int player, int horse, int yut) // After roll the yuts, find the horse where it can move 
{
    int catch_other = 0;
    int horse_pos;
    int prev_pos;
    if (horse == 1)
    {
        prev_pos = PLAYER[player + 2].first;
        horse_pos = PLAYER[player].first;
        PLAYER[player + 2].first = horse_pos;
    }
    else
    {
        prev_pos = PLAYER[player + 2].second;
        horse_pos = PLAYER[player].second;
        PLAYER[player + 2].second = horse_pos;
    }

    if (PLAYER[player].first == PLAYER[player].second && PLAYER[player].first != 1) // the horses overlapped
    {
        PLAYER[player + 2].first = horse_pos;
        PLAYER[player + 2].second = horse_pos;
    }

    if (yut == -1) // Back_Do.. go back 1 block.. direction is where the horse comes from...
    {
        if (horse_pos == 1)
            return 0;

        if (horse_pos == 2)
            horse_pos = 30;
        else if (horse_pos == 26)
            horse_pos = 11;
        else if (horse_pos == 28)
            horse_pos = 23;
        else if (horse_pos == 21)
            horse_pos = 6;
        else if (horse_pos == 16)
        {
            if (prev_pos < 16)
                horse_pos--;
            else
                horse_pos += 9;
        }
        else if (horse_pos == 23)
        {
            if (prev_pos == 11 || prev_pos == 26 || prev_pos == 27)
                horse_pos += 4;
            else
                horse_pos--;
        }
        else
            horse_pos--;
    }
    else if (yut > 0)
    {
        if (horse_pos < 21 && horse_pos != 6 && horse_pos != 11 && horse_pos != 16)
        {
            horse_pos += yut;
            if (horse_pos > 20)
                horse_pos += 9;
        }
        else if (horse_pos == 6)
        {
            horse_pos += yut + 14;
        }
        else if (horse_pos == 11)
        {
            if (yut == 3)
                horse_pos = 23;
            else
            {
                if (yut < 3)
                    horse_pos += yut + 14;
                else
                    horse_pos += yut + 13;
            }
        }
        else if (horse_pos == 23)
        {
            horse_pos += yut + 4;
        }
        else if (horse_pos < 26)
        {
            horse_pos += yut;
            if (horse_pos > 25)
                horse_pos -= 10;
        }
        else if (horse_pos == 30)
            horse_pos = -1;
        else if (horse_pos == 26 || horse_pos == 27)
        {
            horse_pos += yut;
            if (horse_pos == 28)
                horse_pos = 23;
            else if (horse_pos > 28)
                horse_pos += -1;
        }
        else
        {
            horse_pos += yut;
        }
    }

    ///horse out!!...////
    if (horse_pos > 30)
        horse_pos = -1;


    ////catch or not/////
    if (player == 1)
    {
        if (horse_pos == PLAYER[2].first && horse_pos < 31)
        {
            PLAYER[2].first = 1;
            PLAYER[4].first = 1;
            catch_other = 1;
        }

        if (horse_pos == PLAYER[2].second && horse_pos < 31)
        {
            PLAYER[2].second = 1;
            PLAYER[4].second = 1;
            catch_other = 1;
        }
    }
    else
    {
        if (horse_pos == PLAYER[1].first && horse_pos < 31)
        {
            PLAYER[1].first = 1;
            PLAYER[3].first = 1;
            catch_other = 1;
        }

        if (horse_pos == PLAYER[1].second && horse_pos < 31)
        {
            PLAYER[1].second = 1;
            PLAYER[3].second = 1;
            catch_other = 1;
        }
    }
    /////////////////////

    if (PLAYER[player].first == PLAYER[player].second && PLAYER[player].first != 1)
    {
        PLAYER[player].first = horse_pos;
        PLAYER[player].second = horse_pos;
    }
    else {
        if (horse == 1)
            PLAYER[player].first = horse_pos;
        else
            PLAYER[player].second = horse_pos;
    }

    return catch_other;
}

int Overlap_Horse(int player_turn)
{
    if (PLAYER[player_turn].first == PLAYER[player_turn].second && PLAYER[player_turn].first != 1)
        return 1;
    else
        return 0;
}
///////////////////////////////////////////////////////

/**** Accumulation ****/
int* accumulation = new int(6);

void Init_Accumulation()
{
    for (int i = 0; i < 6; i++)
        accumulation[i] = 0;
}

int Record_Yut(int yut)
{
    int yut_or_mo;

    if (yut == -1)
        accumulation[0]++;
    else
        accumulation[yut]++;

    if (yut == 4 || yut == 5)
    {
        yut_or_mo = 1;
    }
    else
        yut_or_mo = 0;

    return yut_or_mo;
}
//////////////////////////


class Game ////execute game
{
    int yut, player_turn = 1, horse=1, move_num = 1, i=0, choose=0, select=0, overlap=0;
    int check_who_win = 0, yut_or_mo = 0, catch_other = 0;
    string roll = "N";
    int p = 10;
public:
    Game()
    {
        gotoxy(15 + p, 9 + p);   cout << "--------------------------------------------" << endl;
        gotoxy(15 + p, 10 + p);  cout << "    THis game is Yut_Nori for 2 players     " << endl;
        gotoxy(15 + p, 11 + p);   cout << "--------------------------------------------" << endl;
        gotoxy(15 + p, 12 + p);  cout << "--------------------------------------------" << endl;
        gotoxy(15 + p, 13 + p);   cout << "              GAME    START!!" << endl;
        gotoxy(15 + p, 14 + p);   cout << "--------------------------------------------" << endl;

        Board_Init();
        PLAYER[1] = { 1,1 };
        PLAYER[2] = { 1,1 };
        PLAYER[3] = { 1,1 };//player1 prev not player3!
        PLAYER[4] = { 1,1 };//player2 prev not player4!

        Horse_State();
        Board_Print();



        while (1)
        {
            move_num = 1;
            int c = 9;
            gotoxy(50, c); c++; cout << endl;
            gotoxy(50, c); c++; cout << "!!!!!!!!!!!!!!!  Player" << player_turn << "'s turn  !!!!!!!!!!!!!!!" << endl;

            Init_Accumulation();

            while (1)
            {
                gotoxy(50, c); c++; cout << "ROLL THE YUTS!!! (press the button [R]) : ";
                cin >> roll;
                while (1)
                {
                    if (roll == "R")
                        break;
                    gotoxy(50, c); c++; cout << "HEY Click the button [R] exactly!!! : ";
                    cin >> roll;
                }
                yut = Roll_Yut(roll);
                Yut_Print(yut, c);
                c = c + 6;
                yut_or_mo = Record_Yut(yut);

                if (!yut_or_mo)
                    break;

                move_num++;
            }

            if (move_num == 1) // not yut_or_mo
            {
                if (yut == -1 && (PLAYER[player_turn].first == -1 || PLAYER[player_turn].first == 1) && (PLAYER[player_turn].second == -1 || PLAYER[player_turn].second == 1))
                {
                    gotoxy(50, c); c++; cout << "There is no horse to move (Back-DO)!!!!!!)" << endl;
                    catch_other = 0;
                }
                else {
                    while (1)
                    {
                        overlap = Overlap_Horse(player_turn);
                        if (!overlap)
                        {
                            if (yut == -1 && (PLAYER[player_turn].first == -1 || PLAYER[player_turn].first == 1))
                            {
                                gotoxy(50, c); c++; cout << "The horse is automatically [2]!! ";
                                Sleep(1000);
                                horse = 2;
                            }
                            else if (yut == -1 && (PLAYER[player_turn].second == -1 || PLAYER[player_turn].second == 1))
                            {
                                gotoxy(50, c); c++; cout << "The horse is automatically [1]!! ";
                                Sleep(1000);
                                horse = 1;
                            }
                            else
                            {
                                while (1)
                                {
                                    gotoxy(50, c); c++; cout << "Select the horse what you want! [1/2] : ";
                                    cin >> horse;
                                    if (horse == 1 || horse == 2)
                                        break;
                                }
                            }

                        }
                        else
                            horse = 1;

                        select = 1;
                        if (horse == 1)
                            if (PLAYER[player_turn].first == -1)
                                select = 0;
                            else
                                if (PLAYER[player_turn].second == -1)
                                    select = 0;
                        if (select)
                            break;

                        gotoxy(50, c); c++; cout << "Player" << player_turn << "'s " << horse << "'s horse is already gone.. choose other horse!" << endl;

                    }
                    catch_other = Move_Horse(player_turn, horse, yut);
                    Board_Update(player_turn, horse);
                }
                Horse_State();
                c = 9;
                Board_Print();
            }
            else // yut_or_mo
            {
                i = 0;
                while (1)
                {
                    check_who_win = Check_Who_Win();
                    if (check_who_win)
                        break;
                    gotoxy(50, c); c++; cout << "Player" << player_turn << "'s turn! Check the list what you have!" << endl;
                    gotoxy(50, c); c++; cout << endl;
                    gotoxy(50, c); c++; cout << "Back_Do : " << accumulation[0] << " Do : " << accumulation[1] << " Gae : " << accumulation[2] << " Girl : " << accumulation[3];
                    gotoxy(50, c); c++;   cout << "Yut : " << accumulation[4] << " Mo : " << accumulation[5] << endl;
                    while (1)
                    {
                        gotoxy(50, c); c++; cout << "What do you want?";
                        while (1)
                        {
                            gotoxy(50, c); c++;   cout << "Back_Do[0] Do[1] Gae[2] Girl[3] Yut[4] Mo{5] : ";
                            cin >> choose;
                            if (choose <= 5 && choose >= 0)
                                break;
                        }
                        if (accumulation[choose] > 0)
                            break;
                        else
                            gotoxy(50, c); c++; cout << "You don't have... Select again" << endl;
                    }

                    while (1)
                    {
                        overlap = Overlap_Horse(player_turn);
                        if (!overlap)
                        {
                            gotoxy(50, c); c++; cout << endl;
                            if (choose == 0 && (PLAYER[player_turn].first == -1 || PLAYER[player_turn].first == 1))
                            {
                                gotoxy(50, c); c++; cout << "The horse is automatically [2]!! ";
                                Sleep(1000);
                                horse = 2;
                            }
                            else if (choose == 0 && (PLAYER[player_turn].second == -1 || PLAYER[player_turn].second == 1))
                            {
                                gotoxy(50, c); c++; cout << "The horse is automatically [1]!! ";
                                Sleep(1000);
                                horse = 1;
                            }
                            else
                            {
                                while (1)
                                {
                                    gotoxy(50, c); c++; cout << "Select the horse what you want! [1/2] : ";
                                    cin >> horse;
                                    if (horse == 1 || horse == 2)
                                        break;
                                }
                            }
                        }
                        else
                            horse = 1;

                        select = 1;
                        if (horse == 1)
                            if (PLAYER[player_turn].first == -1)
                                select = 0;
                            else
                                if (PLAYER[player_turn].second == -1)
                                    select = 0;
                        if (select)
                            break;

                        gotoxy(50, c); c++; cout << "Player" << player_turn << "'s " << horse << "'s horse is already gone..";
                        gotoxy(50, c); c++; cout << "choose other horse!" << endl;

                    }

                    accumulation[choose]--;

                    if (choose == 0)
                        choose = -1;

                    catch_other = Move_Horse(player_turn, horse, choose);

                    Board_Update(player_turn, horse);
                    Horse_State();
                    c = 9;
                    Board_Print();

                    if (catch_other)
                    {
                        move_num++;
                        while (1)
                        {
                            gotoxy(50, c); c++; cout << endl << "Player" << player_turn << " catches other player's horse!!";
                            gotoxy(50, c); c++; cout << endl;
                            gotoxy(50, c); c++; cout << "ROLL THE YUTS!!! (press the button [R])" << endl;
                            cin >> roll;
                            while (1)
                            {
                                if (roll == "R")
                                    break;
                                gotoxy(50, c); c++; cout << "HEY Click the button [R] exactly!!! : ";
                                cin >> roll;
                            }
                            yut = Roll_Yut(roll);
                            Yut_Print(yut, c);
                            yut_or_mo = Record_Yut(yut);

                            if (!yut_or_mo)
                                break;
                            move_num++;
                        }
                    }

                    i++;

                    if (i >= move_num)
                        break;
                }
            }


            if (catch_other) // catch other player's horses
            {
                gotoxy(50, c); c++;  cout << "Player" << player_turn << " catches other player's horse!!" << endl;
                gotoxy(50, c); c++;  cout << endl;
            }
            else
            {
                if (player_turn == 1)
                    player_turn = 2;
                else
                    player_turn = 1;
            }

            check_who_win = Check_Who_Win();//judge the game end
            if (check_who_win)
            {
                Win_Print(check_who_win);
                break;
            }
        }
    }
};

int main()
{
    Set_Console_View();
    srand((unsigned int)time(NULL));
    Game();
    return 0;
}
