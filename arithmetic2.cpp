// Andy Lafleur
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

int main() {
   // srand(time(NULL));
    char operator_array[5] = {'+','-','*','/','%'};
    //int randomIndex = rand() % 5;  // 5 is our number of elements
    //char selected_operator = operator_array[randomIndex]; // this is how we generate our operators at a random index
    int input;
    //int operand = rand()%10;
    int second_operand;
    int result;           // we need to double so we can divide with fractional numbers
    int question_input;
    double correct_answer = 0;
    double percentage;


    cout << "Enter the total number of questions to ask: ";
    cin >> question_input;
    while (0 >= question_input)  // we use a while loop to ensure user input is positive 
    {
        cout << "The number of questions cannot be zero or negative. Re-enter: "; // this loop will keep going until user enters a positive
        cin >> question_input;
    }
    for (int i = 0; i < question_input; i++) // we used a for loop so the program would run based on the number the user input
    {

        int randomIndex = rand() % 5;
        char selected_operator = operator_array[randomIndex]; 

        int operand = rand()%10;

        if (selected_operator == '/' or selected_operator == '%')
        {
            second_operand = rand()%9+1;
        }
        else
        {
            second_operand = rand() % 10;
        }
        cout << "What is " << operand << " " << selected_operator << " " << second_operand << "?" << " ";
        cin >> input;
        if (selected_operator == '+')
        {
            result = operand + second_operand;
        }
        else if (selected_operator == '-')
        {
            result = operand - second_operand;
        }
        else if (selected_operator == '*')
        {
            result = operand * second_operand;
        }
        else if (selected_operator == '/')
        {
            result = operand / second_operand;
        }
        else if (selected_operator == '%')
        {
            result = operand % second_operand;
        }
        if (input == result)
        {
            cout << "true" << endl << endl;
            correct_answer++; // if the user's answer is correct we will initilize it under this variable
            // to keep track of correct answer we increment by 1 
        }
        else
        {
            cout << "false" << endl << endl;    // how do we save the correct answer for each time for loop happens so we can calculate the percentage properly?
        }
    }
    percentage = correct_answer/question_input * 100;
    cout << "percentage correct: " << percentage << "%" << endl;
    if (percentage >= 90)
    {
        cout << "letter grade: A" << endl;
    }
    else if (percentage >= 80)                           // i took the percentage and if statements out so it would stop appearing after                            // each for loop
    {
        cout << "letter grade: B" << endl;
    }
    else if (percentage >= 70)
    {
        cout << "letter grade: C" << endl;
    }
    else if (percentage >= 60)
    {
        cout << "letter grade: D" << endl;
    }
    else
    {
        cout << "letter grade: F" << endl;
    }
}


