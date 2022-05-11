
/*FILE:
 *HEADER FILE:
 *BY: CHRISTIAN ZLATANOV
 */

// function declarations
// generates the cellular automaton based on the rule given and user input given
// and stores the automaton in a Array
int generate(int aGen[], int rule, int cells, int kids_max, int storageArray[kids_max][cells]);

// creates the ruleset and applies it to create the new node
int rules(int rule, int a, int b, int c);

// takes the CA, stored as an array and prints it
int displayCA(int genLength, int kids, int aArray[kids][genLength]);

// prints the CA to a file
int printToFile(int rule, int genLength, int kids, int aArray[kids][genLength]);

// takes first generation string from user and converts to int
// Used to populate the first generation
int firstGeneration(char firstGen[], int firstGenArray[], int cells);
