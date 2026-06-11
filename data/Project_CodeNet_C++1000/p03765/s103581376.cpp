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

const int N = 1e5 + 10;

string s[2];
int pref[2][N];

void compute_pre() {
    REP(which, 2) {
        pref[which][0] = (s[which][0] == 'A' ? 1 : 2);
        FOR(i, 1, s[which].size()) {
            pref[which][i] = msum(pref[which][i-1], (s[which][i] == 'A' ? 1 : 2));
        }
    }
}

int getsum(int l, int r, int which) {
    int ret = pref[which][r];
    if(l > 0) {
        ret = mdif(ret, pref[which][l-1]);
    }
    return ret;
}

int main() {
    cin >> s[0] >> s[1];
    compute_pre();
    int q; cin >> q;
    while(q--) {
        int ls, rs, lt, rt;
        cin >> ls >> rs >> lt >> rt;
        ls--, rs--, lt--, rt--;
        cout << (getsum(ls, rs, 0) == getsum(lt, rt, 1) ? "YES\n" : "NO\n");
    }
}




























