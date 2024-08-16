//Andy Lafleur
#include <iostream>
#include <string>
using namespace std;

 // we solved this by using nested for loops

int main()
{
cout << "Input width: ";   // this is our user input for width
int width;
cin >> width;

cout << "Input height: ";  // this is our user input for height
int height;
cin >> height;


cout << "Shape:" << endl;    // this is so we can print "shape:""
for (int i = 0; i < height; i++)    /// for loop for the height of our box shape
{

for (int i = 0; i < width; i++)   
{
    cout << "*";  // how can i get this all on one line? // i got it all on one line by removing  endl
}
cout <<endl;  // this is so the stars can move on to the next row
}
// this program is a success make sure you study this !!!
}