// andy lafleur
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries
// libraries

int main(){
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
    string starting_date;
    cout << "Enter starting date: ";
    cin >> starting_date;

    string ending_date;
    cout << "Enter ending date: ";
    cin >> ending_date;
    bool in_range = false;  // this boolean checks if we are in range

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
  {
    fin.ignore(INT_MAX, '\n');
    if(date == starting_date)
    {                         // if starting date is equal to original date this start the comparison
      in_range = true;
    }
    if(in_range)
    {
      if(eastEl >= westEl)
      {
        cout << date << " East" << endl;
      }
      else
      {
        cout << date << " West" << endl;
      }
    }
    if(date == ending_date)
    {
      in_range = false;
    }
  }
     fin.close();
     return 0;

}


    

