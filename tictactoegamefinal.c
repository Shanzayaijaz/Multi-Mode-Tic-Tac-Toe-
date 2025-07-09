#include<stdio.h>
#include<windows.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
int i;
int checkForWin(char *a);
void boardn(char x, char o, char *u1, char *u2, char *a);
int decision(char *x, char *o, char *u1);
void gotoxy(int x, int y);
void load();
int checkForWintri(char *b);
void boardtri(char x, char y, char z, char *u1, char *u2,char *u3, char *b);
int decisiontri(char *x, char *y,char *z, char *u1);
int isBoardFull(char a[]);
void displayBoardai(char *u1, char *u2, char a[]);
int checkForWinai(char board[]);
int isBoardFullai(char board[]);
int playerMoveai(char board[]);
int aiMove(char board[]);
void printScoreboard();
void updateScoreboardtri(char *u1, char *u2, char *u3, int score, int player);
void updateScoreboardAi(char *winner, char *loser);


void updateScoreboardAi(char *winner, char *loser) {
    FILE *p;
  p = fopen("scoreboard.txt", "a+");
    fprintf(p, "\n%s winner , %s loser\n", winner, loser);
    fclose(p);
}

void updateScoreboardtri(char *u1, char *u2, char *u3, int score, int player) {
    FILE *p = fopen("scoreboard.txt", "a+");
    if (p == NULL) {
        printf("Error opening the scoreboard file.\n");
        return;
    }

    if (score == 1) {
        if (player % 3 == 0) {
           
            fprintf(p, "\nPlayer1 %s wins\n", u1);
        } else if (player % 3 == 1) {
          
            fprintf(p, "\nPlayer2 %s wins\n", u2);
        } else {
           
            fprintf(p, "\nPlayer3 %s wins\n", u3);
        }
    } else {
        printf("\n\nGame Draws!\n\n");
        fprintf(p, "Game Draw\n","draw");
    }

    fclose(p);
}
void printScoreboard() {
    FILE *p = fopen("scoreboard.txt", "a+");
    if (p != NULL) {
        char line[100];
        printf("Scoreboard:\n");
        while (fgets(line, sizeof(line), p) != NULL) {
            printf("%s", line);
        }
        fclose(p);
    } else {
        printf("Error opening scoreboard file.\n");
    }
}


int isBoardFull(char a[]) {
    int i;
    for (i = 0; i < 9; i++) {
        if (a[i] == ' ')
            return 0;
    }
    return 1;
}

int checkforwintri(char *b)
{
    if ((b[0] == b[1] && b[1] == b[2] && b[2] == b[3]) ||
    (b[4] == b[5] && b[5] == b[6] && b[6] == b[7]) ||
    (b[8] == b[9] && b[9] == b[10] && b[10] == b[11]) ||
    (b[12] == b[13] && b[13] == b[14] && b[14] == b[15]) ||
    (b[0] == b[4] && b[4] == b[8] && b[8] == b[12]) ||
    (b[1] == b[5] && b[5] == b[9] && b[9] == b[13]) ||
    (b[2] == b[6] && b[6] == b[10] && b[10] == b[14]) ||
    (b[3] == b[7] && b[7] == b[11] && b[11] == b[15]) ||
    (b[0] == b[5] && b[5] == b[10] && b[10] == b[15]) ||
    (b[3] == b[6] && b[6] == b[9] && b[9] == b[12])) {
    return 1;
}
else if (b[0] != 'a' && b[1] != 'b' && b[2] != 'c' && b[3] != 'd' && b[4] != 'e' && b[5] != 'f' && b[6] != 'g' && b[7] != 'h' && b[8] != 'i' && b[9] != 'j' && b[10] != 'k' && b[11] != 'l' && b[12] != 'm' && b[13] != 'n' && b[14] != 'o' && b[15] != 'p')
    return 0;
else
    return -1;
}

void boardtri(char x, char y, char z, char *u1, char *u2, char *u3, char *b)
{
    int i;
        system("cls");
    printf("\tTic-Tac-Toe\n\n");
        printf("\n\n");
        printf("%s:- (%c)\n%s:-  (%c)\n%s:-  (%c)\n\n\n",u1,x,u2,y,u3,z);

       printf("    %c |  %c | %c  | %c\n", b[0], b[1], b[2], b[3]);
printf("      |    |    |    \n");
printf("------|----|----|----\n");
printf("      |    |    |    \n");
printf("    %c |  %c | %c  | %c\n", b[4], b[5], b[6], b[7]);
printf("      |    |    |    \n");
printf("------|----|----|----\n");
printf("    %c |  %c | %c  | %c\n", b[8], b[9], b[10], b[11]);
printf("      |    |    |    \n");
printf("------|----|----|----\n");
printf("    %c |  %c | %c  | %c\n", b[12], b[13], b[14], b[15]);
printf("      |    |    |    \n");

        
    }
int decisiontri(char *x, char *y, char *z, char *u1)
{
    char dec;
    printf("\n\n");
    do {
        printf("Player1 %s choose x or o or z: ", u1);
        scanf(" %c",&dec);
    } while (dec != 'x' && dec != 'y' && dec !='z');

    if ( dec == 'x') {
        *x = 'X';
        *y = 'Y';
        *z='Z';
    } else if(dec=='y') {
        *x = 'Y';
        *y = 'X';
        *z='Z';
    }
    else if(dec=='z'){
    	*x = 'Z';
        *y = 'X';
        *z='Y';
	}
    return 1;
}


void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void load()
{
    int row,col,r,c,q;
    system("COLOR F5");
        gotoxy(50,14);

    printf("loading..");
    gotoxy(49,15);
    for(r=1; r<=12; r++)
    {
    	Beep(1300,200);
    	Beep(1700,200);
    	
        printf("%c",177);

    }
     gotoxy(45,20);
    printf("press enter to continue");
   
getch();
system("cls");

}
int checkForWin(char *a)
{
    if(a[0]==a[1] && a[1]==a[2])
        return 1;
    else if(a[3]==a[4] && a[4]==a[5])
        return 1;
    else if(a[6]==a[7] && a[7]==a[8])
        return 1;
    else if(a[0]==a[3] && a[3]==a[6])
        return 1;
    else if(a[1]==a[4] && a[4]==a[7])
        return 1;
    else if(a[2]==a[5] && a[5]==a[8])
        return 1;
    else if(a[0]==a[4] && a[4]==a[8])
        return 1;
    else if(a[2]==a[4] && a[4]==a[6])
        return 1;
    else if(a[0]!='1' && a[1]!='2' && a[2]!='3' && a[3]!='4' && a[4]!='5' && a[5]!='6' && a[6]!='7' && a[7]!='8' && a[8]!='9')
        return 0;
    else
        return -1;
}
void boardn(char x, char o, char *u1, char *u2, char *a)
{
    int i;
        system("cls");
    printf("\tTic-Tac-Toe\n\n");
        printf("\n\n");
        printf("%s:- (%c)\n%s:-  (%c)\n\n\n",u1,x,u2,o);

        printf("  %c |  %c | %c\n",a[0],a[1],a[2]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("    |    |    \n");
        printf("  %c |  %c | %c\n",a[3],a[4],a[5]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("  %c |  %c | %c\n",a[6],a[7],a[8]);
        printf("    |    |    \n");
    }
int decision(char *x, char *o, char *u1)
{
    char dec;
    printf("\n\n");
    do {
        printf("Player1 %s choose x or o: ", u1);
        scanf(" %c",&dec);
    } while (dec != 'x' && dec != 'o');

    if ( dec == 'x') {
        *x = 'X';
        *o = 'O';
    } else {
        *x = 'O';
        *o = 'X';
    }
    return 1;
}



void displayBoardai(char *u1, char *u2, char a[]) {
    system("cls");
    printf("\tTic-Tac-Toe\n\n");
    printf("\n\n");
    printf("%s:- (X)\n%s:- (O)\n\n\n", u1, u2);

    printf("  %c | %c | %c\n", a[0], a[1], a[2]);
    printf("    |   |    \n");
    printf("-----------\n");
    printf("    |   |    \n");
    printf("  %c | %c | %c\n", a[3], a[4], a[5]);
    printf("    |   |    \n");
    printf("-----------\n");
    printf("    |   |    \n");
    printf("  %c | %c | %c\n", a[6], a[7], a[8]);
    printf("    |   |    \n");
}

int checkForWinai(char board[9]) {
 
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ') {
        return 1;
    }
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') {
        return 1;
    }
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ') {
        return 1;
    }
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ') {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ') {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ') {
        return 1;
    }
    if (board[0] == board[4] && board[4] == board[8]&& board[0] != ' ') {
        return 1;
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
        return 1;
    }
    return 0;
}

int isBoardFullai(char board[9]) {
    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return 0;
        }
    }
    return 1;
}

int playerMoveai(char board[9]) {
    int move;
    while (1) {
        printf("\nEnter your move (1-9): ");
        scanf("%d", &move);
        if (move >= 1 && move <= 9 && board[move - 1] == ' ') {
            break;
        }
        printf("\nInvalid move. Please try again.\n");
    }
    return move - 1;
}

int tryWinOrBlock(char board[9], char player, int index) {
    if (index >= 9) return -1;

    if (board[index] == ' ') {
        board[index] = player;
        if (checkForWinai(board)) {
            board[index] = ' ';
            return index;
        }
        board[index] = ' ';
    }

    return tryWinOrBlock(board, player, index + 1);
}

int fillEmptySpots(char board[9], int emptySpots[9], int index, int count) {
    if (index >= 9) return count;

    if (board[index] == ' ') {
        emptySpots[count] = index;
        return fillEmptySpots(board, emptySpots, index + 1, count + 1);
    }

    return fillEmptySpots(board, emptySpots, index + 1, count);
}

int aiMove(char board[9]) {
    
    int winMove = tryWinOrBlock(board, 'O', 0);
    if (winMove != -1) return winMove;

    int blockMove = tryWinOrBlock(board, 'X', 0);
    if (blockMove != -1) return blockMove;

    int emptySpots[9];
    int total = fillEmptySpots(board, emptySpots, 0, 0);
    if (total > 0) {
        int randIndex = rand() % total;
        return emptySpots[randIndex];
    }

    return -1; 
}


int main(){
    system("COLOR F5");
	gotoxy(45,14);
	printf("WELCOME TO THE TIC TAC TOE GAME");
		gotoxy(48,16);
		printf("Press any key to start");
		getch();
		system("cls");
		

	load();

    char x,o;
    char a[9]={'1','2','3','4','5','6','7','8','9'};
    char u1[50],u2[50]; 
    int player=1;
    int choice,score=-1;
    char symbol;
    char start;
    int select;
    int flag;
    do{
    printf("\n\n1. Two player Tic Tac Toe.(the winner will play against AI)\n2. Three-player game with 4x4 board.\n3. Tic Tac Toe with AI.\n4. Scoreboard. \n");
    scanf("%d",&select);
    if(select==1){
    	do {
    	        printf("\nEnter name of player1: ");
                scanf("%s",u1);
                printf("Enter name of player2: ");
                scanf("%s",u2);
             !strcmp(u1,u2) ? printf("Enter names of different players!\n\n") : FALSE;
            } while(!strcmp(u1,u2));
            
            decision(&x, &o, u1);
            boardn(x,o, u1, u2, a);
             do {
                player=((player%2)?1:2);
                symbol=((player==1)?x:o);
                if(player==1)
                    printf("\n%s Type any digit from 1-9 to fill your response:- ",u1);
                else
                    printf("\n%s Type any digit from 1-9 to fill your response:- ",u2);
                scanf("%d",&choice);
                  if(choice==1 && a[0]=='1')
                    a[0]=symbol;
                else if(choice==2 && a[1]=='2')
                    a[1]=symbol;
                else if(choice==3 && a[2]=='3')
                    a[2]=symbol;
                else if(choice==4 && a[3]=='4')
                    a[3]=symbol;
                else if(choice==5 && a[4]=='5')
                    a[4]=symbol;
                else if(choice==6 && a[5]=='6')
                    a[5]=symbol;
                else if(choice==7 && a[6]=='7')
                    a[6]=symbol;
                else if(choice==8 && a[7]=='8')
                    a[7]=symbol;
                else if(choice==9 && a[8]=='9')
                    a[8]=symbol;
                    
                else {
                        printf("Wrong Selection\n");
                        player--;
                }
            
                score=checkForWin(a);
                player++;
                boardn(x, o, u1, u2, a);
            } while(score == -1);
                 if(score==1) {
                if(player==2){
                    printf("\n\nPlayer1 %s Wins!\n\n",u1);
                    
                    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char u2[] = "AI";
    char playerSymbol, aiSymbol;
    int move, win;
    srand(time(0));

    printf("\n Now player %s will have a match with AI ",u1);
    printf("\n Press enter to start playing");
    getch();

     system("COLOR B0");


     while (1) {
        
        displayBoardai(u1, u2, board);
        move = playerMoveai(board);
        board[move] = 'X';

        win = checkForWinai(board);
        if (win) {
            printf("\nHooray! %s has won the game!\n\n",u1);
            updateScoreboardAi(u1,u2);
            break;
        }
        if (isBoardFullai(board)) {
        
            displayBoardai(u1, u2, board);
            printf("\nIt's a tie!!!\n\n");
            break;
        }

        move = aiMove(board);
        if (move != -1) {
            board[move] = 'O';
            displayBoardai(u1, u2, board);
        }

        win = checkForWinai(board);
        if (win) {
            printf("\n You've lost the game... \n\n");
            updateScoreboardAi(u2,u1);
            break;
        }
        if (isBoardFullai(board)) {
            displayBoardai(u1, u2, board);
            printf("\nIt's a tie!!!\n\n");
            break;
        }
    }
    }
                else {
                    printf("\n\nPlayer2 %s Wins!\n\n",u2);
                    strcpy(u1,u2);
                    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
                    
    char u2[] = "AI";
    char playerSymbol, aiSymbol;
    int move, win;
    srand(time(0));

    printf("\n Now player %s will have a match with AI ",u1);
    printf("\n Press enter to start playing");
    
    getch();

     system("COLOR B0");

     while (1) {
        
        displayBoardai(u1, u2, board);
        move = playerMoveai(board);
        board[move] = 'X';

        win = checkForWinai(board);
        if (win) {
        
            printf("\nHooray! %s have won the game!\n\n",u1);
            updateScoreboardAi(u1,u2);
            break;
        }
        if (isBoardFullai(board)) {
            displayBoardai(u1, u2, board);
            printf("\nIt's a tie!!!\n\n");
            break;
        }

        move = aiMove(board);
        if (move != -1) {
            board[move] = 'O';
            displayBoardai(u1, u2, board);
        }

        win = checkForWinai(board);
        if (win) {
        printf("\n You've lost the game... \n\n");
        updateScoreboardAi(u2,u1);
            break;
        }
        if (isBoardFullai(board)) {
            displayBoardai(u1, u2, board);
            printf("\nIt's a tie!!!\n\n");
            break;
        }
    }
   
                }
            }
            else {
                printf("\n\nGame Draws!\n\n");
            }
             system("COLOR F5");
            printf("\n Press 1 to go back to choice menu else press 0 : ");
        scanf("%d",&flag);
        system("cls");
       
       }
       
       else if(select==2){
       	char y,z;
       	char choicet;
    char b[16]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
    char u3[50]; 
     score=-1;
    FILE *p;
            p=fopen("game.txt","a+");


                printf("\nEnter name of player1: ");
                scanf("%s",u1);
                printf("Enter name of player2: ");
                scanf("%s",u2);
                printf("Enter name of player3: ");
                scanf("%s",u3);
                

            decisiontri(&x, &y, &z, u1);
            boardtri(x,y,z, u1, u2,u3, b);
            player=0;
             do {
             	player=player%3;
				 if(player==0){
				 	symbol=x;
				 } 
				 else if(player==1){
				 	symbol=y;
				 }
				  else if(player==2){
				 	symbol=z;
				 }
             	

        printf("\nPlayer %d, type any character a-p to fill your response: ", player + 1);
        scanf(" %c", &choicet);

         if(choicet=='a' && b[0]=='a')
                    b[0]=symbol;
                else if(choicet=='b' && b[1]=='b')
                    b[1]=symbol;
                else if(choicet=='c' && b[2]=='c')
                    b[2]=symbol;
                else if(choicet=='d' && b[3]=='d')
                    b[3]=symbol;
                else if(choicet=='e' && b[4]=='e')
                    b[4]=symbol;
                else if(choicet=='f' && b[5]=='f')
                    b[5]=symbol;
                else if(choicet=='g' && b[6]=='g')
                    b[6]=symbol;
                else if(choicet=='h' && b[7]=='h')
                    b[7]=symbol;
                else if(choicet=='i' && b[8]=='i')
                    b[8]=symbol;
                else if(choicet=='j' && b[9]=='j')
                    b[9]=symbol;
                else if(choicet=='k' && b[10]=='k')
                    b[10]=symbol;
                else if(choicet=='l' && b[11]=='l')
                    b[11]=symbol;
                else if(choicet=='m' && b[12]=='m')
                    b[12]=symbol;
                else if(choicet=='n' && b[13]=='n')
                    b[13]=symbol;
                else if(choicet=='o' && b[14]=='o')
                    b[14]=symbol;
                else if(choicet=='p' && b[15]=='p')
                    b[15]=symbol;
                else {
                        printf("Wrong Selection\n");
                        player--;
                }
            
    
                score=checkforwintri(b);
                player++;
                boardtri(x, y, z, u1, u2, u3, b);
            } while(score == -1);
                 if(score==1) {
                player--;
                updateScoreboardtri(u1, u2, u3, score, player);
                	fclose(p);
                if (player % 3 == 0) {
        printf("\n\nPlayer1 %s Wins!\n\n", u1);
    
    } else if (player % 3 == 1) {
        printf("\n\nPlayer2 %s Wins!\n\n", u2);
      
    } else {
        printf("\n\nPlayer3 %s Wins!\n\n", u3);
   
    }}
            else {
            printf("\n\nGame Draws!\n\n");
			updateScoreboardtri(u1, u2, u3, score, player);
			}
        printf("\n Press 1 to go back to choice menu else press 0 : ");
        scanf("%d",&flag);
        system("cls");
       
       }
       else if(select==3){

 char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char u1[50], u2[] = "AI";
    char playerSymbol, aiSymbol;
    int move, win;
    srand(time(0));

    printf("\nEnter name of player: ");
    scanf("%s", u1);


     while (1) {
        
        displayBoardai(u1, u2, board);
           move = playerMoveai(board);
        board[move] = 'X';
        

        win = checkForWinai(board);
        if (win) {
            printf("\nHooray! %s have won the game!\n\n",u1);
             updateScoreboardAi(u1,u2);
            break;
        }
        if (isBoardFullai(board)) {
            displayBoardai(u1, u2, board);
            printf("\nIt's a tie!!!\n\n");
           
            break;
        }

        move = aiMove(board);
        if (move != -1) {
        	board[move] = 'O';
            displayBoardai(u1, u2, board);
    
           
        }

        win = checkForWinai(board);
        if (win) {
            printf("\n You've lost the game... \n\n");
              updateScoreboardAi(u2,u1);
          break;
        }
        if (isBoardFullai(board)) {
            displayBoardai(u1, u2, board);
            printf("\nIt's a tie!!!\n\n");
            break;
        }
        
    }
   printf("\nPress 1 to go back to choice menu else press 0 : ");
        scanf("%d",&flag);
        system("cls");
}

else if(select==4){
system("cls");
    printScoreboard();
		printf("\nPress 1 to go back to choice menu else press 0 : ");
        scanf("%d",&flag);
        system("cls");
	
}
}
while(flag==1);

}

