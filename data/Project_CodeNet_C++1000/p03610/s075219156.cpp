// OddString
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    string odd_string = "";
    cin >> s;
    for (int i = 1; i <= s.size(); ++i) {
        if (i % 2 == 1) odd_string += s[i-1];
    }
    cout << odd_string << endl;
}