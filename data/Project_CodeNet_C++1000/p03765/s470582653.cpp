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
const int MAXN = 100005, MAXM = 200010;
// code
//#define int long long
/*
 * A -> BB -> AAAA
 * AB -> AAA -> ""
 * AAA -> BBBBA -> BA
 * 3A, 7B ->
 */
int freS[MAXN][2], freT[MAXN][2];
void Solve() {
  	string s, t;
  	cin >> s >> t;
  	for (int i = 0; i < s.length(); i++){
        freS[i+1][0] = freS[i][0] + (s[i] == 'A');
        freS[i+1][1] = freS[i][1] + (s[i] == 'B');
  	}
  	for (int i = 0; i < t.length(); i++){
        freT[i+1][0] = freT[i][0] + (t[i] == 'A');
        freT[i+1][1] = freT[i][1] + (t[i] == 'B');
  	}
  	int q; cin >> q;
  	while(q--){
        int a,b,c,d,x,y,z,t;
        cin >> x >> y >> z >> t;
        a = freS[y][0] - freS[x-1][0];
        b = freS[y][1] - freS[x-1][1];
        c = freT[t][0] - freT[z-1][0];
        d = freT[t][1] - freT[z-1][1];
        //cout << "A: " << a << ' ' << c << endl;
        //cout << "B: " << b << ' ' << d << endl;
        a %= 3;
        b %= 3;
        c %= 3;
        d %= 3;
        bool f = false;
        for (int i = 0; i < 3; i++){
            if ((a+i)%3 == c && (b+i)%3 == d){
                f = true;
            }
        }
        cout << (f ? "YES\n" : "NO\n");
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
