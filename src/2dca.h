/*FILE: Conways Game of Life Simulation
 *HEADER FILE:
 *BY: CHRISTIAN ZLATANOV
 */

//amount of neighbours a cell has
int countNeighbours(int row, int col, int aGen[row][col], int r, int c);

//print a generation
int printGen(int row, int col, int aGen[row][col]);
