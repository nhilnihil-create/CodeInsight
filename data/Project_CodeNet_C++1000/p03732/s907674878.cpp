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
#define INF 9223372036854775807

int N,W,w,v,mw,ans;
deque<int> V[4];

signed main() {
    cin >> N >> W >> mw >> v;
    V[0].pb(v);
    rep(i,N-1) {
        cin >> w >> v;
        V[w-mw].pb(v);
    }
    rep(i,4) sort(rall(V[i]));
    rep(i,4) V[i].push_front(0);
    rep(i,4) rep11(j,V[i].size()) V[i][j] += V[i][j-1];
    rep(i,V[0].size()) rep(j,V[1].size()) rep(k,V[2].size()) {
        int tmp = W - (i*mw + j*(mw+1) + k*(mw+2));
        if (tmp >= 0) ans = max(ans, V[0][i] + V[1][j] + V[2][k] + V[3][min((int)(V[3].size()-1),tmp/(mw+3))]);
    }
    cout << ans << endl;
}