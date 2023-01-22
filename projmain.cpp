#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<windows.h>

//this is a new type named player , we can make a new player using the word "player"
struct{
int col;
int row;
int bars_numbers;
int id;
int turn;
}typedef player;


//this is to change the color of the print that come after it
BlueCyan(){
  printf("\033[1;36m");
}
Red(){
  printf("\033[1;31m");
}
Green(){
  printf("\033[1;32m");
}
//this is to change color back to black
ResetColor(){
  printf("\033[0m");
}

//this function to remplir a table with 0 ,3,and 4;
//0 is the places where the pawn can move to
//3 is the places with bars
//also the 4 is the places with bars but the pawns can t pass throught it
InitBoard(int tab[19][19]){
int i,j;
 for (i=0;i<19;i++){
       for (j=0;j<19;j++){
            tab[i][j]=0;
//the pair places(this for rows only) will have a bar in them
            if(i%2==0){
            tab[i][j]=3;
            }
//the pair places(this for colones only) will have a bar in them
            if(j%2==0){
            tab[i][j]=3;
            }
//this is to fill the cadre with 4 so the pawns can t skip it
            if(j==0 || j==18){
            tab[i][j]=4;
            }
            if(i==0 || i==18){
            tab[i][j]=4;
            }
        }
    }
}


//like it s name said ,it will affiche
AfficheBoard(int tab[19][19]){
int i,j;
 for (i=0;i<19;i++){
printf("\t\t\t\t\t\t");
       for (j=0;j<19;j++){

            if(tab[i][j]==0){
                //if the case is empty
                printf(" ");
            }else if(tab[i][j]==1){
                //if player 1 is in this case
                printf("%c",1);
            }else if(tab[i][j]==2){
                //if player 2 is in this case
                printf("%c",2);
            }else if(i==0 && j==0){
                //╔
                //if the case is 4 then change color
                if(tab[i][j]==4||tab[i][j]==5){
                    BlueCyan();
                    printf("%c",201);
                    ResetColor();
                }else printf("%c",201);
            }else if(i==0 && j==18){
                //╗
                //if the case is 4 then change color
                if(tab[i][j]==4||tab[i][j]==5){
                    BlueCyan();
                    printf("%c",187);
                    ResetColor();
                }else printf("%c",187);
            }else if(i==0 && j%2==0){
                //╦
                //if the case is 4 then change color
                if(tab[i][j]==4||tab[i][j]==5){
                    BlueCyan();
                    printf("%c",203);
                    ResetColor();
                }else printf("%c",203);
            }else if(i==18 && j==18){
                //╝
                //if the case is 4 then change color
                if(tab[i][j]==4||tab[i][j]==5){
                    BlueCyan();
                    printf("%c",188);
                    ResetColor();
                }else printf("%c",188);
            }else if(i==18 && j==0){
                //╚
                //if the case is 4 then change color
                if(tab[i][j]==4){
                    BlueCyan();
                    printf("%c",200);
                    ResetColor();
                }else if(tab[i][j]==5){
                    Green();
                    printf("%c",200);
                    ResetColor();
                }else printf("%c",200);
            }else if(i==18 && j%2==0){
                //╩
                //if the case is 4 then change color
                if(tab[i][j]==4||tab[i][j]==5){
                    BlueCyan();
                    printf("%c",202);
                    ResetColor();
                }else printf("%c",202);

            }else if(j==0 && i%2==0){
                //╠
                //if the case is 4 then change color
                if(tab[i][j]==4||tab[i][j]==5){
                    BlueCyan();
                    printf("%c",204);
                    ResetColor();
                }else printf("%c",204);
            }else if(j==18 && i%2==0){
                // ╣
                //if the case is 4 then change color
                if(tab[i][j]==4||tab[i][j]==5){
                    BlueCyan();
                    printf("%c",185);
                    ResetColor();
                }else if(tab[i][j]==5){
                    Green();
                    printf("%c",185);
                    ResetColor();
                }else printf("%c",185);
            }else if(i%2==1 && (tab[i][j] == 3 ||tab[i][j] == 4 )){
                // ║
                //if the case is 4 then change color
                if(tab[i][j]==4){
                    BlueCyan();
                    printf("%c",186);
                    ResetColor();
                }else if(tab[i][j]==5){
                    Green();
                    printf("%c",186);
                    ResetColor();
                }else printf("%c",186);
            }else if(i%2==0 && (tab[i][j] == 3 ||tab[i][j] == 4||tab[i][j]==5) && j%2==0){
                //╬
                //if the case is 4 then change color
                if(tab[i][j]==4){
                    BlueCyan();
                    printf("%c",206);
                    ResetColor();
                }else if(tab[i][j]==5){
                    Green();
                    printf("%c",206);
                    ResetColor();
                }else printf("%c",206);
            }else if(i%2==0){
                //═
                //if the case is 4 then change color
                if(tab[i][j]==4){
                    BlueCyan();
                    printf("%c",205);
                    ResetColor();
                }else if(tab[i][j]==5){
                    Green();
                    printf("%c",205);
                    ResetColor();
                }else printf("%c",205);
            }
        }
printf("\n");
    }
}

//this to initialize the game (it will reset the number of bars and the first place of the pawns
InitializePlayer(int tab[19][19],player *p1,player *p2){
//init player 1
p1->id=1;
p1->col =1;
p1->row =9;
p1->bars_numbers=10;
p1->turn=1;
//init player 2
p2->id=2;
p2->col =17;
p2->row =9;
p2->bars_numbers=10;
p2->turn=0;

//init places of pawns in the board
tab[p1->col][p1->row]=p1->id;
tab[p2->col][p2->row]=p2->id;
}

int MovePownOrBars(){
int choice=-1;
while(choice>3 || choice<0){
    printf("\n\t\t\t\t\t      to move a pawn press 1 ,\n\t\t\t\t\t to move bars horizenally press 2");
    choice = getch() - '0';
}
return choice;
}

//this function is to move pawns
MovePawns(int tab[19][19],player *p1,player *p2,int *choice){
int key;
 printf("\n\t\t\t\t\t\t player %d turn|| %d bars \n",p1->id,p1->bars_numbers);
//khbit() is a predefini function
if (kbhit()) {
    key=getch();
    if (key == 224) {
        do {
            key=getch();
        } while(key==224);
        //the asci code of the up arrow is 72 ,this if to move the pawn up             //printf("up");
        //the case should be different to 4   ([i-1][j] is the case that above the [i][j]
        if(key==72 && tab[p1->col-1][p1->row]!=4){
            //this to return the case to 0 so it will show nothing
            tab[p1->col][p1->row]=0;
            //this to make the case that above where we re now recieve 1
            tab[p1->col-2][p1->row]=p1->id;
            //this to update the player cordonate
            p1->col=p1->col-2;
            //this is to mark the end of the turn of the current player
            p1->turn=0;
            p2->turn=1;

        }else if(key==75 && tab[p1->col][p1->row-1]!=4){
            tab[p1->col][p1->row]=0;
            tab[p1->col][p1->row-2]=p1->id;
            p1->row=p1->row-2;
            p1->turn=0;
            p2->turn=1;
            //printf("left");
        }else if(key==77 && tab[p1->col][p1->row+1]!=4){
            tab[p1->col][p1->row]=0;
            tab[p1->col][p1->row+2]=p1->id;
            p1->row=p1->row+2;
            p1->turn=0;
            p2->turn=1;
            //printf("right");
        }else if(key==80 && tab[p1->col+1][p1->row]!=4){
            tab[p1->col][p1->row]=0;
            tab[p1->col+2][p1->row]=p1->id;
            p1->col=p1->col+2;
            p1->turn=0;
            p2->turn=1;
            //printf("down");
        }else printf("\n\t\t\t\t\t\t can t move pawn to a blocked path \n");
      }
    }
    *choice=0;
}

initialiser_1er_bars(int tab[19][19],int *i0,int *j0,int *i1,int *j1,int *i2,int *j2,int *i3,int *j3){
*i0=10;
*j0=10;
*i1=10;
*j1=9;
*i2=10;
*j2=8;
*i3=10;
*j3=7;
        tab[*i0][*j0]=5;
        tab[*i1][*j1]=5;
        tab[*i2][*j2]=5;
        tab[*i3][*j3]=5;
}

//this function is to move bars
MoveBarsHorizontally(int tab[19][19],player *p1,player *p2,int *i0,int *j0, int *i1,int *j1,int *i2,int *j2,int *i3,int *j3){
int key;

//khbit() is a predefini function
if (kbhit()) {
    key=getch();
    if (key == 224) {
        do {
            key=getch();
        } while(key==224);

        //the asci code of the up arrow is 72 ,this if to move the pawn up             //printf("up");
       if(key==72 && tab[*i0-2][*j0]==3&&tab[*i1-2][*j1]==3&&tab[*i2-2][*j2]==3&&tab[*i3-2][*j3]==3){
        tab[*i0][*j0]=3;
        tab[*i1][*j1]=3;
        tab[*i2][*j2]=3;
        tab[*i3][*j3]=3;
        tab[*i0-2][*j0]=5;
        tab[*i1-2][*j1]=5;
        tab[*i2-2][*j2]=5;
        tab[*i3-2][*j3]=5;
        *i0=*i0-2;
        *i1=*i1-2;
        *i2=*i2-2;
        *i3=*i3-2;

        }else if(key== 77&& tab[*i3][*j3+4]==3&&tab[*i2][*j2+4]==3&&tab[*i1][*j1+4]==3&&tab[*i0][*j0+4]==3){
        tab[*i0][*j0]=3;
        tab[*i1][*j1]=3;
        tab[*i2][*j2]=3;
        tab[*i3][*j3]=3;
        tab[*i0][*j0+4]=5;
        tab[*i1][*j1+4]=5;
        tab[*i2][*j2+4]=5;
        tab[*i3][*j3+4]=5;
        *j0=*j0+4;
        *j1=*j1+4;
        *j2=*j2+4;
        *j3=*j3+4;

        }else if(key==75 && tab[*i3][*j3-4]==3&&tab[*i2][*j2-4]==3&&tab[*i1][*j1-4]==3&&tab[*i0][*j0-4]==3){
        tab[*i0][*j0]=3;
        tab[*i1][*j1]=3;
        tab[*i2][*j2]=3;
        tab[*i3][*j3]=3;
        tab[*i0][*j0-4]=5;
        tab[*i1][*j1-4]=5;
        tab[*i2][*j2-4]=5;
        tab[*i3][*j3-4]=5;
        *j0=*j0-4;
        *j1=*j1-4;
        *j2=*j2-4;
        *j3=*j3-4;

            //printf("right");
        }else if(key==80&&tab[*i0+2][*j0]==3&&tab[*i1+2][*j1]==3&&tab[*i2+2][*j2]==3&&tab[*i3+2][*j3]==3){
        tab[*i0][*j0]=3;
        tab[*i1][*j1]=3;
        tab[*i2][*j2]=3;
        tab[*i3][*j3]=3;
        tab[*i0+2][*j0]=5;
        tab[*i1+2][*j1]=5;
        tab[*i2+2][*j2]=5;
        tab[*i3+2][*j3]=5;
        *i0=*i0+2;
        *i1=*i1+2;
        *i2=*i2+2;
        *i3=*i3+2;

            //printf("down");
        }else printf("\n\t\t\t\t\t\t  can t move pawn to a blockked path");
      }
    }
}


void check_win(player pl,int board[19][19]) {
    int p1_x, p1_y, p2_x, p2_y;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {

            if (board[i][j] == 1) {
                p1_x = i;
                p1_y = j;
            } else if (board[i][j] == 2) {
                p2_x = i;
                p2_y = j;
            }
        }
    }
    if (pl.id == 1) {
        if (p1_x == 17) {
            system("clear");
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\t\t**************\n");
            printf("\t\t\t\t\t**************\n");
            printf("\t\t\t\t\tPlayer 1 wins!\n");
            printf("\t\t\t\t\t**************\n");
            printf("\t\t\t\t\t**************\n");
            Sleep(5000);
            exit(0);
        }
    } else if (pl.id == 2) {
        if (p2_x == 1) {
            system("clear");
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\t\t**************\n");
            printf("\t\t\t\t\t**************\n");
            printf("\t\t\t\t\tPlayer 2 wins!\n");
            printf("\t\t\t\t\t**************\n");
            printf("\t\t\t\t\t**************\n");
            Sleep(5000);
            exit(0);
        }
    }
}




int main(){
//declarations
int board[19][19];
player player1;
player player2;
int i0, j0, i1, j1, i2, j2, i3, j3;
int choice;
char confirm;
//testing
int m=1;
//initiating the board with the 0,3 and 4
InitBoard(board);
//initiating the player and their places in the board
InitializePlayer(board,&player1,&player2);
        printf("\n\t\t\t\t\t      player 1 turn || %d bars  \n",player1.bars_numbers);

        AfficheBoard(board);

       while (1) {
//this khbit() is a predefinit function
            if(choice==0){
               choice=MovePownOrBars();
            }else if (kbhit()) {
//this if to switch turns between the players
            if(player1.turn==1){
                    if(choice==1){
                        system("clear");
                        MovePawns(board,&player1,&player2,&choice);
                        AfficheBoard(board);
                        check_win(player1,board);
                    } else if(choice==2 && player1.bars_numbers != 0){
                    initialiser_1er_bars(board,&i0,&j0,&i1,&j1,&i2,&j2,&i3,&j3);
                    system("clear");
                    AfficheBoard(board);
                    do{
                    if( confirm !='1') {
                    MoveBarsHorizontally(board,&player1,&player2,&i0,&j0,&i1,&j1,&i2,&j2,&i3,&j3);
                    system("clear");
                    AfficheBoard(board);
                    printf("\n \t\t\t\t press 1 to confirm");
                    printf("\n \t\t\t\t press 2 to continue");
                    confirm =getch();}
                    if( confirm =='1') {
                    board[i0][j0]=4;
                    board[i1][j1]=4;
                    board[i2][j2]=4;
                    board[i3][j3]=4;
                    player1.bars_numbers=player1.bars_numbers-1;
                    player1.turn=0;
                    player2.turn=1;
                    choice=0;
                        }
                    }while(confirm != '1');
                    }else printf("still under construction");

            }else if(player2.turn==1 && player1.turn==0){

                    if(choice==1){
                        system("clear");
                        MovePawns(board,&player2,&player1,&choice);
                        AfficheBoard(board);
                        check_win(player2,board);
                    } else if(choice==2 && player2.bars_numbers != 0){
                            initialiser_1er_bars(board,&i0,&j0,&i1,&j1,&i2,&j2,&i3,&j3);
                            system("clear");
                            AfficheBoard(board);
                            do{
                                if( confirm !='1') {
                                    MoveBarsHorizontally(board,&player2,&player1,&i0,&j0,&i1,&j1,&i2,&j2,&i3,&j3);
                                    system("clear");
                                    AfficheBoard(board);
                                    printf("\n \t\t\t\t press 1 to confirm");
                                    printf("\n \t\t\t\t press 2 to continue");
                                    confirm =getch();}
                                if( confirm =='1') {
                                    board[i0][j0]=4;
                                    board[i1][j1]=4;
                                    board[i2][j2]=4;
                                    board[i3][j3]=4;
                                    player2.bars_numbers=player2.bars_numbers-1;
                                    player2.turn=0;
                                    player1.turn=1;
                                    choice=0;
                                    }
                            }while(confirm != '1');
                            }else printf("still under construction");
            }

        }
    }

}
