#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<double, int> pdbi;
typedef pair<int,pii> pipii;
typedef pair<ll,pll> plpll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vector<int>> mat;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const int INF = 1<<30;
const ll mod = 1000000000 + 7;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

#define addm(X, Y) (X) = ((X) + ((Y) % mod) + mod) % mod

int n, k;
int a[100000 + 5], b[100000 + 5];

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    int mask = (1 << 31) - 1LL;
    rep(i, 33) {
        if (!((k>>i) & 1) && i != 0) continue;
        int tmp = k;
        if (i == 0) {
            tmp = k;
        }
        else {
            tmp ^= (1<<i); tmp |= (1<<i) - 1LL; tmp &= mask;
        }
        int v = 0;
        rep(l, n) {
            if (a[l] > tmp) continue;
            bool ok = true;
            rep(j, 33) {
                if ((a[l]>>j) & 1) {
                    if (!((tmp>>j) & 1)) {
                        //cout << j << endl;
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                v += b[l];
            }
        }
        ans = max(ans, v);
    }
    cout << ans << endl;
}
