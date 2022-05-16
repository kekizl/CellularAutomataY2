/*FILE: Conway's Game of Life Simulation
 *FUNCTIONS:
 *BY: CHRISTIAN ZLATANOV
 **/

// INCLUDES
#include "2dca.h"
#include <stdio.h>
#include <stdlib.h>

//count the amount of neighbours a cell has
int countNeighbours(int row, int col, int aGen[row][col], int r, int c) {

  int alive = 0;
//iterate through neighbouring cells
//code adapted from https://www.geeksforgeeks.org/program-for-conways-game-of-life
  for (int i = r - 1; i < r + 2; i++) {
    for (int j = c - 1; j < c + 2; j++) {
      if ((i == r && j == c) || (i < 0 || j < 0) || (i >= row || j >= col)) {
        continue;
      }
      if (aGen[i][j] == 1) {

        alive++;
      }
    }
  }
  return alive;
}

//print the next generation
int printGen(int row, int col, int aGen[row][col]) {
  for (int i = 0; i < row; i++) {
    printf("\n");
    for (int j = 0; j < col; j++) {
      printf("%d", aGen[i][j]);
    }
  }
  return 0;
}
