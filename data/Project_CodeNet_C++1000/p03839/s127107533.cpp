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


int n,k,a,b[100001],c[100001],sum,ans;


signed main() {
    cin >> n >> k;
    rep1(i,n) {
        cin >> a;
        if (a > 0) sum += a, b[i] = a;
        else c[i] = -a;
        b[i] += b[i-1], c[i] += c[i-1];
    }
    repo(i,k,n+1) ans = max(ans, sum-min(b[i]-b[i-k],c[i]-c[i-k]));
    cout << ans << endl;
}


