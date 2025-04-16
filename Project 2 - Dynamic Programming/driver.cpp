// BY: Isabell Austin, Noah Baker, and Anna Vadella
#include<iostream>
#include<fstream>
#include "item.h"
int count = 0;

int max(int a, int b) {
    if(a >= b) {
        return a;
    }
    return b;
}

int refine(int n, int W, Item * items, int ** matrix)
{
    count++;

    // base case
    if (n == 0 || W == 0) {
        return 0;
    }

    count++;
    if(W < items[n-1].weight) {
        matrix[n][W] = refine(n-1, W, items, matrix);
        return matrix[n][W];
    }
    else {
        matrix[n][W] =  max(refine(n-1, W, items, matrix), 
            (refine(n-1, W - items[n-1].weight, items, matrix) + items[n-1].value));
        return matrix[n][W];
        
    }
}

int main()
{
    // item variables
    int numItems = 0, capacity = 0;
    double weight = 0, value = 0, ratio = 0;
    string nameOfItem = " ";

    // knapsack variables
    int sackItems = 0; 
    int totalV = 0, totalW = 0;
    int skipItem = 0;

    ifstream file;
    string filename = " ";
    
    cout << "Enter filename: ";
    cin >> filename;

    file.open(filename); 
    file >> numItems>> capacity;

    Item * items = new Item[numItems];
    Item * knapsack = new Item[numItems];
    for(int i = 0; i < numItems; i++)
    {
        file >> nameOfItem >> value >> weight;
        Item itemObj = Item(value, weight); 
        itemObj.name = nameOfItem;
        ratio = itemObj.ratio();
        items[i] = itemObj;
    } 
    int ** matrix = new int * [numItems+1];
    
    // PHASE 1: Dynamic Approach for the 0-1 knapsack ---------------------------------------------------
    for(int i = 0; i <= numItems; i++)
    {
        // creates an auxiliary two-dimensional array
        matrix[i] = new int[capacity+1]; // each i-th pointer is now pointing to dynamic array (size capacity)

        for(int j=0; j <= capacity;j++)
        {
            if (i == 0 || j == 0)
            {
                continue;
            }
            else if (items[i-1].weight <= j)
            {
                // Formula from 192 in the book
                matrix[i][j] = max(matrix[i-1][j], matrix[i-1][j - ((int)items[i-1].weight)] + items[i-1].value);
            }
            else
            { 
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    for(int i = numItems; i > 0; i--)
    {
        if(matrix[i][capacity - skipItem] == matrix[i-1][capacity - skipItem])
        {
            continue;
        }
        knapsack[sackItems] = items[i-1];
        totalV += knapsack[sackItems].value;
        totalW += knapsack[sackItems].weight;
        skipItem += knapsack[sackItems++].weight;
    }    

    /** PHASE 2: Reporting the Items ---------------------------------------------------
    string outfilename  = "knapsackRun" + to_string(sackItems) + ".txt"; 
    ofstream outfile;
    outfile.open(outfilename);

    outfile << sackItems << "\n";
    outfile << totalW << "\n";
    outfile << totalV << "\n\n";
    outfile << "Items in the Solution:" << "\n";

    Item sackArray[sackItems];
    for(int i = 0; i < sackItems; i++){
        outfile << knapsack[i].name << " " << knapsack[i].value << " " << knapsack[i].weight << "\n";
    } */
    // reset matrix values
    for(int i = 0; i < numItems+1; i++)
    {
        for(int j=0; j<capacity+1; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // PHASE 3: Refinement of Dynamic Programming Approach ---------------------------------------------------
    refine(numItems, capacity, items, matrix); 

    sackItems = 0;
    totalV = 0;
    totalW = 0;
    skipItem = 0;

    Item * knapRefined = new Item[numItems];

    // select optimal solutions; determine how many entires needed, then do computations starting with first row
    for (int i = numItems; i > 0; i--)
    {
        if(matrix[i][capacity - skipItem] == matrix[i-1][capacity - skipItem])
        {
            continue; 
        }
        knapRefined[sackItems] = items[i-1];
        totalV += knapRefined[sackItems].value;
        totalW += knapRefined[sackItems].weight;
        skipItem += knapRefined[sackItems++].weight;
    } 

    string outfilename  = "knapsackRun" + to_string(sackItems) + ".txt"; 
    ofstream outfile;
    outfile.open(outfilename);

    outfile << sackItems << "\n";
    outfile << totalW << "\n";
    outfile << totalV << "\n";
    outfile << "Number of Calculated Matrix Entries:" << count << "\n\n";
    outfile << "Items in the Solution:" << "\n";


    for(int i = 0; i < sackItems; i++)
    {
        outfile << knapRefined[i].name << " " << knapRefined[i].value << " " << knapRefined[i].weight << "\n";
    } 

    return 0;
}