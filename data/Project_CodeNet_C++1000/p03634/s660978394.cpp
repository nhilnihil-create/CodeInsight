#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

struct edge{int to,cost;};
vector< vector<edge> > g;
vector<ll> d;


void dfs(int s,ll dist,int pre= -1){
    d[s] = dist;
    for (auto nv:g[s]){
        if (nv.to == pre) continue;
        dfs(nv.to,dist+(ll)nv.cost,s);
    }
}

int main(){
    int n; cin >> n;
    g.resize(n);
    d.resize(n);
    rep(i,n-1){
        int x,y,c;
        cin >> x >> y >> c;
        edge e1 = {y-1,c};
        edge e2 = {x-1,c};
        g[x-1].push_back(e1);
        g[y-1].push_back(e2);
    }
    int q,k;
    cin >> q >> k;
    dfs(k-1,0);
    rep(i,q){
        int x,y;
        cin >> x >> y;
        x--;y--;
        cout << d[x]+d[y] << endl;
    }
    //rep(i,n) cout << d[i] << " ";
    //cout << endl;

    return 0;    
}
