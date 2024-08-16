// Andy Lafleur
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

int main(){
srand(time(NULL));
char operator_array[5] = {'+','-','*','/','%'};
int randomIndex = rand() % 5;  // 5 is our number of elements
char selected_operator = operator_array[randomIndex]; // this is how we generate our operators at a random index
int input;
int operand = rand()%10;
int second_operand;
int result;

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
    cout << "true"<< endl;
}
else
{
  cout << "false"<< endl;
}












}


