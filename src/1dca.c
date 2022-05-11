/*FILE:
 *FUNCTIONS:
 *BY: CHRISTIAN ZLATANOV
 **/

// INCLUDES
#include "1dca.h" //header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// array where ruleset will be generated into
int ruleArr[8] = {0, 0, 0, 0, 0, 0, 0, 0};

/*
 *Generates new generations up to the amount of kids_max.
 *Saves the new generations in a 2d array so we can print the CA later.
 **/
int generate(int aGen[], int rule, int cells, int kids_max, int storageArray[kids_max][cells]) {

  // input validation
  if (aGen == NULL || cells < 1 || kids_max < 1) {
    return -1;
  }
  // variable declaration
  int i;
  int nextgen[cells]; // create an array for the next gen
  int kids = 0;       // variable for the amount of generations

  do {
    // iterate through the first generation
    for (i = 0; i < cells; i++) {

      // set integers variables based on the neighbourhood of i
      // if its in the very first column
      if (i == 0) {
        int left = aGen[cells - 1];
        int middle = aGen[i];
        int right = aGen[i + 1];

        nextgen[i] = rules(rule, left, middle, right);
      }

      // if its in the last column
      else if (i == cells - 1) {
        int left = aGen[i - 1];
        int middle = aGen[i];
        int right = aGen[0];

        nextgen[i] = rules(rule, left, middle, right);

      }

      else {
        // set integers variables based on the neighbourhood of i
        int left = aGen[i - 1];
        int middle = aGen[i];
        int right = aGen[i + 1];
        nextgen[i] = rules(rule, left, middle, right);
      }
      // copy row to the storage array
      storageArray[kids][i] = aGen[i];
    }

    // iterate through both arrays and set aGen to be the new Gen
    for (i = 0; i < cells; i++) {
      aGen[i] = nextgen[i];
    }

    // increment kids
    kids++;

  } while (kids <
           kids_max - 1); // do while loop keeps on going until kids_max rows

  for (i = 0; i < cells; i++) {
    // put the final generation into the storage array as well
    storageArray[kids][i] = nextgen[i];
  }
  return 0;
}

/*
 *Function looks at the neigbourhood(a, b, c)
 *applies Rule 30 and returns a valid integer to
 *what the new integer should be accoording to our array.
 */
int rules(int rule, int a, int b, int c) {

  if (a > 1 || b > 1 || c > 1) {
    return -1;
  }

  // default array to keep the ruleset
  int ruleset_to_make[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  // loop to convert the decimal into binary
  for (int i = 0; rule > 0; i++) {
    // Mod of 2 on the rule and save the remained on an array
    ruleset_to_make[i] = rule % 2;
    // Divide rule by 2, leaving us with the lower number if its divided by 2
    rule = rule / 2;
  }

  // Reverse the array from the above for loop to make the binary we need for
  // the ruleset.
  int index = 7;
  for (int i = 0; i < 8; i++) {
    ruleArr[index] = ruleset_to_make[i];
    index--;
  }

  // neighborhood in the condition, returns child
  if (a == 1 && b == 1 && c == 1)
    return ruleArr[0];
  else if (a == 1 && b == 1 && c == 0)
    return ruleArr[1];
  else if (a == 1 && b == 0 && c == 1)
    return ruleArr[2];
  else if (a == 1 && b == 0 && c == 0)
    return ruleArr[3];
  else if (a == 0 && b == 1 && c == 1)
    return ruleArr[4];
  else if (a == 0 && b == 1 && c == 0)
    return ruleArr[5];
  else if (a == 0 && b == 0 && c == 1)
    return ruleArr[6];
  else if (a == 0 && b == 0 && c == 0)
    return ruleArr[7];
  else
    return 0;
}

// takes the CA (stored as an array) and prints it.
int displayCA(int genLength, int kids, int aArray[kids][genLength]) {

  if (aArray == NULL) {
    return -1;
  }
  // intiates variables used in loops
  int i, j;

  for (i = 0; i < kids; i++) {
    printf("\n");

    for (j = 0; j < genLength; j++) {
      // prints each value in the array(Generated CA)
      printf("%d", aArray[i][j]);
    }
  }

  return 0;
}

int printToFile(int rule, int genLength, int kids,
                int aArray[kids][genLength]) {
  if (aArray == NULL) {
    return -1;
  }
  // open file and initialize variables for the loops
  FILE *f = fopen("test.txt", "w");
  int i, j;

  time_t t;
  time(&t);

  // prints information about the CA to the file for viewing
  fprintf(f, "CA was generated using rule: %d\n", rule);
  fprintf(f, "CA has a size of %dx%d\n", kids, genLength);
  fprintf(f, "Generated at: %s\n\n", ctime(&t));

  for (i = 0; i < kids; i++) {
    fprintf(f, "\n");
    for (j = 0; j < genLength; j++) {
      // prints each value in the array(Generated CA)
      fprintf(f, "%d", aArray[i][j]);
    }
  }
  fclose(f);
  return 0;
}
