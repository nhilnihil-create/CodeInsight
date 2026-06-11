#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, q, k;
  cin >> n;
  vector<vector<pair<int, long long>>> tree(n);
  for(int i=0; i<n-1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    tree[--a].push_back({--b, c});
    tree[b].push_back({a, c});
  }
  cin >> q >> k;
  k--;
  vector<long long> dist(n, 1e18);
  dist[k] = 0;
  queue<int> que;
  que.push(k);
  while(!que.empty()){
    int now = que.front();
    que.pop();
    for(auto to: tree[now]){
      if(dist[to.first] == 1e18){
        dist[to.first] = dist[now] + to.second;
        que.push(to.first);
      }
    }
  }
  for(int i=0; i<q; i++){
    int x, y;
    cin >> x >> y;
    cout << dist[--x] + dist[--y] << endl;
  }
}