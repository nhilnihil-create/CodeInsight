// Date: 2020-04-03

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define IO freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout)
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define D(x) cout << #x << " = " << x << endl;
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)x.size())
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

LL fac[N], inv[N], a[N], ans[N];
int cnt[N];

LL C(int x, int y) {
    if(x < y || y < 0) return 0;
    return fac[x] * inv[y] % mod * inv[x-y] % mod;
}

void add(LL& x, LL y) {
    x = (x + y) % mod;
}

int main() {
    FIO;
    fac[0] = inv[0] = 1;
    rep(i, 1, N-1) fac[i] = fac[i-1] * i % mod, inv[i] = qpow(fac[i], mod-2, mod);
    int n;
    cin >> n;
    int v = 0;
    rep(i, 1, n+1) {
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] == 2) v = a[i];
    }
    int x = -1, y = -1;
    rep(i, 1, n+1) if(a[i] == v) {
        if(x == -1) x = i;
        else y = i;
    }
    rep(i, 1, n+1) {
        add(ans[i], C(n-1, i));
        add(ans[i], 2*C(n-1, i-1)%mod);
        add(ans[i], -C(x+n-y, i-1)+mod);
        add(ans[i], C(n-1, i-2));
    }
    rep(i, 1, n+1) cout << ans[i] << endl;

    return 0;
}