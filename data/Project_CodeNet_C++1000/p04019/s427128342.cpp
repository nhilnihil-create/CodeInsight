#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<bool> angle(4);
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == 'E') angle[0] = true;
        if (s[i] == 'W') angle[1] = true;
        if (s[i] == 'N') angle[2] = true;
        if (s[i] == 'S') angle[3] = true;
    }
    bool ans = true;
    if ((angle[0] != angle[1]) || (angle[2] != angle[3])) ans = false;
    cout << (ans ? "Yes" : "No") << endl;
}