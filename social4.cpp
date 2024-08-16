#include <iostream>
#include <string>
using namespace std;
//tong yi
//andy
//struct
//profile
//

struct Profile {
    string username;
    string displayname;
};

struct Post {
    string username;
    string message;
};

class Network {
private:
    static const int MAX_USERS = 20;
    static const int MAX_POSTS = 100;
    int numUsers;
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];
    int numPosts;
    Post posts[MAX_POSTS];
    int findID(string usrn);

public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();
    bool writePost(string usrn, string msg);
    bool printTimeline(string usrn);
};

Network::Network() {
    numUsers = 0;
    numPosts = 0;
}

int Network::findID(string usrn) {
    for (int i = 0; i < numUsers; ++i) {
        if (profiles[i].username == usrn) {
            return i;
        }
    }
    return -1;
}

bool Network::addUser(string usrn, string dspn) {
    if (numUsers >= MAX_USERS) {
        return false;
    }
    profiles[numUsers].username = usrn;
    profiles[numUsers].displayname = dspn;
    numUsers++;
    return true;
}

bool Network::follow(string usrn1, string usrn2) {
    int id1 = findID(usrn1);
    int id2 = findID(usrn2);
    if (id1 == -1 || id2 == -1) {
        return false;
    }
    following[id1][id2] = true;
    return true;
}

bool Network::writePost(string usrn, string msg) {
    int id = findID(usrn);
    if (id == -1 || numPosts >= MAX_POSTS) {
        return false;
    }
    posts[numPosts].username = usrn;
    posts[numPosts].message = msg;
    numPosts++;
    return true;
}

bool Network::printTimeline(string usrn) {
    int id = findID(usrn);
    if (id == -1) {
        return false;
    }

    for (int i = numPosts - 1; i >= 0; --i) {
        if (posts[i].username == usrn) {
            cout << profiles[id].displayname << " (@" << usrn << "): " << posts[i].message << endl;
        } else {
            for (int j = 0; j < numUsers; ++j) {
                if (following[id][j] && posts[i].username == profiles[j].username) {
                    cout << profiles[j].displayname << " (@" << posts[i].username << "): " << posts[i].message << endl;
                }
            }
        }
    }
    return true;
}

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}