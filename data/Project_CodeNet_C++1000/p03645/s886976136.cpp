#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;
const ll INF = ll(1e18)+5;
const string YES = "POSSIBLE";
const string NO = "IMPOSSIBLE";

int main() {
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> graph(N);
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        --a;--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll> d(N,INF);
    queue<ll> q;
    q.push(0);
    d[0] = 0;
    while(!q.empty()){
        ll p = q.front();q.pop();
        // cerr <<"p=" << p << endl;
        for(ll child:graph[p]){
            // cerr <<"child=" << child << endl;
            if(d[child] == INF){
                d[child] = d[p] + 1;
                q.push(child);
            }
        }
    }
    // cerr <<"dN=" << d[N-1] << endl;
    if(d[N-1] <=2){
        cout << YES << endl;
    }else{
        cout << NO <<endl;
    }
    return 0;
}