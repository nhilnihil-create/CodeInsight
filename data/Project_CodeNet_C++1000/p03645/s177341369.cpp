#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;


int N, M;  //N頂点M辺
vector<int> visited;
vector<vector<int>> G;


int main() {
  cin >> N >> M;
  G = vector<vector<int>>(N); // サイズを確保する
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    // 頂点番号を 0-indexed とする
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<int> q;
  for(int nv:G[0])q.push(nv);
  while(!q.empty()){
    int v=q.front();
    q.pop();

    for(int nv:G[v]){
      if(nv==N-1){cout << "POSSIBLE" << endl; return 0;}
    }
  }
  cout << "IMPOSSIBLE" <<endl;    
}