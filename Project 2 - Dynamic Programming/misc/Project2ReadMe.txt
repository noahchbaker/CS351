# Project 2: Joule Thief - Dynamic Programming (CS351 - Algorithms)
BY: Isabell Austin, Noah Baker, and Anna Vadella

DUE: Friday, December 1st, 2023

# Deliverables
item.h: our implementation of provided base code

fileBuilder.cpp: program to generate text files

driver.cpp: dynamic programming approach to 0-1 knapsack

jouleTest10.txt: text file input for knapsackRun10.txt

knapsackRun3.txt: sample run with 10 items

jouleTest20.txt: text file input for knapsackRun20.txt

knapsackRun5.txt: sample run with 20 items

# How to Run (Format & Instructions)
## Format:
### The format of the output files for fileBuilder.cpp is shown below:

number-of-items-in-solution knapsack-capacity

item-1-name item-1-pesos item-1-weight

item-2-name item-2-pesos item-2-weight

...

### The format of the output files for driver.cpp is shown below:

number-of-items-in-solution

total-weight-of-items-in-solution

total-profit-of-items-in-solution


Items in the Solution:

item-1-name item-1-pesos item-1-weight

item-2-name item-2-pesos item-2-weight

...

## Instructions:
### To generate text files for testing:
```bash
g++ fileBuilder.cpp
a.out
```
The file output will be named jouleTestN.txt where N is the number of desired items.
For example, for a 20 item test, the file will be named jouleTest20.txt


### To generate final knapsack run output:
```bash
g++ driver.cpp
a.out
```
You will have to edit line 16 for your desired test file name.
The file output will be named knapsackRuntN.txt where N is the number of desired items.
For example, for a 20 item run, the file will be named knapsackRun20.txt.