// Andy Lafleur




#include <iostream>
#include <fstream>
#include <cstdlib> // for rand
#include <ctime> // run new value each time 
#include <sstream>
#include <algorithm> // for swap function 
using namespace std;

 int main(){ 

    string input_fileName = "problems.csv"; 
    ifstream file(input_fileName); // reads in file 

    if (file.fail()){
        cerr << "File cannot be opened for reading. " << endl;
        exit(1);
    }
    string junk; 
    //getline(fin, junk); // gets first line ignores it 
        
    // two arrays : 
// 20 is the capacity of our equation array and answer array
    const int Size = 20; 
    string Equations[Size]; // list of all equations
    double Answer_arrays[Size];  // list of all answers

    //correct, total, user input and count for the number of questions. 
   
 
    double user_input;  // reads in user input value as a double integer type  // we set it to double so we can calculate decimal percentages
   

    // double percentage
   

    // set bool 
    //bool check_for_percentage = false; 
    
    // read questions in from the file using for loop 
    string Stream_Answer;
    string line_file1;
    string Questions_file;
    int questions_remaining = 0; //bs array
    while(getline(file,line_file1)){
        //cout<< fileline << "\n";
        // now to retrieve the data we want to use getline for each index in the array
        stringstream filelinePart(line_file1);
        getline(filelinePart, Questions_file, ','); 
        Equations[questions_remaining] = Questions_file;
        getline(filelinePart, Stream_Answer); 
        double answer = stod(Stream_Answer); //bs array
        Answer_arrays[questions_remaining] = answer; 
        questions_remaining++;    
        

    }

    
    file.close(); 


   

    srand(time(NULL)); 
    int count = 0; 
    double percentage = 0;
    int questionstotal = questions_remaining;  
    double correct_num = 0; 

    while ((percentage) < 60 && (questions_remaining > 0)){
        
        
        int index = rand () % questions_remaining; 

        
        
        swap(Equations[index], Equations[questions_remaining -1]);
        swap(Answer_arrays[index], Answer_arrays[questions_remaining -1]); 
        
        
        cout << "(" << count+1 << ")" << "what is " << Equations[questions_remaining-1] << "?" << " "; 
        cin >> user_input;

       

        if (user_input == Answer_arrays[questions_remaining-1]){ // 
            cout << "true" << endl; 
            correct_num++; 
            percentage = (correct_num / questionstotal)*100;
        }
        else{
            cout << "false" << endl; 
        }
        cout << endl; 
        count++; 
        questions_remaining--;
        
    
    if (percentage >= 60){
        cout << "At least " << percentage << "%" << " " << "is" << " " << "correct." << " " << "Stop." << endl;
        }
   
    }
  cout << "percentage correct: " << percentage << "%";
  return 0; 
 }

 // two while loops
 //if statemensts