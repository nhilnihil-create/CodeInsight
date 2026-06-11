#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> G[n];
  vector<int> d(n, -1);
  d[0] = 0;
  queue<int> que;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
    if(a==0){
      d[b] = 1;
      que.push(b);
    }
    if(b==0){
      d[a] = 1;
      que.push(a);
    }
  }
  while(!que.empty()){
    int next = que.front(); que.pop();
    for(int i=0; i<G[next].size(); i++){
      d[G[next][i]] = 2;
    }
  }
  string ans;
  if(d[n-1] != -1) ans = "POSSIBLE";
  else ans = "IMPOSSIBLE";
  cout << ans << endl;
  return 0;
}
