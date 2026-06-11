#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<string> a = {"dream", "dreamer", "erase", "eraser"};

    for (int i = 0; i < 4; i++) {
        reverse(a.at(i).begin(), a.at(i).end());
    }

    while (!s.empty()) {
        if (s.substr(0, 5) == a.at(0) || s.substr(0, 5) == a.at(2)) {
            s.erase(0, 5);
        }

        else if (s.substr(0, 7) == a.at(1)) {
            s.erase(0, 7);
        }

        else if (s.substr(0, 6) == a.at(3)) {
            s.erase(0, 6);
        }

        else {
            break;
        }
    }

    if (s.empty()) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
}