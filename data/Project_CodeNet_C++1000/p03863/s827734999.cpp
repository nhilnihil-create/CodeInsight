#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    string s;
    cin >> s;
    bool even = false, palin = false;

    if (s.size() % 2 == 0) even = true;
    if (s[0] == s[s.size()-1]) palin = true;

    if (palin && even) cout << "First" << endl;
    if (palin && !even) cout << "Second" << endl;
    if (!palin && !even) cout << "First" << endl;
    if (!palin && even) cout << "Second" << endl;

}