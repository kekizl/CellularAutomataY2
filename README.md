[![Linux](https://svgshare.com/i/Zhy.svg)](https://svgshare.com/i/Zhy.svg)
[![macOS](https://svgshare.com/i/ZjP.svg)](https://svgshare.com/i/ZjP.svg)
[![Windows](https://svgshare.com/i/ZhY.svg)](https://svgshare.com/i/ZhY.svg)
![example workflow](https://github.com/kekizl/CellularAutomataY2/actions/workflows/c.yml/badge.svg)
[![Ask Me Anything !](https://img.shields.io/badge/Ask%20me-anything-1abc9c.svg)](https://GitHub.com/kekizl/CellularAutomataY2)

# CellularAutomataY2
A Cellular Automata made in C.

## Synopsis
Generally, a cellular automaton (CA) is a regular grid of cells. Each cell can exist in one of a finite number of states(on or off) at a particular point in time. Cellular automata have found application in various areas, including physics, theoretical biology and microstructure modeling. The grid can be in any finite number of dimensions. For each cell, a set of cells called its neighborhood is defined relative to the specified cell. The new generation of the automata is generated by a 'rule' that determines the new state of each cell in terms of the current state of the cell and the states of the cells in its neighborhood

This project demonstrates the different types of patterns generated by a Cellular Automata for any rule and size of your choice.

Conway's Game of Life is perhaps the most popular application of an Automata. It is a 2D automata in which cells are either alive or dead, represented by a 1 or 0 respectively. The next state of any is defined by the amount of surrounding 'alive' cels. A simulator of said Automata is also featured in this project as an extension. 

## How to run

In order to run the 1 dimensional automata, type 'make test'.

Once running the tester file you will be prompted to enter a rule number. Any number from 1 to 256 works.

Next you will be asked for the width and length of the Automaton. Once again, any number works.

## Sample Output
A sample output from running the tester file should be as follows:

```
Please enter the number of the rule you want: 30

Please enter the number of cells you want: 30

Please enter the number of generations you want: 10


000100000000000100000000000000

001110000000001110000000000000

011001000000011001000000000000

110111100000110111100000000000

100100010001100100010000000001

011110111011011110111000000011

010000100010010000100100000110

111001110111111001111110001101

000111000100000111000001011001

101100101110001100100011010111
```

## How to run (Conway's Game of Life)
Similarly type 'make 2dtest' and run the .out file created. 

First you will be prompted to enter the width of the automata. Any number works.

Next you will be asked to enter the depth of the automata. Enter a number of your choice.

Finally you will be asked to enter the amount of generations for which the simulation will run. 

Output can look as follows:
```
Please enter the amount of rows you want: 5
Please enter the amount of columns you want: 5
Please enter the amount of gens you want: 3

First Generation:
10111
10011
01011
00000
10110

Next Generation:
01101
10000
00111
01001
00000

Next Generation:
01000
00001
01111
00101
00000%     
```

## Future Enhancements
Possible extensions I would like to implement in the future include the following:

- Graphics 

- Wrap-Around implementation of Conway's Game of Life

