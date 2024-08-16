#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift)
{
    if (isalpha(c))   // we are using this if statement to check if our character is alphanumeric
    {
        char base = (isupper(c)) ? 'A' : 'a';  // we are checking if alphanumeric is capital //condition ? value_if_true : value_if_false
        return (c - base + rshift) % 26 + base;   // this right here implements the shifting
    }
    else
    {
        return c; // if it's not an alphanumeric character, leave it unchanged
    }
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift)
{
    string result = ""; // Create an empty string to store the shifted characters
    for (int i = 0; i < plaintext.length(); i++)
    {
        result += shiftChar(plaintext[i], rshift); // Shift each character using the ShiftChar method
    }
    return result;
}

int main()
{
    // Code for main function (not provided, but assumed to exist)
    return 0;
}
