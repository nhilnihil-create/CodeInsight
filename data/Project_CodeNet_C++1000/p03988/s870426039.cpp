#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 210;
int A[MAX_N];

void finish(){
  cout <<"Impossible" << endl; exit(0);
}

signed main(void){
  
  int N; cin >> N;
  int K = 0;
  for(int i = 0; i < N; i++){ 
    int a; cin >> a; A[a]++;
    K = max(K,a);
  }
  
  //次に直径パスを構築
  if(K%2 == 0){
   for(int i = K; i >= K/2; i--){ 
     
     if(i==K/2){ 
       if( A[i] == 0 ){ finish();}
       else{ A[i]--;}
     }
     else{
       if( A[i] <= 1 ){ finish();}
       else{ A[i]-=2;}
     }
     
   }
    
    for(int i = 1; i <= K/2; i++){
      if( A[i] > 0 ){ finish();}
    }
    
    cout << "Possible" << endl;
    
    
  }//偶数
  else{
    
    for(int i = K; i >= (K+1)/2; i--){
      
      if( A[i] <= 1 ){ finish();}
      else{ A[i] -= 2;}
    }
  
  
    for(int i = 1; i <= (K+1)/2; i++){
    if(A[i] > 0 ){ finish();}
      
  
     
      
    }
    
    cout << "Possible" << endl;
    
  }
  
  return 0;
}
  
