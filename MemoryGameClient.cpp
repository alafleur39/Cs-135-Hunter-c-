#include "MemoryGame.hpp"
#include <iostream>
#include <cstdlib> // for srand and rand
#include <ctime> 
#include <iomanip>
using namespace std;  // for time

// Default constructor
MemoryGame::MemoryGame() {
    numPairs = 3;  //
    numSlots = 8;
    values = new string[numSlots]; // dynamic memory allocation
    //srand(time(nullptr)); // comment this out
    int randomintegers[3]; // initilize 3 random integers
    for (int i = 0; i < 3; i++)
    {
        randomintegers[i] = rand() % 1000; // generate 3 random integers in [0,999]
    }
    values[0] = to_string(randomintegers[0]); // Place the first integer  of our randomly genereated integers to the first two slots of values
    values[1] = to_string(randomintegers[0]);

    values[2] = to_string(randomintegers[1]);  // Place the second integer to the next two slots of values
    values[3] = to_string(randomintegers[1]);

    values[4] = to_string(randomintegers[2]);
    values[5] = to_string(randomintegers[2]);   // Place the third integer to the subsequent two slots of values

    for (int i = 6; i < numSlots; i++) 
    {
      values[i] = ""; // Set the rest of values elements to be empty strings
    }
    bShown = new bool[numSlots];  // Allocate dynamic memory for an array of booleans –
    // type bool in C++ – with numSlots elements and assign it to data member bShown. Set each element of bShown to be false.
    for (int i = 0; i < numSlots; i++)
    {
        bShown[i] = false;  // we used this for loop to set each element of bshown false
    }
    

  
}

// Non Default constructor
MemoryGame::MemoryGame(int numPairs, int numSlots) 
{
   if (numPairs <= 0 || numSlots <=0 || 2* numPairs > numSlots)
   {
     numPairs = 3;
     numSlots = 8;



   }
   else
   {
    this->numPairs = numPairs;  // we use this-> to help us access our data member from the other constructor and assign it to the parameter
    this->numSlots = numSlots;
   }
   values = new string[numSlots];
   int randomIntegers[numPairs];
   for (int i = 0; i < numPairs; i++) //Generate numPairs random integers in [0, 999]
   {
    randomIntegers[i] = rand() % 1000;
   }

    values[0] = to_string(randomIntegers[0]); 
    values[1] = to_string(randomIntegers[0]);
    values[2] = to_string(randomIntegers[1]);
    values[3] = to_string(randomIntegers[1]);
    values[4] = to_string(randomIntegers[2]);
    values[5] = to_string(randomIntegers[2]);
    for (int i = 6; i < numSlots; i++)
    {
        values[i] = "";  // set the rest of values to be empty strings
    }

    bShown = new bool[numSlots];
    
    // Initialize each element of bShown to false
    for (int i = 0; i < numSlots; ++i) {
        bShown[i] = false;
    
   
    
}
}
// Constructor with words as data
MemoryGame::MemoryGame(string *words, int size, int numSlots) {
    if (size <= 0 || numSlots <= 0 || numSlots < 2 * size) {
        numSlots = 2 * size; // Assume the number of elements in formal parameter words is size. If formal parameters size or numSlots
         //is non-positive or numSlots is smaller than twice of size, set numSlots to be twice of size
    }
    this->numPairs = size; // we set data member numPairs to parameter size we use this-> to access data members
    this->numSlots = numSlots; // set data member numSlots to its paramater equivalent
    values = new string[numSlots];
    bShown = new bool[numSlots];
    int wordIndex = 0; // i created an index to track the current word

    // Place each word in pairs until all words are placed or the values array is filled
    for (int i = 0; i < numSlots && wordIndex < size; i += 2) {
        values[i] = words[wordIndex];  // Place the current word in the first slot of the pair
        values[i + 1] = words[wordIndex];  // Place the current word in the second slot of the pair
        wordIndex++;  // Move to the next word
    }

    // Set the rest of the elements of values to be empty strings
    for (int i = wordIndex * 2; i < numSlots; i++) {
        values[i] = "";
    }
     // Initialize each element of bShown to false
    for (int i = 0; i < numSlots; ++i) {
        bShown[i] = false;
     



    
}
}

// Destructor
MemoryGame::~MemoryGame() {
    delete[] values;    // we allocate memory in constructor deallocate memory in destructor
    delete[] bShown;   // we use this destructor to prevent any memory leakage
    values = nullptr;
    bShown = nullptr; 
} 

// Play method
void MemoryGame::play() {
    // Implementation of the play method goes here
    randomize(); // call randomize method
    int index,round,pairsFound,first;
    pairsFound=0;
    round = 0;
    first = -1; //initlize first to an invalid index 
    while (pairsFound < numPairs)
{
    cout << "Round: " << round << endl;  // print out numbers of round
    round += 1;
      // declare index outside the loop
    
    // find an unflipped card
    index = input(); // random index
    while (bShown[index]) // loop until an unflipped card is found
    {
        index = input(); // reassign index until an unflipped card is found
    }
    
    // next we are going to implement the flips
    // first flip
    if (first == -1)
    {
        bShown[index] = true;
        first = index; // save the index
    }
    else
    {
        // second flip
        if (values[first] == values[index] && values[first] != "")
        {
            // match found
            bShown[index] = true;
            pairsFound++;
        }
        else
        {
            bShown[first] = false;  // if there's no match found
        }
        first = -1; // reset first index
    }
    display();
}
    // Report round taken to find all matched pairs
    cout << "Rounds taken to find all matched pairs: " << round << endl;
}
    


void printSeparatedLine(int size) {
cout << "+"; //the first +
//draw -----+ for (size) many times
for (int i = 0; i < size; i++) cout << "-----+";
    cout << endl;
}

// Display method
void MemoryGame::display() const {
    //print labels
cout << " ";
for (int i = 0; i < numSlots; i++)
    cout << setw(3) << i << setw(3) << " ";
    //setw(3) before i means i occupies 3-character,
    //For example, if i has only two digits,
    //then pad a space to its left.
cout << endl;
printSeparatedLine(numSlots);

cout << "|";
for (int i = 0; i < numSlots; i++)
{
    if (bShown[i])
    {cout << setw(5) << values[i] << "|";}
    else
    {cout << "     |";}

     
        
    
    
}
cout << endl;

printSeparatedLine(numSlots);

    
}

// Randomize method
void MemoryGame::randomize() {
   // srand(time(0)); // Seed the random number generator
    // Implementation of the randomize method goes here
    int size = numSlots; // Determine the size of the values array we initilize size to numslots
    // Continue Step 2-3 until size is 1 to implement these steps we will do a while loop
    while (size >1) // if size hits 1 we start
    {
        int random_index = rand() % size;  //Generate a random index in [0, size).

        //Swap the element at chosen index with the last element in values.
        string temp = values[random_index];
        values[random_index] = values[size-1];
        values[size-1] = temp;

        size--; //Then reduce size by 1 so that we do not consider the already-chosen element, which resides in the last
         //element of values.

    }
    
}







// Input method
int MemoryGame::input() const {
    // Implementation of the input method goes here


    // step 7.1 
    int end_of_array = numSlots -1;
    cout << "Enter an unflipped card in [0, " << end_of_array << "]: ";
    int input1; // we will change this from string to int
    cin >> input1;
    while (input1 < 0 or input1 > end_of_array)  // nested while loop
    {
        
       cout << "Warning: there is a space following :input is not in [0, " << end_of_array <<  "].  Re-enter: " << endl;
    
      while (bShown[input1])  // we needed a while loop so users can re enter
      {
        cout << "The card is flipped already. Re-enter: " << endl;
        cin >> input1;  // allows user to re enter

      }

      
      
    }  
     return input1; // return the index                                            
    }

   // would i need 2 while loops to achieve this 
    // lets try a nested while loop
// how do we know if the index of a flipped card is chosen already?
    




int main() {
    // Create an instance of MemoryGame with default constructor
    MemoryGame game1;

    cout << "Playing game1:" << endl;
    game1.play();

    // Create an instance of MemoryGame with non-default constructor
    MemoryGame game2(4, 10); // 4 pairs, 10 slots

    cout << "Playing game2:" << endl;
    game2.play();

    // Create an instance of MemoryGame with words
    string words[] = {"Apple", "Banana", "Orange", "Grapes"};
    MemoryGame game3(words, 4, 8); // 4 words, 8 slots

    cout << "Playing game3:" << endl;
    game3.play();

    return 0;
}
// keep this code just in case