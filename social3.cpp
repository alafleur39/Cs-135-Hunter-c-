#include <iostream>
#include <string>
using namespace std;

struct Profile {
    string username;
    string displayname;
};

class Network {
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];
    int findID(string usrn);

public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();
};

Network::Network() {
    numUsers = 0;
    // Initialize the friendship matrix to false
    for (int i = 0; i < MAX_USERS; ++i) {
        for (int j = 0; j < MAX_USERS; ++j) {
            following[i][j] = false;
        }
    }
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

void Network::printDot() {
    cout << "digraph {" << endl;
    // Print usernames
    for (int i = 0; i < numUsers; ++i) {
        cout << "  \"@" << profiles[i].username << "\"" << endl;
    }
    // Print friendship connections
    for (int i = 0; i < numUsers; ++i) {
        for (int j = 0; j < numUsers; ++j) {
            if (following[i][j]) {
                cout << "  \"@" << profiles[i].username << "\" -> \"@" << profiles[j].username << "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
