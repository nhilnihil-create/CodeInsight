#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int N,M;
vector<vector<int>> to;
vector<bool> visited,used;
vector<int> ans,ans2;

void dfs(int a,int b){ 
  
  //今aにいて、記録済み
  
  for(auto ne : to[a] ){ 
    
    if(visited[ne]){ continue;}
    
    else{ 
      
      
     if( !used[ne] ){ 
      if( b == 0 ){ans.push_back(ne);}
      else{ ans2.push_back(ne);}
       used[ne] = true;
     }
      
      visited[ne] = true; dfs(ne,b); return;
    }
    
    //　aから繋がっていてかつ行ったことがない点がなくなるまでdfsを続ければ答えになるはず
    
  }
  
  return ;
}
    
  
  
  

int main(){
 
  cin >> N >> M;
  
  visited = vector<bool>(N,false);
  used = vector<bool>(N,false);
  to.resize(N);
  
  for(int i = 0; i < M; i++){ 
    int a, b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
    
  }
  
  int m = 1e9;
  
  int p;

  for(int i = 0; i < N; i++){ 
    
   if( m > (int)to[i].size() ){
     p = i;
     m = (int)to[i].size();
   }
    
  }

  if( m == 1 ){ 
    // p起点で進められるところまでを進める
    
    
    visited[p] = true;
    
     ans.push_back(p);
    
     used[p] = true;
  
    
    dfs(p,0);
     
    cout << (int)ans.size() << endl;
    
    for(auto ne : ans ){ 
      
      cout << ne+1 << " ";}
    
    cout << endl;
    
    
    
  }
  //if閉じ
  else{
    // 0を選んで両方向にやっていく
    
    visited[0] = true;
    
    ans2.push_back(0);
    
    
    dfs(0,0);
    dfs(0,1);
    
    reverse(ans.begin(),ans.end());
    
    cout << (int)ans.size() + (int)ans2.size() << endl;
    
    for(auto ne : ans){ 
      cout << ne+1 << " " ;
    }
  
    for(auto ne : ans2){
      cout << ne+1 << " ";
    }
    
    
  }
  
  return 0;
} 
  
    
    
   
     