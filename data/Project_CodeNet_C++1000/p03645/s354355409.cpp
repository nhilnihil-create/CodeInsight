#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,s,e) for(ll i=s;i<e;++i)
#define MOD 1000000007
using Graph=vector<vector<ll>>;

int main(){
    ll n,m;
    cin >> n >> m;
    Graph G(n);
    ll a,b;
    F(i,0,m){
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    queue<ll> q;
    F(i,0,G[0].size()) q.push(G[0][i]);

    while(!q.empty()){
        ll p=q.front(); q.pop();
        F(i,0,G[p].size()){
            if(G[p][i]==n-1){
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}