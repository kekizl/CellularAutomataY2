/*FILE:
 *TESTER FOR CELLULAR AUTOMATON
 *BY: CHRISTIAN ZLATANOV
 */

// INCLUDES

#include "2dca.h"
#include <stdio.h>
#include <stdlib.h>

int row;
int col;

int main(){
        int neighbour_live_cell, amountOfGens, iteration = 0;    


	printf("Please enter the amount of rows you want: ");
        scanf("%d", &col);
	printf("Please enter the amount of columns you want: ");
        scanf("%d", &row);
	printf("Please enter the amount of gens you want: ");
	scanf("%d", &amountOfGens);
	
	int firstGen[row][col], secondGen[row][col];

	for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            firstGen[i][j] = rand() % 2;
        }
    }
	printGen(row, col, firstGen);
do{
	//next canvas values based on live neighbour count
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            neighbour_live_cell = neighbour_count(row, col, firstGen,i,j);
            if(firstGen[i][j]==1 && (neighbour_live_cell==2 || neighbour_live_cell==3)){
                secondGen[i][j]=1;
            }
 
            else if(firstGen[i][j]==0 && neighbour_live_cell==3){
                secondGen[i][j]=1;
            }
 
            else{
                secondGen[i][j]=0;
            }
        }
    }
    printf("\n\n");
    printGen(row, col, secondGen);

    for(int i=0; i<row; i++){
	for(int j =0; j<col; j++){
	firstGen[i][j] = secondGen[i][j];
	}
    }
    iteration++;
}while(iteration != amountOfGens -1);
return 0;
}
