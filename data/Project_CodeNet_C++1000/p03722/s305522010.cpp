#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long INF = 1000000000000000;

int main(){
  cout << setprecision(10);
  int N,M;
  cin >> N >> M;
  vector<pii> e(M);

  map<int,ll> dist;
  map<pii,ll> length;
  for(int i = 0; i < N; i++){
    dist[i] = INF;
  }
  dist[0] = 0;

  for(int i = 0; i < M; i++){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    e.at(i) = make_pair(a,b);
    length[make_pair(a,b)] = -c;
  }

  // 最短路
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      pii now = e.at(j);
      int src = now.first;
      int dst = now.second;
      
      if(dist[src] == INF) continue;

      if(dist[dst] > dist[src] + length[now]){
        dist[dst] = dist[src] + length[now];
      }
    }
  }

  ll ans = dist[N-1];

  vector<bool> negative(N, false);

  for(int i  = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      pii now = e.at(j);
      int src = now.first;
      int dst = now.second;
      
      if(dist[src] == INF) continue;

      if(negative[src]){
        negative[dst] = true;
      }
      if(dist[dst] > dist[src] + length[now]){
        dist[dst] = dist[src] + length[now];
        negative[dst] = true;
      }
    }
  }

  if(negative[N-1]){
    cout << "inf" << endl;
  } else {
    cout << -ans << endl;
  }




}
