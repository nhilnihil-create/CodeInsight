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

int n,m,q,ans[100000],memo[100000];
vector<int> v[100000];
stack<pair<int,pair<int,int>>> st;

void kr(int a, int d, int c) {
    if (ans[a] && memo[a] >= d) return;
    memo[a] = d;
    if (!ans[a]) ans[a] = c;
    if (!d) return;
    for(auto i : v[a]) kr(i,d-1,c);
}

signed main() {
    cin >> n >> m;
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        --a, --b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cin >> q;
    rep(i,q) {
        int v,d,c;
        cin >> v >> d >> c;
        --v;
        st.push(mp(v,mp(d,c)));
    }
    rep(i,q) {
        auto tmp = st.top();st.pop();
        kr(tmp.fi, tmp.se.fi, tmp.se.se);
    }
    rep(i,n) cout << ans[i] << endl;
}

