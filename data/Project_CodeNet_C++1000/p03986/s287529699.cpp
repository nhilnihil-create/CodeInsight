#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;  cin >> t;
    stack<char> s;
    for (int i = 0; i < (int)t.size(); ++i) {
        if (!s.empty() && s.top() == 'S' && t[i] == 'T') s.pop();
        else s.push(t[i]);
    }
    cout << s.size() << endl;
}
