#include<stdio.h>


//this function to remplir a table with 0;
InitBoard(int tab[9][9]){
int i,j;
 for (i=0;i<9;i++){
       for (j=0;j<9;j++){
          tab[i][j]=0;
    }
    }
}


//this function is affiche the inside of the table
AffichePawn(int tab[9][9],int i,int j){
    if(tab[i][j]==0){
        printf("%c%c",176,186);
    }else if(tab[i][j]==1){
        printf(" %c",186);
    }else if(tab[i][j]==2){
        printf(" %c",186);
    }
}

//this function is to print the skullet of the table
AfficheBoard(int tab[9][9]){
//var  function
int i,j;
//initial place of the pawns


//this print is to make space for the indexation so it will align with table rows
printf("  ");
//this for is to make the indexation of the top row
    for (i=0;i<9;i++){
        printf("%d ",i+1);
    }
//this print to return to line
printf("\n");
//this print is to make the head of the table with the code ascci
printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,203,205,203,205,203,205,203,205,203,205,203,205,203,205,203,205,187);


//this for is to print the table border + the contenu of the table
    for (i=0;i<9;i++){
        //this if is to avoid printig an additional row
        if(i>0){
               printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,206,205,206,205,206,205,206,205,206,205,206,205,206,205,206,205,185);
        }
        //this print is to print the right side indexation
        printf("%d%c",i+1,186);
            //this boucle is made to display the inside of the table
            for (j=0;j<9;j++){
                AffichePawn(tab,i,j);
            }
    //this if is to return to the line after every row
    printf("\n");
    }
    //this if is to print the bottom side of the table (with assci code)
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,202,205,202,205,202,205,202,205,202,205,202,205,202,205,202,205,188);

    //this print is to make space for the indexation so it will align with table rows
    printf("  ");
    //this for is for the indexation of the bottom row
    for (i=0;i<9;i++){
        printf("%d ",i+1);
    }

}




int main(){
int board[9][9];

InitBoard(board);
AfficheBoard(board);
}
