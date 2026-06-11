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
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1000000007
#define INF LONG_LONG_MAX

int h,w,n,d[3]={1,0,-1},ans[10];
map<pair<int,int>,int> m;

signed main() {
    cin >> h >> w >> n;
    rep(k,n) {
        int a,b;
        cin >> a >> b;
        rep(i,3) rep(j,3) if (0 < a+d[i] && a+d[i] <= h && 0 < b+d[j] && b+d[j] <= w) m[mp(a+d[i], b+d[j])]++;
    }
    int hoge = 0;
    ans[0] = (h-2)*(w-2);
    for(auto i : m) if (1 < i.fi.fi && i.fi.fi < h && 1 < i.fi.se && i.fi.se < w) ans[i.se]++, hoge++;
    ans[0] -= hoge;
    rep(i,10) cout << ans[i] << endl;
}
