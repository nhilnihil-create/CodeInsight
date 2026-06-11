//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 3e5 + 100;
const int LOG = 20;
const int mod = 1e9 + 7;
const int MX = 1e5 + 100;
typedef long long li;
const li MOD = 1000000000949747713ll;


int x[MAXN];
int up[MAXN][LOG];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    int L;
    cin >> L;

    for (int i = 1; i <= n; ++i) {
        if (abs(x[n] - x[i]) <= L) {
            up[i][0] = n;
        } else {
            int id = lower_bound(x + 1, x + n + 1, x[i] + L + 1) - x;
            up[i][0] = id - 1;
        }
    }
    for(int j=1;j<LOG;++j){
        for(int i=1;i<=n;++i){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin>> a>> b;
        if(a  > b)
            swap(a,b);
        int ans = 0;
        for(int i = LOG-1;i>=0;--i){
            if(up[a][i] < b){
                a = up[a][i];
                ans+=(1<<i);
            }
        }
        cout << ans+1<<"\n";
    }


}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#else

#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int t = 1;
    while (t--)
        solve();
    dout << endl << "time : " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}