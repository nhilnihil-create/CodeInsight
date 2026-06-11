#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int a[26];

int main()
{
    string s;
    cin >> s;
    rep(i, s.size()) {
        a[s[i] - 'a']++;
    }
    rep(i, 26) {
        if(a[i] == 0) {
            cout << (char) (i + 'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}