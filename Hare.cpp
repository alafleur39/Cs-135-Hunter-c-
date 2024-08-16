// Andy Lafleur
// TONG YI
// Project 3A
#include "Hare.hpp"
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;



// we have to follow the instructions from the hpp file
//, the colon (:) is used in the constructor initializer list to initialize member variables of the class.
 Hare::Hare() : patterns({0, 0, 9, 9, -12, 1, 1, 1, -2, -2}), position(0) // what does : mean? // : means member initializer list
 {
      //so far so good
 }

Hare::Hare(vector<int> patterns, int position): position(position), patterns(patterns) 
{
    // no further initilization needed because we did member initializer list
}

Hare::Hare(int* arr, int size, int position)
{  // use the size parameter that will be inputed by user in the function call to iterate through the for loop
patterns.reserve(size);
for (int i = 0; i < size; i++)  // we iterating through the vector using a for loop
{
    patterns.push_back(arr[i]);
}
this->position = position;    // so far so so good
}

void Hare::move()  // we will come back to the move constructor
{
 // Generate a random number in the range [0, size of patterns)
    int random_index = rand() % patterns.size();

    // Move the hare according to its move pattern at the randomly chosen index
    position += patterns[random_index];

    // 
    // we might not need if statements or do we?
}


int Hare::getPosition() const  // getter function to access a private data member
{    // why did we have to make it consant? // so the return value cant be modified
 return position;
}

void Hare::setPosition(int position) // setter function
{
  this->position = position;    
} 
