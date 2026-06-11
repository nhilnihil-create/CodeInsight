#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001001001;
const ll MOD = 1000000007;

ll N, M, ans=0, tmp=0;
vector<vector<pair<ll,ll>>> G;

signed main(){
    cin >> N >> M;
    G.resize(N);
    vector<ll> dist(N, INF);
    dist[0] = 0;
    for(int i=0;i<M;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -c;
        G[a].push_back(make_pair(b,c));
    }
    ll state = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (dist[j] >= INF/2) continue;
            for(int l=0;l<G[j].size();l++) {
                if(dist[G[j][l].first]>dist[j]+G[j][l].second) {
                    dist[G[j][l].first]=dist[j]+G[j][l].second;
                    if(i==N-1&&G[j][l].first==N-1) state++;
                }
            }
        }
    }
    if(state==0) cout << -dist[N-1] << endl;
    else cout << "inf" << endl;
    return 0;
}