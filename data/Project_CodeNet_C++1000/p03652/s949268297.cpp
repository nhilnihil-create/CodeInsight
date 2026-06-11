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

int N,M,ans;
deque<int> v[300];
map<int,int> m,b;

signed main() {
    cin >> N >> M;
    rep(i,N) rep(j,M) {
        int a;
        cin >> a;
        v[i].pb(a);
    }
    rep(i,N) m[v[i][0]]++;
    for(auto i : m) ans = max(ans, i.se);
    rep(k,M-1) {
        int MAX=0,num;
        for(auto i : m) if (i.se > MAX) {
            MAX = i.se;
            num = i.fi;
        }
        b[num] = 1;
        m.clear();
        rep(i,N) {
            while (b[v[i][0]]) v[i].pop_front();
            m[v[i][0]]++;
        }
        int tmp=0;
        for(auto i : m) tmp = max(tmp, i.se);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

