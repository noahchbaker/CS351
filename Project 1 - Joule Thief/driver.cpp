// BY: Isabell Austin, Noah Baker, and Anna Vadella

#include<iostream>
#include<fstream>
#include"pq.h"
#include"item.h"

using namespace std;

int main(){
    typedef pq<Item> priorityQ;
    typedef pq<Item> knapsackQ;
    priorityQ pq; // Priority Queue

    ifstream file;
    file.open("test2.txt"); 

    int n, capacity = 0;
    file >> n >> capacity;

    string name;
    double value = 0; //pesos
    double weight = 0; //pounds

    Item itemArray[n];
    for(int i = 0; i < n; i++){
        file >> name >> value >> weight;
        
        itemArray[i].name = name;
        itemArray[i].value = value;
        itemArray[i].weight = weight;

        // itemArray[i].print();
        // cout << itemArray[i].ratio() << endl;
        
        pq.enqueue(itemArray[i]);
    }
    file.close();
    pq.print();

    // Knapsack; Greedy Algorithm
    int totalW = 0; //total weight
    int sackItems = 0; //final num of items in the knapsack
    int totalV = 0; //total value

    knapsackQ knapsack;
    
    Item chosenArray[n];
    //for loop for knapsack
    for(int i = 0; i < n; i++){
        chosenArray[i] = pq.dequeue();

        if(totalW + chosenArray[i].weight <= capacity){
            knapsack.enqueue(chosenArray[i]);   
            totalV = totalV + chosenArray[i].value;
            totalW = totalW + chosenArray[i].weight;
            sackItems++;
        }
    }

    string filename  = "knapsackRun" + to_string(sackItems) + ".txt"; 
    ofstream outfile;
    outfile.open(filename);

    outfile << sackItems << "\n";
    outfile << totalW << "\n";
    outfile << totalV << "\n\n";
    outfile << "Items in the Solution:" << "\n";

    Item sackArray[sackItems];
    for(int i = 0; i < sackItems; i++){
        sackArray[i] = knapsack.dequeue();
        outfile << sackArray[i].name << " " << sackArray[i].value << " " << sackArray[i].weight << "\n";
    }

    return 0;
}