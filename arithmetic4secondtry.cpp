#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    string file_name = "problems.csv"; // file name
    ifstream input_file("problems.csv"); // inpaut file stream

    if (input_file.fail()) {
        cerr << "Failed to open the file." << endl; // error message if the file opening fails
        exit(1);
    }

    string equations[20]; // array to store equations
    string correct_answers[20]; // array to store correct answers
    string user_answer; // stores the user's answer
    int question_count = 1; // count of questions
    int correct_count = 0; // count of correct answers
    int total_questions = 0; // total number of questions
    int rem_Q = 0;
    double percentage_correct;

    string equation; // stores the mathematical expression
    string correct_answer; // stores the correct answer

    while (getline(input_file, equation, ',')) { // read expression until comma
        getline(input_file, correct_answer); // read in correct answer
        equations[total_questions] = equation; // store equation in array
        correct_answers[total_questions] = correct_answer; // store correct answer in array
        total_questions++; // increment total questions count
    }

    rem_Q = total_questions;

    input_file.close(); // close the file

    //cout << rem_Q << " "  << total_questions << endl;

// for (int i = 0; i < total_questions; ++i) {
        while( rem_Q > 0 && percentage_correct < 60) {

        srand(time(NULL));

        int index = rand() % rem_Q; // generate random index
        cout << "(" << question_count << ") What is " << equations[index] << "? "; // prompt for user input
        getline(cin, user_answer); // get user's answer and save it in the variable user_answer
        cout << endl << user_answer << endl; // output user's answer


        if (user_answer == correct_answers[index]) { // check if the answer is correct
            cout << "true" << endl;
            correct_count++; // add to correct count
        } else {
            cout << "false" << endl;
        }

        cout << endl; // add spacing between questions
        question_count++; // increment question count

        equations[index] = equations[rem_Q -1]; 
        correct_answers[index] = equations[rem_Q -1];
        rem_Q--;
        
        percentage_correct = ((correct_count * 1.0) / (total_questions * 1.0) * 100); // calculate percentage correct

        if (percentage_correct >= 60) { // check if correct rate is 60% or higher
        cout << "At least 60  " << "%" << " is correct. Stop." << endl;
        break;
         }
        }
         cout << "Percentage correct: " << percentage_correct << "%" << endl; // output percentage correct
    return 0;
    }

