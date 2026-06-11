#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end())
#define vdelete(v) (v).erase(unique(all(v)), (v).end())
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1000000007
#define INF LONG_LONG_MAX

int n,t[100000],a[100000],memo[100000],limit[100000],ans=1;

signed main() {
    cin >> n;
    rep(i,n) memo[i] = -1, limit[i] = INF;
    rep(i,n) cin >> t[i], limit[i] = min(limit[i], t[i]);
    rep(i,n) cin >> a[i], limit[i] = min(limit[i], a[i]);
    memo[0] = t[0];
    memo[n-1] = a[n-1];
    rep11(i,n) if (t[i] != t[i-1]) memo[i] = t[i];
    repm(i,n-1) if (a[i+1] != a[i]) memo[i] = a[i];
    rep(i,n) if (memo[i] == -1) ans = (ans*limit[i])%MOD;
    rep(i,n) if (memo[i] != -1 && memo[i] != min(a[i], t[i])) {
        cout << 0 << endl;
        return 0;
    }
    if (a[0] != t[n-1]) cout << 0 << endl;
    else cout << ans << endl;
}


