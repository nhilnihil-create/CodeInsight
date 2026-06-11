#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main(){
    cin >> n >> m;
    Graph G(n);
    ll a[m];
    ll b[m];
    ll c[m];
    ll dist[n][n];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=1e9;
        }
    }
    for(ll i=0;i<m;i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(Edge(b[i],c[i]));
		G[b[i]].push_back(Edge(a[i],c[i]));
        dist[a[i]][b[i]]=c[i];
        dist[b[i]][a[i]]=c[i];
    }
    for(ll k=0;k<n;k++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    vector<ll> flag(m,0);
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                if(j!=k){
                    if(dist[j][k]==dist[j][a[i]]+c[i]+dist[b[i]][k]) flag[i]=1;
                }
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<m;i++) if(flag[i]==0) ans++;
    cout << ans << endl;
}
