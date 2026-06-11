#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(void){ 
  
  int N;
  cin >> N; int M = 0;
  
  vector<int> vec(110,0);
  
  for(int i = 0; i < N; i++){
    int a; cin >> a; 
    vec[a]++; M = max(M,a); //直径を求める
  }
  
  bool flag = true; 
  
  if( M % 2 == 0 ){ 
    
    for(int i = M; i >= M/2; i--){ 
      
      if( i == M/2 ){  //最後だけ例外
        
        if( vec[M/2] == 0 ){ flag = false;}
        else{ vec[M/2]--; }
        
      }
      
      else{ 
        
        if( vec[i] <= 1 ){ flag = false;}
        else{ vec[i] -= 2;}
        
      }
    }//for
  }// 偶数の場合
  else{ 
    
    for(int i = M; i >= (M+1)/2; i--){ 
      
      if( vec[i] <= 1 ){ flag = false;}
      else{ vec[i] -= 2;}
      
    }
  }
  
  if(!flag){ cout << "Impossible" << endl; return 0;}
  
  //　残りの要素について、最小値以下が存在しないかを調べる
  
  int m; 
  if( M % 2 == 0 ){ m = M/2;}
  else{ m = (M+1)/2;}
  
  for(int i = 0; i <= m; i++){ 
    if( vec[i] > 0 ){ flag = false;}
  }
  
  if( !flag){ cout <<"Impossible" << endl;}
  else{ cout <<"Possible" << endl;}
  
  return 0;
}
  