#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N; vector<int> a;


vector<int> DP;

vector<vector<int>> to;

void dfs(int v){ 
 
  if(to[v].empty()){ DP[v] = 1; return;}
  
  vector<int> res;
  
  for(auto p : to[v]){
    
    dfs(p);
    
    res.push_back(DP[p]);
    
  }
  
  sort(res.rbegin(),res.rend());
  
  int m = 0;
  
  for(int i = 0; i < (int)res.size(); i++){
    
    m = max(m, res[i]+i+1);
  }
  
  DP[v] = m;
  
  return;
  
}
    
int main(){
  
  cin >> N;
  
  to.resize(N); DP.resize(N);
 
  for(int i = 1; i < N; i++){
    int a; cin >> a; a--;
    //ノードは全て0-indexed,優勝するのは0
    
    to[a].push_back(i); //勝った方から負けた方へノードを張る
    
  } 
  
  dfs(0); //0を頂点として、木DPを行う
  
  cout << DP[0]-1 << endl;
  
  return 0;
}
  