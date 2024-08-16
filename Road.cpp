//  Andy
//  CSCI-135
//  Tong Yi
//  Project 3, Task C


#include "Road.hpp"
#include <iostream>

Road::Road() {
    // Initialize blocks vector with default size and value
    blocks.assign(70, ' '); // 70 spaces
}

Road::Road(int length) {
    //  length if negative or zero
    if (length <= 0) {
        length = 70; // Default length
    }

    
    blocks.assign(length, ' '); 
}

void Road::mark(int index, char ch) {
    // check ifindex is valid
    if (index >= 0 && index < blocks.size()) {
        blocks[index] = ch;
    } else {
        std::cout << "Index out of bounds." << std::endl;
    }
}

void Road::display() const {
    // show the elements of blocks vector
    for (char block : blocks) {
        std::cout << block;
    }
    std::cout << std::endl;
}

int Road::length() const {
    // Return  size of blocks vector
    return blocks.size();
}
