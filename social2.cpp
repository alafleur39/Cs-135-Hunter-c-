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


class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn)  // we need to return -1
  {
     for (int i = 0; i < numUsers; ++i)
     {
        if (profiles[i].getUsername()==usrn) // Assuming getUsername() returns the username of the profile at index i
        {
            return i; // Return the index of the profile if the username matches
        }
        
     }
     return -1; // return -1 if the username not found
     
  }
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network(){
    numUsers = 0;
  }
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn,string dspn){
    if (numUsers < MAX_USERS && findID(usrn)== -1)
    {
        for (int j = 0; j < usrn.length(); j++)
        {
            if (!isdigit(usrn[j])&& !isalpha(usrn[j]))
            {
                return false;
            }
            
        }
        Profile addition(usrn,dspn);
        profiles[numUsers] = addition;
        numUsers++;
        return true;
        
    }
    else{
        return false; 
    }
    
}
};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     
  cout << nw.addUser("luigi", "Luigi") << endl;     

  cout << nw.addUser("mario", "Mario2") << endl;    
  cout << nw.addUser("mario 2", "Mario2") << endl;  
  cout << nw.addUser("mario-2", "Mario2") << endl;  

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i),
                 "Mario" + to_string(i)) << endl;   

  cout << nw.addUser("yoshi", "Yoshi") << endl; 
}