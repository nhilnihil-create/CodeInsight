#include <iostream>
#include <string>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    string s;
    cin >> s;
    s[5] = ' ';
    s[13] = ' ';
    cout << s << endl;
    return 0;
}
