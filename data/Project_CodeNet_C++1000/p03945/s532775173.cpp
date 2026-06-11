#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int change = 0;
    for (size_t i = 1; i < s.length(); i++) {
        if (s.at(i - 1) != s.at(i)) {
            change++;
        }
    }
    cout << change << endl;
    return 0;
}
