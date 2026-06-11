#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

LL sum[N];
int main() {
    int n;
    cin >> n;
    rep(i, 1, n) {
        LL x; cin >> x;
        sum[i] = sum[i-1] + x;
    }
    LL ans = INF;
    rep(i, 1, n-1) ans = min(ans, abs(sum[i]-(sum[n]-sum[i])));
    cout << ans << endl; 

    system("pause");
    return 0;
}