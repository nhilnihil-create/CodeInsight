#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string ans = "yes";
    rep(i, s.size()) {
        repl(j, i + 1, s.size()) {
            if(s[i] == s[j]) {
                ans = "no";
            }
        }
    }
    cout << ans << endl;
    return 0;
}