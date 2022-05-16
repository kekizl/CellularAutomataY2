/*FILE: Conways Game of Life Simulation
 *MAIN
 *BY: CHRISTIAN ZLATANOV
 */

// INCLUDES

#include "2dca.h"
#include <stdio.h>
#include <stdlib.h>



int main() {

  int aliveNeighbours, amountOfGens, iteration = 0, row, col;

  printf("Please enter the amount of rows you want: ");
  scanf("%d", &col);
  printf("Please enter the amount of columns you want: ");
  scanf("%d", &row);
  printf("Please enter the amount of gens you want: ");
  scanf("%d", &amountOfGens);

  int firstGen[row][col], secondGen[row][col];

  //populate first gen with random numbers
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      firstGen[i][j] = rand() % 2;
    }
  }
  printf("\nFirst Generation:");
  printGen(row, col, firstGen);
  do {
    //values of next generation based on neighbouring cells
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        aliveNeighbours = countNeighbours(row, col, firstGen, i, j);
        if (firstGen[i][j] == 1 &&
            (aliveNeighbours == 2 || aliveNeighbours == 3)) {
          secondGen[i][j] = 1;
        }

        else if (firstGen[i][j] == 0 && aliveNeighbours == 3) {
          secondGen[i][j] = 1;
        }

        else {
          secondGen[i][j] = 0;
        }
      }
    }
    
    printf("\n\nNext Generation:");
    printGen(row, col, secondGen);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        firstGen[i][j] = secondGen[i][j];
      }
    }
    iteration++;
  } while (iteration != amountOfGens - 1);
  return 0;
}
