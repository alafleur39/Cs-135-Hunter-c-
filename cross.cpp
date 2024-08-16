// Andy Lafleur
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Input size: ";
    int size;               // size user input
    cin >> size;
    int count = size;

    cout << "Shape:" << endl; 

    for (int row = 0; row < size; row++)  // row loop
    {
      for (int col = 0; col < size; col++) // column loop
        {
            if (row==col || col==count-1)   // this for loop makes the row loop and column intersect when they print out the asteriks
            {
                cout << "*";  // print asterik
            }
            else
            {
                cout << " "; // print empty space
            }
            
            
        }
        count -=1;
        cout << endl; // print out new lime
    }
    



}