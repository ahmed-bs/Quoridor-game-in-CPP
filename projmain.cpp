#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<windows.h>

//this is a new type named player
struct {
int col;
int row;
int bars_numbers;
int id;
int turn;
}typedef player;



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
                printf("%c",201);
            }else if(i==0 && j==18){
                //╗
                printf("%c",187);
            }else if(i==0 && j%2==0){
                //╦
                printf("%c",203);
            }else if(i==18 && j==18){
                //╝
                printf("%c",188);
            }else if(i==18 && j==0){
                //╚
                printf("%c",200);
            }else if(i==18 && j%2==0){
                //╩
                printf("%c",202);
            }else if(j==0 && i%2==0){
                //╠
                printf("%c",204);
            }else if(j==18 && i%2==0){
                // ╣
                printf("%c",185);
            }else if(i%2==1 && (tab[i][j] == 3 ||tab[i][j] == 4 )){
                // ║
                printf("%c",186);
            }else if(i%2==0 && (tab[i][j] == 3 ||tab[i][j] == 4 ) && j%2==0){
                //╬
                printf("%c",206);
            }else if(i%2==0){
                //═
                printf("%c",205);
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
p1->turn=0;
//init player 2
p2->id=2;
p2->col =17;
p2->row =9;
p2->bars_numbers=10;
p2->turn=1;

//init places of pawns in the board
tab[p1->col][p1->row]=p1->id;
tab[p2->col][p2->row]=p2->id;
}





//this function is to move pawns
//this function is to move pawns
MovePawns(int tab[19][19],player *p1,player *p2){
int key;
//khbit() is a predefini function
if (kbhit()) {
    key=getch();
    if (key == 224) {
        do {
            key=getch();
        } while(key==224);
        if(key==72 && tab[p1->col-1][p1->row]!=4){
            tab[p1->col][p1->row]=0;
            tab[p1->col-2][p1->row]=p1->id;
            p1->col=p1->col-2;

            p1->turn=0;
            p2->turn=1;
            //printf("up");
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
        }else printf("can t move pawn to a blockked path");
      }
    }
system("clear");

}





int main(){
//declarations
int board[19][19];
player player1;
player player2;
//testing
int m=1;
int i2=17,k2=9;
int i=1,k=9;
//tab[1][9]=p1.id;
//tab[17][9]=p2.id;
//initiating the board with the 0,3 and 4
InitBoard(board);
//initiating the player and their places in the board
InitializePlayer(board,&player1,&player2);

AfficheBoard(board);

       while (1) {
//this khbit() is a predefinit function
        if (kbhit()) {
//this if to switch turns between the players
            if(player1.turn==1){
                MovePawns(board,&player1,&player2);
                AfficheBoard(board);
            }else if(player2.turn==1){
                MovePawns(board,&player2,&player1);
                AfficheBoard(board);
            }

        }
    }

}
