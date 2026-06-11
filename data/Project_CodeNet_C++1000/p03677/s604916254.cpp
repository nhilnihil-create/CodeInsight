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

#define mid ((l + r) >> 1)
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define lson lc, l, mid
#define rson rc, mid+1, r

int n, m;
LL add[N<<2], val[N<<2];

void pd(int rt) {
    if(add[rt]) {
        add[lc] += add[rt], val[lc] += add[rt];
        add[rc] += add[rt], val[rc] += add[rt];
        add[rt] = 0;
    }
}

void update(int rt, int l, int r, int ql, int qr, int v) {
    if(ql <= l && r <= qr) {
        add[rt] += v;
        val[rt] += v;
        return;
    }
    pd(rt);
    if(ql <= mid) update(lson, ql, qr, v);
    if(qr > mid) update(rson, ql, qr, v);
}

LL ask(int rt, int l, int r, int x) {
    if(l == r) return val[rt];
    pd(rt);
    if(x <= mid) return ask(lson, x);
    else return ask(rson, x);
}

int a[N], cnt[N];

LL cal(int x) {
    return -ask(1, 1, 2*m-1, x) + 1LL*cnt[x]*x;
}

int main() {
    FIO;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    LL ans = 0;
    rep(i, 1, n-1) {
        int l = a[i], r = a[i+1];
        if(l > r) r += m;
        ans += r-l;
        if(l+1 < r) {
            update(1, 1, 2*m-1, l+2, r, l+1);
            cnt[l+2]++, cnt[r+1]--;
        }
    }
    rep(i, 1, 2*m) cnt[i] += cnt[i-1];
    LL mx = 0;
    rep(i, 1, m) {
        LL val = cal(i);
        if(i < m) val += cal(i+m);
        chkmax(mx, val);
    }
    ans -= mx;
    cout << ans;


    return 0;
}