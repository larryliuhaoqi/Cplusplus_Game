/* Game */
#include <iostream>
#include <stdlib.h>   /* srand, rand */
#include <time.h> 
#include <string.h>

using namespace std;
 
int menu(void);//fountion of menu
int funtions;//select funtion
void start(void);//fountion of start
void Introduction(void);//fountion of introduction
int main(void);//fountion for start funtion
int game(void);//fountion of play game
bool gamefinished = false;

//menu++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int menu(void)  //menu
{
	int functions;
	cout<<"Welcome to this GAME!\n";
    cout<<"Now select what funtion you want from these following funtions:\n";
    cout<<"1) Introduction\n";
    cout<<"2) Start GAME\n";
    cout<<"3) Exit\n";
	scanf("%d", &funtions);
		
	return funtions;
}

void start(void)
{
	int functions;
	funtions = menu();
	switch (funtions)
	{
	case 1:
		Introduction ();
		printf("\n");
		start();
		break;
	case 2:	
		game();
		break;
	case 3:
		gamefinished = true;
		break;
	}
}

//Introduction++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Introduction(void)
{
	cout<<"\nIntroduction\n";
	cout<<"\nThe standard setting: ";
	cout<<"\nThereare 14 pockets on the game board as shown in the following figure.";
	cout<<"\nThe two big pockets are called Mancala. In the beginning, each small";
	cout<<"\npocket contains 4 stones.\n";
	cout<<"(This the list of keyboard:) \n";
	cout<<"--------------------------------\n";
    cout<<"|   | 5 | 4 | 3 | 2 | 1 | 0 |   |\n";
    cout<<"| 6 |-----------------------| 13|\n";
    cout<<"|   | 7 | 8 | 9 | 10| 11| 12|   |\n";
    cout<<"--------------------------------\n";
	cout<<"(This the start of the GAME:) \n";
	cout<<"--------------------------------\n";
    cout<<"|   | 4 | 4 | 4 | 4 | 4 | 4 |   |\n";
    cout<<"| 0 |-----------------------| 0 |\n";
    cout<<"|   | 4 | 4 | 4 | 4 | 4 | 4 |   |\n";
    cout<<"--------------------------------\n";
	cout<<" The ruleof playing:";
	cout<<"\nSupposethe two players are ??and ?? They are assigned the pockets in ";
	cout<<"\nfront of them and the Mancala on their right hand side as shown in the ";
	cout<<"\nfollowing figure.Each player takes turn to select one of their empty pocket.";
	cout<<"\nThe stones in the pocket are distributed in the count-clockwise direction,";
	cout<<"\none to each pocket including the player’s Mancala (but not the opponent’s ";
	cout<<"\nMancala). For example, in the following figure, player 1 select pocket 9. ";
	cout<<"\nSo each of pocket 10, 11, 12 and Mancala 1 has one more stone. ";
	cout<<"\nThere are two special cases:\n";
	cout<<"1. The last stone falls in the player’s Mancala, such as in the following ";
	cout<<"\nexample. The player get to take another turn before the opponent.";
	cout<<"Player 2------------------------\n";
    cout<<"|   | 4 | 4 | 4 | 4 | 4 | 4 |   |\n";
    cout<<"| 0 |-----------------------| 1 |\n";
    cout<<"|   | 4 | 4 | 0 | 5 | 5 | 5 |   |\n";
    cout<<"Player 1------------------------\n";
    cout<<"\n2. The last stone falls in one of the player’s emptypocket and the opposite";
	cout<<"\nopponent’s pocket is non-empty. Then, that last stone and all the stones in";
	cout<<"\nthe opposite pocket go to the player’s Mancala. E.g., in the following figure, ";
	cout<<"\nplayer 2makes the move andgets the stones of 2 and 10 to his/her Mancala.";
	cout<<"Player 2------------------------\n";
    cout<<"|   | 6 | 8 | 8 | 1 |(1)| 0 |   |\n";
    cout<<"| 1 |-----------------------| 1 |\n";
    cout<<"|   | 0 | 1 | 1 | 8 | 7 | 6 |   |\n";
    cout<<"Player 1------------------------\n";
	cout<<"\nThe end game condition: After a player’s turn and all the player’s pockets are";
	cout<<"\nempty. Then, the opponent player gets all the stones of his/her pockets to ";
	cout<<"\nhis/her Mancala.";
	cout<<"\nThe wining criteria: ";
	cout<<"\nThe playerwins if he/she has more stones in his/her Mancala. If both players";
	cout<<"\nget the same number of stones, then it is a draw game.";

}

//Play GAME++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main()
{ 
	start ();	
}

int game()
{
	int board[14];
    void move(int board[], int pos, int turnNum);
    void update(int board[]);
    int pos;
    int player_cp;
    player_cp = rand() % 5;
    bool gamefinished = false;	// Mark the game finished
    int palyer_num;
  board[0] = 4;
  board[1] = 4;
  board[2] = 4;
  board[3] = 4;
  board[4] = 4;
  board[5] = 4;
  board[6] = 0;
  board[7] = 4;
  board[8] = 4;
  board[9] = 4;
  board[10] = 4;
  board[11] = 4;
  board[12] = 4;
  board[13] = 0;
  
  printf("Welcome to Mancala!\n");
  cout<<"Please select player number:\n";
  cout<<"1) 1 player\n";
  cout<<"2) 2 players\n";

  scanf("%d", &palyer_num);

  do
  {
    if (palyer_num == 1)
    {

	    cout<<"You select (1) 1 players\n";
        cout<<"To play select a position on the board.";
        cout<<"\n\n";
	    cout<<"This the list of keyboard: \n";
        cout<<"Player 2------------------------\n";
        cout<<"|   | 5 | 4 | 3 | 2 | 1 | 0 |   |\n";
        cout<<"| 6 |-----------------------| 13|\n";
        cout<<"|   | 7 | 8 | 9 | 10| 11| 12|   |\n";
        cout<<"Player 1------------------------\n";
	    cout<<"Let start the game! \n";
    
        int totalM = board[6] + board[13];
        int turnNum = 1;

		update(board);
        while (totalM < 48)
        {
          
          if (turnNum == 1)  //player
          {
            cout<<"\nPlayer 1: Select a postion (7 to 12): ";
            cin>> pos;
       
            if (pos >= 7 && pos <= 12)
            {
              move(board, pos, turnNum);
            }
       
            else
            {
              cout<<"Please select another position (7 to 12): ";
              cin>> pos;
            }
          }
		  update(board);
		  if (turnNum == 1)  //computer player
          {
            cout<<"\nPlayer 2: Select a postion (0 to 5): ";
		    printf("%d", player_cp);
		  
            cin>> pos;           
          }
		  update(board);
        }
    cin.get();
    return 0;
    }
    else if (palyer_num == 2)
    {
	    cout<<"You select (2) 2 players\n";
        cout<<"To play select a position on the board.";
        cout<<"\n\n";
   
        cout<<"Player 2------------------------\n";
        cout<<"|   | 5 | 4 | 3 | 2 | 1 | 0 |   |\n";
        cout<<"| 6 |-----------------------| 13|\n";
        cout<<"|   | 7 | 8 | 9 | 10| 11| 12|   |\n";
        cout<<"Player 1------------------------\n";
    
        int totalM = board[6] + board[13];
        int turnNum = 1;

        update(board);
        while (totalM < 48)
        {
          
          if (turnNum == 1)  //player 1
          {
            cout<<"\nPlayer 1: Select a postion (7 to 12): ";
            cin>> pos;
       
            if (pos >= 7 && pos <= 12)
            {
              move(board, pos, turnNum);
            }
       
            else
            {
              cout<<"Please select another position (7 to 12): ";
              cin>> pos;
            }
          }
		  update(board);
		  if (turnNum == 1)  //player 2
          {
            cout<<"\nPlayer 2: Select a postion (0 to 5): ";
            cin>> pos;
       
            if (pos >= 0 && pos <= 5)
            {
              move(board, pos, turnNum);
            }
       
            else
            {
              cout<<"Please select another position: ";
              cin>> pos;
            }
          }
		  update(board);
		  if(board[0] == 0 && board[1] == 0 && board[2] == 0 && board[3] == 0 && board[4] == 0 && board[5] == 0)
		  {		    
			printf("Player 2 winned !!!");
			gamefinished = true;
		  }
		  if(board[6] == 0 && board[7] == 0 && board[8] == 0 && board[9] == 0 && board[9] == 0 && board[10] == 0)
		  {		    
			printf("Player 1 winned !!!");
			gamefinished = true;
		  }

        }
    cin.get();
    return 0;
    }
	
  } while(palyer_num == 1 || palyer_num == 2);
  printf("please try again");
  main();
}

//GAME setting++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void move(int board[], int pos, int turnNum)
{
  int initPos = pos;
  for (int i = 0; i < board[pos] + 1; i++)
  {  
    int curPos = pos + i;
     
    if (curPos >= 14)
      curPos -= 14;
     
    else if (curPos >= 28)
      curPos -= 28;
 
    if (turnNum == 1)
    {
      int * current1 = &(board[curPos]);
      if (current1 == &(board[6]))
        current1 = &(board[7]);
      *current1 += 1;
    }    
     
    else if (turnNum == 2)
    {
      int * current2 = &(board[curPos]);
      if (current2 == &(board[13]))
        current2 = &(board[0]);
      *current2 += 1;
    }
  }
  board[initPos] = 0;
}
 

void update(int board[])
{
  cout<<"\nPlayer 2-------------------------\n";
  cout<<"|   | "<<board[5]<<" | "<<board[4]<<" | "<<board[3]<<" | "<<board[2]<<" | "<<board[1]<<" | "<<board[0]<<" |   |\n";
  cout<<"| "<<board[6]<<" |-----------------------| "<<board[13]<<" |\n";
  cout<<"|   | "<<board[7]<<" | "<<board[8]<<" | "<<board[9]<<" | "<<board[10]<<" | "<<board[11]<<" | "<<board[12]<<" |   |";
  cout<<"\nPlayer 1-------------------------\n";
}