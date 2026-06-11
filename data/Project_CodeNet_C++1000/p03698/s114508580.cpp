#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    string s;
    cin >> s;
    vector<char> data(s.size());
    for (int i = 0; i < s.size(); i++) {
        data.at(i) = s.at(i);
    }
    bool finished = false;
    for (int now = 0; now < s.size(); now++) {
        for (int i = 0; i < s.size(); i++) {
            if (now == i) {
                continue;
            }
            if (data.at(now) == data.at(i)) {
                ans = 1;
                finished = true;
                break;    
            }
        }
        if (finished) {
            break;
        }
    }
    if (ans == 1) {
        cout << "no" << endl;
    }
    else {
        cout << "yes" << endl;
    }
}