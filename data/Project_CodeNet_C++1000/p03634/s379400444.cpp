#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

int main() {
    ll N;
    cin >> N;
    vector<vector<P>> tree(N);
    for(int i=0;i<N-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        tree[a].push_back(P(b,c));
        tree[b].push_back(P(a,c));
    }
    vector<ll> d(N,-1);
    ll Q,K;
    cin >> Q >> K;
    d[K-1]=0;
    queue<int> q;
    q.push(K-1);
    while(!q.empty()){
        int t = q.front();q.pop();
        for(P p:tree[t]){
            if(d[p.first] ==-1){
                d[p.first] = d[t] + p.second;
                q.push(p.first);
            }
        }
    }

    for(int q=0;q<Q;q++){
        int x,y;
        cin >> x>>y;
        --x;--y;
        cout <<d[x] +d[y] <<"\n";
    }

    return 0;
}