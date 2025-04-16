// BY: Isabell Austin, Noah Baker, and Anna Vadella

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    int n = 0, sackCap = 0, itemV, itemW;  
    // n: # of items, sackCap: sack capacity, itemN: name, itemV: value, itemW: weight

    srand(time(NULL)); 

    cout << "Number of Items: ";
    cin >> n; //10, 20, 100, 1000, 10000
    cout << "Knapsack Capacity: ";
    cin >> sackCap;

    string filename  = "jouleTest" + to_string(n) + ".txt"; 
    ofstream outfile;
    outfile.open(filename);


    outfile << n << " " << sackCap << "\n";

    for(int i = 0; i < n; i++)
    {   if(n<=26) {
            char itemN;
            char letter[] = "abcdefghijklmnopqrstuvwxyz";
            itemN = letter[i]; 
            itemV = rand()%(176) + 25; //randomized item values between 25 and 200
            itemW = rand()%(3*n) + 1; //randomized item weights between 1 and 3 * n
            outfile << itemN << " " << itemV << " " << itemW << endl;
        }
        else {
            int itemN = 0;
            itemN = 1100+(20+i); //incrementing item number starting at 1120
            itemV = rand()%(176) + 25; //randomized item values between 25 and 200
            itemW = rand()%(3*n) + 1; //randomized item weights between 1 and 3 * n
            outfile << itemN << " " << itemV << " " << itemW << endl;
        } 
    }

    outfile.close();

    return 0;
}