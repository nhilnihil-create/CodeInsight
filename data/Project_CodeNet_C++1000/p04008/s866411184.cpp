#include<bits/stdc++.h>
using namespace std;

using P = pair<int,int>;

const int INF = 1e9;

int main(){
  int N, K;
  cin >> N >> K;
  
  vector<int> vec(N);
  vector<int> par(N);
  vector<int> dist(N,INF);
  vector<vector<int>> G(N,vector<int>(0));
  
  
  for(int i=0; i<N; i++){
    cin >> vec[i];
    vec[i]--;
  }
  
  if(K == 1){
    int cnt = 0;
    for(int i=0; i<N; i++){
      if(vec[i] != 0){
        cnt++;
      }
    }
    cout << cnt << endl;
    return 0;
  }
  
  int ans = 0;
  if(vec[0] != 0){
    ans++;
    vec[0] = 0;
  }
  
  for(int i=1; i<N; i++){
    G[vec[i]].push_back(i);
    G[i].push_back(vec[i]);
  }
  
  
  
  queue<int> Q;
  dist[0] = 0;
  Q.push(0);
  while(Q.size()){
    int x = Q.front();
    Q.pop();
    for(int i=0; i<G[x].size(); i++){
      if(dist[G[x][i]] > dist[x] + 1){
        dist[G[x][i]] = dist[x] + 1;
        Q.push(G[x][i]);
        par[G[x][i]] = x;
      }
    }
  }
  
  vector<P> D(N);
  for(int i=0; i<N; i++){
    P add = {dist[i], i};
    D[i] = add;
  }
  sort(D.rbegin(),D.rend());
  
  for(int i=0; i<N; i++){
    int x = D[i].first;
    int y = D[i].second;
    Q.push(y);
  }
  
  while(Q.size()){
    int x = Q.front();
    Q.pop();
    int pos = x;
    int cnt = 0;
    while(pos != 0){
      cnt++;
      int p = pos;
      pos = par[pos];
      par[p] = 0;
      if(cnt == K && pos != 0){
        ans++;
        Q.push(pos);
        break;
      }
    }
  }
  cout << ans << endl;
}