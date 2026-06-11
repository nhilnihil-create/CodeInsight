#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

string target[4] = { "dream", "dreamer", "erase", "eraser" };

int main() {
    string s;
    cin >> s;
    for (string &t : target) reverse(t.begin(), t.end());
    reverse(s.begin(), s.end());
    while (s.size() >= 5) {
        if (s.substr(0,5) == target[0]) { s = s.substr(5); continue; }
        if (s.substr(0,7) == target[1]) { s = s.substr(7); continue; }
        if (s.substr(0,5) == target[2]) { s = s.substr(5); continue; }
        if (s.substr(0,6) == target[3]) { s = s.substr(6); continue; }
        cout << "NO" << endl;
        return 0;
    }
    cout << (s == "" ? "YES" : "NO") << endl;
    return 0;
}