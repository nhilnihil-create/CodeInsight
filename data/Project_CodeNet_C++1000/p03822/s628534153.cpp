#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100100;

vector<vector<int>> to;

int dfs(int v){ // tree-DP
  
  if(to[v].empty()){ //子なし→leaf→深さ0
    return 0;
  }
  
  vector<int> res;
  
  for(auto ne : to[v]){
    
    res.push_back(dfs(ne));
    
  }
  
  sort(res.rbegin(),res.rend());
  
  int r = 0;
  
  int cnt = 1;
  
  for(auto ne : res){
    r = max(r, ne+cnt);
    cnt++;
  }
  
  return r;
}
     
    

int main(){
  
  int N; cin >> N;
  
  to.resize(N);
  
  for(int i = 1; i < N; i++){
    int a; cin >> a; a--;
    to[a].push_back(i);
  }
  
  
  cout << dfs(0) << endl;
  
  return 0;
}