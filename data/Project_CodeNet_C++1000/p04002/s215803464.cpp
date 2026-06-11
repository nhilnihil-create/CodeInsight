// Date: 2020-03-21

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define FIO ios::sync_with_stdio(false);cin.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define D(x) cout<<#x<<" = "<<x<<endl;
#define SZ(x) ((int)x.size())
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

set<pii> st;
LL cnt[10], n, m, q;
pii a[N];

const int xx[] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
const int yy[] = {0, 1, 2, 3, 1, 2, 3, 1, 2, 3};

void cal(int x, int y) {
    rep(i, 1, 9) {
        int f = 1, t = 0;
        rep(j, 1, 9) if(j != i) {
            int nx = x + xx[j]-xx[i], ny = y + yy[j]-yy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                f = 0;
                break;
            }
            if(st.count(mk(nx, ny))) t++;
        }
        if(f) cnt[t]--, cnt[t+1]++;
    }
}

int main() {
    FIO;
    cin >> n >> m >> q;
    cnt[0] = (n-2) * (m-2);
    rep(i, 1, q) cin >> a[i].fi >> a[i].se;
    sort(a+1, a+1+q);
    rep(i, 1, q) {
        cal(a[i].fi, a[i].se);
        st.insert(a[i]);
    }
    rep(i, 0, 9) cout << cnt[i] << '\n';

    return 0;
}