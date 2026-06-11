#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;


int main(void) {
    string s, t;
    cin >> s;
    t = s;
    std::reverse(s.begin(), s.end());
    if (s == t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
