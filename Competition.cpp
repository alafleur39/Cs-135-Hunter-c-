//Andy Lafleur
//135
//competition.cpp

#include "Competition.hpp"
#include <iostream>
using namespace std;
//Andy Lafleur
//135
//competition.cpp
Competition::Competition()
{
    rabbit = Hare();
    tor = Tortoise();
    lane = Road();
}

Competition::Competition(Hare coney, Tortoise cooter, int length)
{
    rabbit = coney;
    tor = cooter;
    lane = Road(length); // take in the input of the length and sub it into the road function to generate how far we wanna go
}

void Competition::play()
{
    int final_position = lane.length() - 1; // gettingt the last position so we do -1 of the length

    int round = 1; // start on round one

    while (rabbit.getPosition() < final_position && tor.getPosition() < final_position)
    {
        // Rabit
        rabbit.move();
        rabbit.setPosition(max(rabbit.getPosition(), 0));
        rabbit.setPosition(min(rabbit.getPosition(), final_position));
        lane.mark(rabbit.getPosition(), 'H');

        // Tortoise
        tor.move();
        tor.setPosition(max(tor.getPosition(), 0));
        tor.setPosition(min(tor.getPosition(), final_position));
        lane.mark(tor.getPosition(), 'T');

        cout << "Round " << round << ": ";
        lane.display();

        if (rabbit.getPosition() == tor.getPosition())
        {
            cout << "Ouch! Tortoise bites hare." << endl;
        }
        lane.mark(rabbit.getPosition(), ' ');
        lane.mark(tor.getPosition(), ' ');
        round++;
    }

    if (rabbit.getPosition() == final_position)
    {
        cout << "Yuck, hare wins." << endl;
    }
    else if (tor.getPosition() == final_position)
    {
        cout << "Tortoise wins!" << endl;
    }
    else
    {
        cout << "It is a tie." << endl;
    }
}
