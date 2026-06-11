#include<bits/stdc++.h>
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
#define INF LONG_LONG_MAX
#define MOD 1000000007
#define yn(f) cout << (f ? "Yes" : "No") << endl;
#define YN(f) cout << (f ? "YES" : "NO") << endl;

int n,ans;
vector<pair<int,int>> v;
set<int> s;

signed main() {
    cin >> n;
    rep(i,n) {
        int a;
        cin >> a;
        v.pb(mp(a,i));
    }
    sort(all(v));
    s.insert(-1);
    s.insert(n);
    rep(i,n) {
        int a = v[i].fi, idx = v[i].se;
        int l = (idx - *(--s.lower_bound(idx)));
        int r = (*s.upper_bound(idx) - idx);
        ans += l*r*a;
        s.insert(idx);
    }
    cout << ans << endl;
}


