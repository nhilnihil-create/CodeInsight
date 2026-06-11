#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

const int mod = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s[2];
    rep(i, 2) cin >> s[i];
    int x = 0;
    ll ans = 3;
    
    if ((x < (n - 1)) && (s[0][x] == s[0][x + 1]) && (s[1][x] == s[1][x + 1])) {
        ans = 6;
    }
    
    while(x < (n - 1)) {
        if ((x < (n - 1)) && (s[0][x] == s[1][x]) && (s[0][x + 1] == s[1][x + 1])) {
            if (x == 0) {
                ans = 6;
            }
            else {
                ans = ans * 2 % mod;
            }
            
            x++;
        }
        else if ((x < (n - 2)) && (s[0][x] == s[0][x + 1]) && (s[1][x] == s[1][x + 1]) && (s[0][x + 2] == s[1][x + 2])) {
            if (x == 0) {
                ans = 6;
            }
            
            x += 2;
        }
        else if ((x < (n - 2)) && (s[0][x] == s[1][x]) && (s[0][x + 1] == s[0][x + 2]) && (s[1][x + 1] == s[1][x + 2])) {
            if (x == 0) {
                ans = 6;
            }
            else {
                ans = ans * 2 % mod;
            }
            
            x++;
        }
        else if ((x < (n - 3)) && (s[0][x] == s[0][x + 1]) && (s[1][x] == s[1][x + 1]) && (s[0][x + 2] == s[0][x + 3]) && (s[1][x + 2] == s[1][x + 3])) {
            if (x == 0) {
                ans = 18;
            }
            else{
                ans = ans * 3 % mod;
            }
            
            x += 2;
        }
        else {
            x += 2;
        }
    }
    
    cout << ans << endl;
    return 0;
}
