#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

struct edge{
    int from,to;
    ll cost;
};
signed main(){
    int n,m; cin >> n >> m;
    vector<edge> G;
    rep(i,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        edge e={a,b,-c};
        G.pb(e);
    }
    ll dist[n];
    rep(i,n) dist[i]=1e18;
    dist[0]=0;
    ll res=0;
    bool ng=0;
    rep(i,n){
        rep(j,G.size()){
            edge e=G[j];
            if(dist[e.to]>dist[e.from]+e.cost){
                dist[e.to]=dist[e.from]+e.cost;
                if(i==n-1){
                    if(ng&&dist[n-1]!=res){
                        cout << "inf" << endl;
                        return 0;
                    }
                    if(ng) break;
                    ng=1;
                    res=dist[n-1];
                    i--;
                }
            }
        }
    }
    cout << -dist[n-1] << endl;
}

