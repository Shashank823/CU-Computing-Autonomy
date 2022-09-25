#include <stdlib.h>
#include <iostream>
using namespace std;

// returns true if input character q is puctuation, else false
bool ispunctuation(char q) {
    
    if (q == '!' || q == '\"' || q == '#' || q == '$' || q == '%' || q == '&' || 
    q == '\'' || q == '(' || q == ')' || q == '*' || q == '+' || q == ',' || q == '-' || 
    q == '.' || q == '/' || q == ':' || q == ';' || q == '<' || q == '=' || q == '>' || 
    q == '?' || q == '@' || q == '[' || q == '\\' || q == ']' || q == '^' || 
    q == '`' || q == '{' || q == '|' || q == '}')
        return true;

    return false;
}

char* modifyAndCopy(char *raw_input) {
    
    char* newCopy = new char[80];
    int n = 0;
    for (int i = 0; i < 80; i++) {
        if (ispunctuation(raw_input[i])) {
            continue;
        }
        newCopy[n] = raw_input[i];
        n++;
    }
    return newCopy;
}

char* modifyInPlace(char *raw_input) {
    int n = 0;
    for (int i = 0; i < 80; i++) {
        if (ispunctuation(raw_input[i])) {
            continue;
        }
        raw_input[n] = raw_input[i];
        n++;
    }
    return raw_input;
}

int main() {
    // user input
    char raw_input[80] = {0};
    cout << "Please input something with punctuation in it: ";
    cin.getline(raw_input,80);

    cout << "Modify and Copy: " << endl;
    cout << "Original: " << raw_input << endl;
    cout << "Modified: " << modifyAndCopy(raw_input) << endl << endl;

    cout << "Modify in Place: " << endl;
    cout << "Original: " << raw_input << endl;
    cout << "Modified: " << modifyInPlace(raw_input) << endl;
}
