#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    int start = 200005, goal = 0;
    cin >> s;
    rep(i, s.size()) {
        if (s[i] == 'A') {
            start = min(i, start);
        } 
        if (s[i] == 'Z') {
            goal = max(i, goal);
        }
    }
    cout << abs(start-goal) + 1 << endl;

    return 0;
}
