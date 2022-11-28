#include<stdio.h>

int main(){

int board[9][9];
int i,j;
printf("  ");
for (i=0;i<9;i++){
        printf("%d ",i+1);
}
 printf("\n");
     printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,203,205,203,205,203,205,203,205,203,205,203,205,203,205,203,205,187);
for (i=0;i<9;i++){
if(i>0){
     printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,206,205,206,205,206,205,206,205,206,205,206,205,206,205,206,205,185);
}
     printf("%d%c",i+1,186);
    for (j=0;j<9;j++){
            board[i][j]=0;
        printf("%c%c",2,186);
    }
    printf("\n");
}
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,202,205,202,205,202,205,202,205,202,205,202,205,202,205,202,205,188);

printf("  ");
for (i=0;i<9;i++){
        printf("%d ",i+1);
}



}
