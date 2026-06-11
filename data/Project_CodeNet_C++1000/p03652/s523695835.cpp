#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  int like[N][M];
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> like[i][j];
      like[i][j]--;
    }
  }
  vector<int> join(N,0);
  int ans = 1e5;
  set<int> S;
  while(S.size() < M){
    vector<int> cnt(M,0);
    int MAX = 0;
    for(int i=0; i<N; i++){
      int x = like[i][join[i]];
      cnt[x]++;
      MAX = max(MAX,cnt[x]);
    }
    ans = min(ans,MAX);
    for(int i=0; i<M; i++){
      if(cnt[i] == MAX){
        S.insert(i);
      }
    }
    if(S.size() == M){
      break;
    }
    for(int i=0; i<N; i++){
      while(S.count(like[i][join[i]])){
        join[i]++;
      }
    }
  }
  cout << ans << endl;
}