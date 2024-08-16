//File name: /Users/laptopuser/Documents/courses/cs135/cs135_s24/project3_hare_tortoise_competition_s24/taskA/autograder/main.cpp
//name: Tong Yi
//email: ty680@hunter.cuny.edu
#include <iostream>
#include <string>
#include "Road.hpp" 
//g++ -std=c++11 main.cpp would be fine with #include "Road.cpp" 
//#include <vector> //included in "Road.hpp" already
using namespace std;

int main(int argc, const char *argv[]) { //does not take input from users
    //Road();
    //Road(int length); 

    Road rd;
    Road rd2(30);
    Road rd3(-1);

    switch (*argv[1]) {
    case 'A': //default constructor
         cout << "After calling default constructor, data member blocks is {";
         for (int i = 0; i < rd.blocks.size(); i++) {
             cout << "'" << rd.blocks[i] << "'";
             if (i < rd.blocks.size()-1)
                cout << ",";
         }
         cout << "}" << endl;
         break;
     case 'B': //Road(int)
         cout << "After Road(30), data member blocks is {";
         for (int i = 0; i < rd2.blocks.size(); i++) {
             cout << "'" << rd2.blocks[i] << "'";
             if (i < rd2.blocks.size()-1)
                cout << ",";
         }
         cout << "}" << endl;
         break;
    case 'C': //Road(int);
         cout << "After Road(-1), data member blocks is {";
         for (int i = 0; i < rd3.blocks.size(); i++) {
             cout << "'" << rd3.blocks[i] << "'";
             if (i < rd3.blocks.size()-1)
                cout << ",";
         }
         cout << "}" << endl;
         break;
    case 'D': //void mark(int index, char ch);
         cout << "After calling mark(2, 'H') method, blocks[2] is ";
         rd.mark(2, 'H');
         cout << rd.blocks[2] << endl;
         break;
    case 'E': //void display() const;
         cout << "After calling display() method with block indexed at 2 is marked by 'H' and block indexed at 5 is marked by 'T', data member blocks is ";
         rd.blocks[2] = 'H';
         rd.blocks[5] = 'T';
         rd.display(); 
         break;
    case 'F': //int length() const;
         cout << "After calling length() method for Road rd2(30), data member length is ";
         cout << rd2.length() << endl;
         break;
 
    default:
         cout << "wrong option";
    }

    return 0;
}
