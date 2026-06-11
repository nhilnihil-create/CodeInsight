#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int A[310][310];
bool del[310][310];

int main(){ 
  int N,M; scanf("%d %d", &N, &M);
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d", &A[i][j]);
    }
  }
  
  int ans = 1e8;
  
  for(int k = 0; k < M; k++){ //1つ1つスポーツを消して行く
    
    map<int,int> mp;
    
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        
        if( del[i][A[i][j]] ){   //remaining もうその競技が除外されている
          continue;}
        
        mp[A[i][j]]++; break;
      }
    }
    
      int cnt = 0; int kind = 0;
      
      for(int j = 1; j <= M; j++){
        if( cnt < mp[j] ){ cnt = mp[j]; kind = j;}
      }//どの競技に一番集中するか/その競技は何か　を調べる
      
      ans = min(ans, cnt);
      
      for(int i = 0; i < N; i++){ 
        del[i][kind] = true;
      } //kindを除外
      
      
      
    }
    
  printf("%d\n", ans);
  
  return 0;
} 