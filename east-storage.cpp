// andy lafleur
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
cout << "Enter Date:";
string input_Date;
cin >> input_Date;
string date;
double eastSt;
double eastEl;    // this is our variables
double westSt;
double westEl;

ifstream fin("Current_Reservoir_Levels.tsv");    // this is how we read in our data
if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file

}
string junk;          // we do this since we can skip the first line and actually process the data
getline(fin,junk);

while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
                   
    fin.ignore(INT_MAX, '\n');   
    if (input_Date == date) // if our input matches the date then it will only print the east basin storage on that date
    {
        cout << "East basin storage:" << eastSt << "billion gallons" << endl; // this is where print out the east basin storage
    }
    
  
}


fin.close();
}