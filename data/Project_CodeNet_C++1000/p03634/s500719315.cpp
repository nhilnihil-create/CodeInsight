#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N; cin >> N;
    vector<vector<pair<int, ll>>> tree(N);
    rep(i, N - 1){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;b--;
        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }
    int Q, K; cin >> Q >> K;
    K--;
    vector<ll> dist(N, -1);
    dist[K] = 0;
    queue<int> que;
    que.push(K);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto x:tree[v]){
            if(dist[x.first] != -1) continue;
            dist[x.first] = dist[v] + x.second;
            que.push(x.first);
        }
    }
    vector<ll> ans;
    rep(i, Q){
        int x, y; cin >> x >> y;
        x--;y--;
        ans.push_back(dist[x]+dist[y]);
    }
    rep(i, Q)cout << ans[i] << endl;
}