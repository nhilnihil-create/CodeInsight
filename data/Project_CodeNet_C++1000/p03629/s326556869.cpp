#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
#define pw(x) (1LL<<(x))
static const int fast_io = [](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
static const int precise_doubles = [](){cout<<fixed<<setprecision(20);return 0;}();
typedef pair<int, int> PII;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(k) - iterator to kth largest, order_of_key(k) - #things < k
typedef long double LD;
typedef long long LL;
#define EVAL(x) x
#define SPA(x) EVAL({cout << #x" = " << x << ' ';})
#define NEWL EVAL({cout << '\n';})
#define SPAR(a, b) EVAL({cout<<#a" = ";for(auto it=a;it!=b;)cout<<*(it++)<<" ";cout<<'\n';})
#define SPAV(v) EVAL({cout<<#v" = ";for(auto it=v.begin();it!=v.end();)cout<<*(it++)<<" ";cout<<'\n';})
const int INF = 0x3f3f3f3f; // 1.0e9
const LL LINF = 0x3f3f3f3f3f3f3f3fll; // 4.5e18
const LD eps = 1e-20;
const int mod = 3;
inline int msum(int x, int y) {return (x+y<mod ? x+y : x+y-mod);}
inline int mdif(int x, int y) {return (x>=y ? x-y : x-y+mod);}
inline int mprod(int x, int y) { return (1ll*x*y) % mod; }
inline int mpow(int x, LL y) {LL r=1;while(y){if(y&1)r=mprod(r,x);x=mprod(x,x);y>>=1;}return r;}
inline int minv(int x) { return mpow(x, mod-2); }
#define DIE EVAL({cout << -1 << '\n'; exit(0);})
//------------------------------------------------------------------------------------------------------

const int N = 2e5 + 10;
int n;
string s;
int first_occ[26][N];
int dp[N], a[N];

int main() {
    cin >> s;
    n = s.size();
    REP(i, n) a[i] = s[i] - 'a';

    REP(c, 26) {
        first_occ[c][n] = n;
        for(int i = n-1; i >= 0; i--) {
            if(a[i] == c) {
                first_occ[c][i] = i;
            } else {
                first_occ[c][i] = first_occ[c][i+1];
            }
        }
    }

    dp[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        int farthest = 0;
        REP(c, 26) {
            farthest = max(farthest, first_occ[c][i]);
        }
        dp[i] = 1 + dp[farthest+1];
    }

    string ans = "";

    for(int i = 0; i < n; ) {
        REP(c, 26) {
            if(dp[i] == 1 + dp[first_occ[c][i] + 1]) {
                ans += char('a' + c);
                i = first_occ[c][i] + 1;
                break;
            }
        }
    }

    cout << ans << '\n';
}




























