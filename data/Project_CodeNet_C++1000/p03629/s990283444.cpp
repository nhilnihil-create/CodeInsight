/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 1e5 + 5, MAXM = 2e5 + 5;
// code
//#define int long long

int dp[MAXM][26], go[MAXM][26];
string s;
void Solve() {
    cin >> s;
    int n = s.length();
    for (int j = 0; j < 26; j++){
        go[n][j] = n;
    }
    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < 26; j++){
            dp[i][j] = dp[i+1][j];
            if ((s[i] - 'a') == j){
                go[i][j] = i;
                dp[i][j] = *min_element(dp[i+1], dp[i+1] + 26) + 1;
            }else{
                go[i][j] = go[i+1][j];
                dp[i][j] = dp[i+1][j];
            }
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    int ln = *min_element(dp[0], dp[0] + 26);
    //cout << ln << endl;
    int r = 0;
    while(ln >= 0){
        int c = min_element(dp[r], dp[r] + 26) - dp[r];
        if (dp[r][c] == ln){
            ln --;
            cout << (char) (c + 'a');
            r = go[r][c];
        }
        r ++;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO;
    int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/
