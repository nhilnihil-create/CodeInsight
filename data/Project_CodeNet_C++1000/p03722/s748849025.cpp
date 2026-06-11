#include<bits/stdc++.h>
using namespace std;

struct edge{
  int64_t from;
  int64_t to;
  int64_t cost;
};

int main(){
  int64_t N, M;
  cin >> N >> M;
  vector<edge> G(M);
  for(int i=0; i<M; i++){
    int64_t a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    edge add;
    add.from = a;
    add.to = b;
    add.cost = c*-1;
    G.at(i) = add;
  }
  int64_t INF = 1e18;
  vector<int64_t> dist(N,INF);
  dist.at(0) = 0;
  bool inf = false;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      edge e = G.at(j);
      if(dist.at(e.to) > dist.at(e.from) + e.cost){
        dist.at(e.to) = dist.at(e.from) + e.cost;
        if(i == N-1 && e.to == N-1){
          inf = true;
        }
      }
    }
  }
  if(inf){
    cout << "inf" << endl;
  }
  else{
    cout << dist.at(N-1)*-1 << endl;
  }
}