// BY: Isabell Austin, Noah Baker, and Anna Vadella
#include<iostream>
#include<fstream>
#include <set>
#include "item.h"
#include "pq.h"

using namespace std;

// global variables as instructed by the book (pg 262)
Item * items(nullptr);
bool * best(nullptr); 
bool * include(nullptr);

set<Item> bestSet = {};

int numSacked = 0;
int totW = 0;
int j = 0;

ofstream outfile;

float bound(Item u, int numItems, int capacity, const Item * items)
{
    // int j = 0;
    int k = 0;
    // int totW = 0;
    float result = 0;
    
    if (u.weight >= capacity)
    { return 0; }

    int profitBound = u.value;
    // cout << u.value << endl;
    for(int x = 0; x < numItems; x++)
    {   best[x] = include[x]; }

    j = u.level + 1;
    totW = u.weight;
    // cout << u.weight << endl;
    bestSet = u.sackItems;

    while ((j <= numItems) && (totW + items[j].weight <= capacity))
    {
        totW += items[j].weight;
        profitBound += items[j].value;
        bestSet.insert(items[j]);
        // u.sackItems.insert(items[j]);
        j++;
    }

    // bestSet = u.sackItems;

    if (j < numItems)
    {   
        profitBound += (capacity -totW) * items[j].ratio();

        for (Item i : bestSet) {
            outfile << i.name << " " << i.value << " " << i.weight << "\n";
        } 
        
    }
    
    // bestSet = set(u.sackItems);
    // for (Item i : bestSet) {
    //     outfile << i.name << " " << i.value << " " << i.weight << "\n";
    // }

    return profitBound;
}

// Best-First Search with B&B from the book
int knapsack(int numItems, const Item * items, int capacity)
{
    pq<Item> pq;
    Item u,v;

    // initalize include array
    for(int x = 0; x < numItems; x++)
    {   include[x] = false; }

    u.level = -1;
    u.value = 0;
    u.weight = 0;
    u.sackItems = {};

    int maxProfit = 0;
    pq.enqueue(u);

    while (!pq.empty())
    {
        u = pq.dequeue();

        if (u.level == -1)
        {   v.level = 0; }
        if (u.level == numItems - 1)
        {   continue; }
        
        v.level = u.level + 1;

        v.weight = u.weight + items[v.level].weight;
        v.value = u.value + items[v.level].value;

        if (v.weight <= capacity && v.value > maxProfit)
        {  maxProfit = v.value; }

        v.bound = bound(v, numItems, capacity, items);
        
        if (v.bound > maxProfit)
        {   pq.enqueue(v); }

        v.weight = u.weight;
        v.value = u.value;

        v.bound = bound(v, numItems, capacity, items);

        if (v.bound > maxProfit)
        {   pq.enqueue(v); }
    }

    // cout<< "\nNumber of items total: "<<numItems<<endl;
    // cout<<"Knapsack capactiy: "<< capacity<<endl;

    return maxProfit;
}

int main()
{
    // item data
    double weight = 0;
    double value = 0;
    double ratio = 0;
    string itemName(" ");

    int numItems = 0;
    int profitTracker = 0;
    int weightTracker = 0;
    int capacity = 0;

    ifstream file;
    string filename = " ";
    cout << "Enter filename: ";
    cin >> filename;

    file.open(filename); 

    file >> numItems >> capacity;

    items = new Item [numItems+1];
    include = new bool [numItems];
    best = new bool [numItems];

    // create item objects and read in their values from a file
    for(int i1=0; i1< numItems; i1++)
    {
        file >> itemName >> value >> weight; 
        Item itemObj = Item(value, weight);
        itemObj.name = itemName;
        items[i1] = itemObj;
    }

    // sorting the items based on ratio
    for (int i=0; i<numItems-1; i++)
    {
        for(int j=0; j< numItems-i-1; j++)
        {
            if (items[j].ratio() < items[j+1].ratio())
            {
                Item tempItem = items[j];
                items[j] = items[j+1];
                items[j+1] = tempItem; 
            }
        }
    }
    file.close();

    string outfilename  = "knapsackRun" + to_string(numItems) + ".txt"; 
    // ofstream outfile;
    outfile.open(outfilename);

    // print optimal items from bestSet
    outfile <<"Optimal Knapsack Items: "<< "\n";
    int maximumProfit = 0;
    maximumProfit = knapsack(numItems,items,capacity);

    outfile << "\nNumber of knapsack items: " << j << "\n";
    outfile << "Total Weight: " << totW << "\n";
    outfile << "Maxiumum profit of optimal solution: " << maximumProfit <<"\n";

    return 0;
}