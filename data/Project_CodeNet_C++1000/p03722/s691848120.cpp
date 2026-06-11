#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

struct Edge{
    long long to,cost;
};
struct Bellman_Ford{
   vector<vector<Edge>> graph;
    ll roop = 0;
    int n;
    vector<bool> seen;

    Bellman_Ford (ll t){
        n = t;
        graph.resize(n);
        seen.resize(n,false);
    }


    bool Do (vector<long long>& d,const ll s = 0){
        d.resize(n,INF);
        d[s] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(Edge p:graph[j]){
                    if(d[j] != INF && d[p.to] > d[j]+p.cost){
                        d[p.to] = d[j]+p.cost;
                        
                        if(i == n-1){
                            roop = p.to;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    
    vector<bool> Can_to(int a,int r = -1){
        if(seen[a]);
        else {
            seen[a] = true;
            for(Edge p:graph[a]){
                if(p.to == r) continue;
                Can_to(p.to,a);
            }
        }
        return seen;
    }
};

int main(){
    long long n,m;
    cin >> n >> m;
    Bellman_Ford mike(n);
    for(int i = 0; i < m; i++){
        long long a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        Edge e = {b,-c};
        mike.graph[a].push_back(e);
    }
    vector<ll> ans;
    bool roop = mike.Do(ans);
    vector<bool> flag = mike.Can_to(mike.roop);
    if(!roop) cout << -ans[n-1] << endl;
    else if(flag[n-1]) cout << "inf" << endl;
    else cout << -ans[n-1] << endl;
    return 0;
}