// Andy Lafleur
#include <iostream>
using namespace std;



int main(){
int mydata[10];  // creates our array

for ( int i = 0; i < 10; i++)
{
    mydata[i] = 1;      // this for loop changes all the elements value to the number 1
}


// steps 3 4 5 can be done with a do while loop
int i = 0; // intilizating i and incrementing it
do {
    for ( int j = 0; j < 10; j++)
{
   
    cout << mydata[j] << ' ';            // this for loop prints  out all the elements
}
    // get i and v from the user
    cout << "\nInput index: ";
    cin >> i;

    cout << "\nInput Value: ";
    int v;
    cin >> v;

    // if i is good, update the array at index i
    if (0 <= i && i <10)
    {
        mydata[i] = v;
    }
    
    
} while (0 <= i && i <10); // if the index was good, repeat
cout << "Index out of range." << " Exit."<< endl;


}