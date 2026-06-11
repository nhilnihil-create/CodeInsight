#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<pair<long long, pair<int, int>>> edge(M);
  for(int e = 0; e < M; e++){
    int a, b;
    long long c;
    cin >> a >> b >> c;
    --a; --b;
    edge[e] = {c, {a, b}};
  }
  
  vector<long long> score(N, -INF);
  score[0] = 0;
  
  bool inf = false;
  
  for(int i = 0; i < N; i++){
    for(int e = 0; e < M; e++){
      int a = edge[e].second.first, b = edge[e].second.second;
      long long c = edge[e].first;
      
      if(score[a] + c > score[b]){
        if(i == N - 1 && b == N - 1){
          inf = true;
          break;
        }
        score[b] = score[a] + c;
      }
    }
  }
  
  if(inf) cout << "inf" << endl;
  else cout << score[N - 1] << endl;
  
  return 0;
}