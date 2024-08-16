// Andy Lafleur
#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    string fileName = "problems.csv"; 
    ifstream fin("problems.csv"); // reads in file 

    if (fin.fail()){
        cerr << "File cannot be opened for reading. " << endl;
        exit(1);
    }
    string junk; 
    //getline(fin, junk); // gets first line ignores it 
    

    string equations; 
    string answers; 
    string ans;  
    string user_input; 
    int count = 1; 
    int questions_num = 0; // but these are strings so i have to convert to int
    int correct_num = 0; 

    while(getline(fin, equations, ',')){ // checks for first column gets that expression line with the comma
        getline(fin, ans); // ignores the answer column.   

        cout << "(" << count << ") " << "What is " << equations << "?" << " ";
        cin >> user_input; 
 //           cout <<endl << user_input << endl;
            //cout << (user_input == ans);
        if (user_input == ans){ // conversion 

            cout << "true" << endl;
            correct_num++; 
        }
        else{
            cout << "false" << endl;
        }
        cout << endl; // to get the spacing between each question. 
        count++; 
        questions_num++; 
    } 
    fin.close();

    double Correct_percentage = ((correct_num*1.0) / (questions_num*1.0) * 100); 
    cout << "percentage correct: " << Correct_percentage << "%" << endl; 

    if (Correct_percentage >= 90){
        cout << "letter grade: A"; 
    }
    else if (Correct_percentage >= 80){
        cout << "letter grade: B"; 
    }
    else if (Correct_percentage >= 70){
        cout << "letter grade: C"; 
    }
    else if (Correct_percentage >= 60){
        cout << "letter grade: D"; 
    }
    else{
        cout << "letter grade: F"; 
    }

    fin.close();
return 0; 

}