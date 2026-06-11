#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, a, b) for (ll i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())
#define PRINT(V) for (auto v:(V)) {cerr << v << " ";} cerr << endl
#define dump(x) cerr << #x << " : " << (x) << endl
#define dump2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
inline ll GCD(ll a, ll b){return b ? GCD(b, a % b) : a;}
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
/* END OF TEMPLATE */

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string ans[4] = {"SS", "SW", "WS", "WW"};
    rep(i, 4){
        repr(j, 1, n+1){
            bool f1 = (ans[i][j-1] == 'W');
            bool f2 = (ans[i][j] == 'W');
            bool f3 = (s[j%n] == 'x');
            ans[i] += ((f1^f2^f3) ? 'W' : 'S');
        }
        if(ans[i][n] == ans[i][0] && ans[i][n+1] == ans[i][1]){
            ans[i].pop_back();
            ans[i].pop_back();
            cout << ans[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}