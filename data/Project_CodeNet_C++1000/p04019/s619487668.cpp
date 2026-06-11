#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
 
int a[4];
 
int main()
{
    string s;
    cin >> s;
    rep(i, s.size()) {
        if(s[i] == 'N') {
            a[0]++;
        }
        else if(s[i] == 'S') {
            a[1]++;
        }
        else if(s[i] == 'E') {
            a[2]++;
        }
        else a[3]++;
    }
    string ans = "Yes";
    if(a[0]!= 0) {
        if(a[1] == 0) ans = "No";
    }
    if(a[1]!= 0) {
        if(a[0] == 0) ans = "No";
    }
    if(a[2]!= 0) {
        if(a[3] == 0) ans = "No";
    }
    if(a[3]!= 0) {
        if(a[2] == 0) ans = "No";
    }
    cout << ans << endl;
    return 0;
}