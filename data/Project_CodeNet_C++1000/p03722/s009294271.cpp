#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
struct edge{int from;int to;ll cost;};
int main(){
    int n,m;cin >> n >> m;
    vector<edge> g(m);
    vector<ll> d(n,INF);
    for(int i=0;i<m;i++){
        int a,b;ll c;
        cin >> a >> b >> c;
        a--,b--;
        g[i]=(edge{a,b,-c});
    }
    d[0]=0;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<m;j++){
            if(d[g[j].from]!=INF&&d[g[j].to]>d[g[j].from]+g[j].cost){
                d[g[j].to]=d[g[j].from]+g[j].cost;
                if(i>=n-1&&g[j].to==n-1){
                    cout << "inf" << endl;
                    return 0;
                }
            }
        }
    }
    cout << -d[n-1] << endl;
}