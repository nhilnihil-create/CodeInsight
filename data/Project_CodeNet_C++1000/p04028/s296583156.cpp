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

int s[MAXN], t[MAXN];

ll dp[5010][5012];
ll bin_pow(ll a,int n){
    ll res = 1;
    while(n){
        if(n&1){
            res = (res * a)%mod;
        }
        a = (a*a)%mod;
        n>>=1;
    }
    return res;
}
void solve() {
   int n;
   cin >> n;
   string s;
   cin >>s;
   int m = sz(s);
   dp[0][0] = 1;

   for(int i=1;i<=n;++i){
       for(int j=0;j<=n;++j){
           if(j > 0)
               dp[i][j] += dp[i-1][j-1] * 2;
           else
               dp[i][j] += dp[i-1][j];
           dp[i][j] += dp[i-1][j+1];
           dp[i][j]%=mod;
       }
   }

   ll ans = dp[n][m];

   dout <<"ans "<<ans<<endl;
   ll pw = 1ll * m * (mod - 2);
   pw = pw%(mod-1);
   dout <<"pw "<<pw<<endl;
   ans = ans * bin_pow(2,pw);
   ans%=mod;
   cout << ans;

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