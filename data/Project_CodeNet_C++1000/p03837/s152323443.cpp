#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P =pair<ll,ll>;
using PP = pair<ll,P>;
const ll INF = ll(1e18)+5;

int main() {
    ll N,M;
    cin >> N >> M;
    vector<vector<P>> graph(N);
    for(int i=0;i<M;i++){
        ll a,b,c;
        cin >> a >> b >>c;
        --a;--b;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }

    set<P> ans;
    for(int i=0;i<N;i++){
        priority_queue<PP,vector<PP>,greater<PP>> pq;
        pq.push(PP(0,P(-1,i)));
        vector<ll> d(N,INF);
        d[i] = 0;
        while(!pq.empty()){
            PP pp = pq.top();pq.pop();
            ll pcost = pp.first;
            ll pfrom = pp.second.first;
            ll p = pp.second.second;  
            if(pcost > d[p]){
                continue;
            }
            if(ans.find(P(p,pfrom)) == ans.end()){
                ans.insert(P(pfrom,p));
            }
            for(P child:graph[p]){
                if(d[child.first] > d[p] + child.second){
                    // cerr <<"child=" << child.first << endl;
                    d[child.first] = d[p] + child.second;
                    pq.push(PP(d[child.first],P(p,child.first)));
                }
            }

        }
    }
    // cerr << ans.size() << endl;
    cout << M-(ans.size()-N) << endl;

    return 0;
}