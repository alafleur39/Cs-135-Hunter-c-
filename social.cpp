#include <iostream>
#include <vector>
using namespace std;
// follow instructions above   // object oriented programmming is very effective
class Profile { 
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn)
    {
         username = usrn;
         displayname = dspn;
    }

    // Default Profile constructor (username="", displayname="")
    Profile()
    {
      username = "";
      displayname = "";
    }
    // Return username
    string getUsername(){ // getter function  // getter and setter functions are used for private member data variables
         return username;


    }
    // Return name in the format: "displayname (@username)"
    string getFullName(){     // we need to review string concaetention in c++
        return displayname + " (@" + username + ")";
    }
    // Change display name
    void setDisplayName(string dspn)
    {
       // no need to prompt user input because we taking input passed as our parameter
       displayname = dspn; // set displayname to our parameter
    }
};


int main() {  // int main for the purpose of testing our function
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}