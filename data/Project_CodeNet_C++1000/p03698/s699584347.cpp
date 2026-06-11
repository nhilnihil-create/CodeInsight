#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> c;
    rep(i, s.size()) c.insert(s[i]);

    if (s.size() == c.size())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
