#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    str[5] = str[13] = ' ';
    
    cout << str << endl;


    return 0;
    
}