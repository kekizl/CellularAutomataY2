
/*FILE:
 *HEADER FILE:
 *BY: CHRISTIAN ZLATANOV
 */

// function declarations
// generates the cellular automaton based on the rule given and user input given
// and stores the automaton in a Array
int generate(char aGen[], int rule, int cells, int kids_max, char storageArray[kids_max][cells]);

// creates the ruleset and applies it to create the new node
int rules(int rule, char a, char b, char c);

// takes the CA, stored as an array and prints it
int displayCA(int genLength, int kids, char aArray[kids][genLength]);

// prints the CA to a file
int printToFile(int rule, int genLength, int kids, char aArray[kids][genLength]);
