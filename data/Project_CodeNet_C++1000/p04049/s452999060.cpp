#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int n, k;
vector<vector<int>> tree;
vector<pair<int, int>> edges;
queue<int> que;
vector<int> dist;

void bfs(){
    while(que.size()){
        int v = que.front(); que.pop();
        for(int u : tree[v]){
            if(chmin(dist[u], dist[v] + 1)){
                que.push(u);
            }
        }
    }
}

int solve_even(){
    int res = n;
    rep(i, n){
        fill(all(dist), n); dist[i] = 0;
        que.push(i); bfs();
        int tmp = 0;
        for(int d : dist){
            if(d > k / 2)tmp++;
        }
        chmin(res, tmp);
    }
    return res;
}

int solve_odd(){
    int res = n;
    for(pair<int, int> e : edges){
        fill(all(dist), n); dist[e.first] = dist[e.second] = 0;
        que.push(e.first); que.push(e.second); bfs();
        int tmp = 0;
        for(int d : dist){
            if(d > k / 2)tmp++;
        }
        chmin(res, tmp);
    }
    return res;
}

int main(){

    cin >> n >> k;
    tree.resize(n);
    dist.resize(n);
    edges.resize(n - 1);

    rep(i, n - 1){
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        edges[i] = make_pair(a, b);
    }

    if(k % 2 == 0)cout << solve_even() << endl;
    else cout << solve_odd() << endl;
    return 0;

}