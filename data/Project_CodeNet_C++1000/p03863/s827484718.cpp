#include <bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == s[n - 1]) cout << (n & 1 ? "Second" : "First") << endl;
    else cout << (n & 1 ? "First" : "Second") << endl;
    return 0;
}