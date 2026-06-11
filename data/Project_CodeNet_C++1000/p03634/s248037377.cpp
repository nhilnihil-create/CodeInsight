#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<vector<pair<int,int>>> edge(N,vector<pair<int,int>>());
    rep(i,N-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    vector<ll> dist(N,-1);
    int Q,K;
    cin >> Q >> K;
    K--;
    dist[K]=0;
    deque<int> dq;
    dq.push_back(K);
    while(!dq.empty()){
        int now = dq.front();
        dq.pop_front();
        for(auto e:edge[now]){
            if(dist[e.first]!=-1) continue;
            dist[e.first] = dist[now] + e.second;
            dq.push_back(e.first);
        }
    }
    rep(i,Q){
        int x,y;
        cin >> x >> y;
        x--; y--;
        cout << dist[x] + dist[y] << endl;
    }
    return 0;
}