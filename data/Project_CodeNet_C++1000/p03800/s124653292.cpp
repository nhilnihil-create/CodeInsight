#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string ans = "";
    bool t = false;
    rep(i,4){
        if (t) break;
        t = true;
        if (i >> 0 & 1) ans += 'S';
        else ans += 'W';
        if (i >> 1 & 1) ans += 'S';
        else ans += 'W';
        rep(i,n-2){
            if (s[i+1] == 'o' && ans[i+1] == 'S') ans += ans[i];
            else if (s[i+1] == 'x' && ans[i+1] == 'W') ans += ans[i];
            else {
                if (ans[i] == 'W') ans += 'S';
                else ans += 'W';
            }
        }
        if (ans[0] == 'S' && s[0] == 'o' && ans[1] == ans[n-1]){
            if (ans[n-1] == 'S' && s[n-1] == 'o' && ans[0] == ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'W' && s[n-1] == 'x' && ans[0] == ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'S' && s[n-1] == 'x' && ans[0] != ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'W' && s[n-1] == 'o' && ans[0] != ans[n-2]) cout << ans << endl;
            else {
                ans = "";
                t = false;
            }
        }
        else if (ans[0] == 'W' && s[0] == 'x' && ans[1] == ans[n-1]){
            if (ans[n-1] == 'S' && s[n-1] == 'o' && ans[0] == ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'W' && s[n-1] == 'x' && ans[0] == ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'S' && s[n-1] == 'x' && ans[0] != ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'W' && s[n-1] == 'o' && ans[0] != ans[n-2]) cout << ans << endl;
            else {
                ans = "";
                t = false;
            }
        }
        else if (ans[0] == 'S' && s[0] == 'x' && ans[1] != ans[n-1]){
            if (ans[n-1] == 'S' && s[n-1] == 'o' && ans[0] == ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'W' && s[n-1] == 'x' && ans[0] == ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'S' && s[n-1] == 'x' && ans[0] != ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'W' && s[n-1] == 'o' && ans[0] != ans[n-2]) cout << ans << endl;
            else {
                ans = "";
                t = false;
            }
        }
        else if (ans[0] == 'W' && s[0] == 'o' && ans[1] != ans[n-1]){
            if (ans[n-1] == 'S' && s[n-1] == 'o' && ans[0] == ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'W' && s[n-1] == 'x' && ans[0] == ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'S' && s[n-1] == 'x' && ans[0] != ans[n-2]) cout << ans << endl;
            else if (ans[n-1] == 'W' && s[n-1] == 'o' && ans[0] != ans[n-2]) cout << ans << endl;
            else {
                ans = "";
                t = false;
            }
        }
        else {
            ans = "";
            t = false;
        }
    }
    if (!t) cout << -1 << endl;
}