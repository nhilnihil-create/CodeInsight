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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const ll INF = 1<<30;
const ll mod = 1000000000 + 7;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

#define addm(X, Y) ((X) = ((X) + (Y) % mod) % mod)

int n;
int a[100000 + 5];

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i, n) cin >> a[i];
    int ans = 0;
    ans += a[0] - 1;
    int mn = 2;
    rep2(i, 1, n) {
        if (a[i] == mn) mn += 1;
        else if (a[i] > mn) {
            if (a[i] % mn == 0) {
                ans += a[i] / mn - 2;
                ans++;
            }
            else ans += a[i] / mn;
        }
    }
    cout << ans << endl;
}
