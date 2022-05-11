/*FILE:
 *TESTER FOR CELLULAR AUTOMATON
 *BY: CHRISTIAN ZLATANOV
 */

// INCLUDES
#include "1dca.h"
#include <stdio.h>
/*
 *Basic main funcion. runs some tests on the program
 */

int main() {
  int ruleForCA = 30, cellsAmount = 10, kidsAmount = 10;
  int temp;

  do {
    printf("Please enter the number of the rule you want: ");
    scanf("%d", &ruleForCA);
  } while ((ruleForCA > 0 && ruleForCA < 256) != 1);

  printf("Please enter the number of cells you want: ");
  scanf("%d", &cellsAmount);

  printf("Please enter the number of generations you want: ");
  scanf("%d", &kidsAmount);

  // populate the first generation
  int gen[cellsAmount];
  for (int i = 0; i < cellsAmount; i++) {
    gen[i] = 0;
  }
  gen[cellsAmount / 2] = 1;
  gen[cellsAmount / 2] = 1;
  gen[3] = 1;

  int caArray[cellsAmount][kidsAmount];

  generate(gen, ruleForCA, cellsAmount, kidsAmount, caArray);

  displayCA(cellsAmount, kidsAmount, caArray);

  // call printToFile function if user chooses to do so
  printf("\n\nWould you like to print the output to a file?\nPlease enter 1 "
         "for YES, 0 for NO:");
  scanf("%d", &temp);
  if (temp == 1) {
    printToFile(ruleForCA, cellsAmount, kidsAmount, caArray);
  }

  return 0;
}
