#include <iostream>
#include <string>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;


int main(void) {
    string s;
    cin >> s;
    if (s[0] == '9' || s[1] == '9') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
