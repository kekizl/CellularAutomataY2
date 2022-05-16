/*FILE:
 *FUNCTIONS:
 *BY: CHRISTIAN ZLATANOV
 **/

// INCLUDES
#include "2dca.h"
#include <stdlib.h>
#include <stdio.h>


int neighbour_count(int row, int col, int aGen[row][col], int r, int c){

int count = 0;

for(int i = r-1; i < r+2; i++){
	for(int j = c-1; j < c+2; j++){
		if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(aGen[i][j]==1){
                count++;
            }
	}
}
return count;
}

int printGen(int row, int col, int aGen[row][col]){
p
for(int i = 0; i < row; i++){
	printf("\n");
	for(int j = 0; j < col; j++){
		printf("%d", aGen[i][j]);
	}
}
return 0;
}
