# Project 4: Joule Thief - Branch and Bound (CS351 - Algorithms)
BY: Isabell Austin, Noah Baker, and Anna Vadella

DUE: Monday, December 18th, 2023

# Deliverables
item.h: our implementation of provided base code

fileBuilder.cpp: program to generate text files

driver.cpp: dynamic programming approach to 0-1 knapsack

jouleTest50.txt: text file input for knapsackRun50.txt

knapsackRun50.txt: sample run with 50 items

jouleTest100.txt: text file input for knapsackRun100.txt

knapsackRun100.txt: sample run with 100 items

# How to Run (Format & Instructions)
## Format:
### The format of the output files for fileBuilder.cpp is shown below:

number-of-items-in-solution knapsack-capacity

item-1-name item-1-pesos item-1-weight

item-2-name item-2-pesos item-2-weight

...

### The format of the output files for driver.cpp is shown below:

Items in the Solution:

item-1-name item-1-pesos item-1-weight

item-2-name item-2-pesos item-2-weight

...

number-of-items-in-solution

total-weight-of-items-in-solution

total-profit-of-items-in-solution

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