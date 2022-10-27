#include<stdio.h>
#include <graphics.h>
// to make table 
int make_tab(int tab[][9]){
		int i,j;
		for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				tab[i][j]=0;
			}
		}
}
int affiche_table(int tab[][9]){
	int i,j;
	printf("  ");
	for (j=0;j<9;j++){
			printf(" %d",j+1);
		}
	for (i=0;i<9;i++){
		printf("\n %d|",i+1);
		for (j=0;j<9;j++){
			if(tab[i][j]==0){
				printf(" |");
			}else{
				printf("%d|",tab[i][j]);
			}	
		}
		printf("\n");
		
	}
}
int main(){
	int board[9][9];

	make_tab(board);
		board[0][0]=2;
		board[0][5]=2;
		board[7][5]=2;
	affiche_table(board);
}
