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

int n,ans[20000][2];

signed main() {
    cin >> n;
    rep(i,n) ans[i][0] = (i+1)*20000, ans[i][1] = (n-i)*20000;
    rep(i,n) {
        int p;
        cin >> p;--p;
        ans[p][0] += i;
    }
    rep(i,n) cout << ans[i][0] << " ";cout << endl;
    rep(i,n) cout << ans[i][1] << " ";cout << endl;
}


