//File name: /Users/laptopuser/Documents/courses/cs135/cs135_s24/project3_hare_tortoise_competition_s24/hare_tortoise_competition_code_s24/CompetitionClient.cpp
//name: Tong Yi
//email: ty680@hunter.cuny.edu
#include <iostream>
#include <string>
#include "Competition.hpp"
using namespace std;

int main() {
    Competition race;
    race.play();

    vector<int> harePattern{-3, 2, 0, 0, 6};
    Hare hare(harePattern, 0);
    
    vector<int> torPattern{1, 1, 2, -2, 3};
    Tortoise tor(torPattern, 5);

    Competition race2(hare, tor, 30);
    race2.play();
    return 0;
}
