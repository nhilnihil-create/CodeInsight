#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
struct edge{ll from,to,cost;};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,a,b,c;
    cin>>n>>m;
    ll d[n];
    bool maki[n];
    memset(maki,0,sizeof(maki));
    vector<edge> g;
    for(int i=1;i<n;i++)d[i]=1e18;
    d[0]=0;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        g.push_back({a-1,b-1,-c});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[g[j].from]!=1e18&&d[g[j].to]>d[g[j].from]+g[j].cost){
                d[g[j].to]=d[g[j].from]+g[j].cost;
                if(i==n-1)maki[g[j].to]=true;
            }
        }
    }
    if(maki[n-1])cout << "inf"<<endl;
    else cout << -d[n-1] <<endl;
    return 0;
}