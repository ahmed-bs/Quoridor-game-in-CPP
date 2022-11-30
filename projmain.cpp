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
        printf("%c%c",1,186);
    }else if(tab[i][j]==2){
        printf("%c%c",2,186);
    }
}



//this function is to fill the table with ascci caracter that will make the border rows of the main table

InitBorderRows(int tab2[19][19]){
    int i,j;
    for (i=0;i<19;i++){
        for (j=0;j<19;j++){
            if(i==0 && j==0){
                tab2[i][j] = 201;
            }else if(i==0 && j==18){
                tab2[i][j] = 187;
            }else if(i==0 && j%2==0){
                tab2[i][j] = 203;
            }else if(i==0 && j%2==1){
                tab2[i][j] = 205;
            }else if(j==0){
                tab2[i][j] = 204;
            }else if(j==18){
                tab2[i][j] = 185;
            }else if(j%2==0){
                tab2[i][j]=206;
            }else{tab2[i][j]=205;
            }
        }
    }
}



//this function is to print the skullet of the table
AfficheBoard(int tab[9][9]){
//var  function
int i,j,k;
//initial place of the pawns

int borderRows[19][19];
InitBorderRows(borderRows);
//this print is to make space for the indexation so it will align with table rows
printf("  ");
//this for is to make the indexation of the top row
    for (i=0;i<9;i++){
        printf("%d ",i+1);
    }
//this print to return to line
printf("\n");

//this for is to print the table border + the contenu of the table
    for (i=0;i<9;i++){
        //this if is to avoid printig an additional row
      printf(" ");
      for(k=0;k<19;k++){ printf("%c",borderRows[i][k]);}
       printf("\n");
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
int borderRows[19][19];
InitBoard(board);
int i,j;
board[0][4]=1;
board[8][4]=2;
AfficheBoard(board);




}
