#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S ; 
  cin >> S ; 
  int N ; 
  N = S.size() ;
  int cnt = 0  ; 
  
  for(int i = 1 ; i < N ; i++){
    if((N-i)%2 == 0){
      
      for(int j = 0 ; j < (N-i)/2 ; j++){
        if(S.at(j) != S.at((N-i)/2 + j)){
          cnt++ ; 
          
        }
      }
     // cout << N-i <<" "<< cnt << endl ; 
      if(cnt == 0)  {
        cout << N - i << endl ; 
        return 0 ; 
      }
      cnt = 0;

    }
  }
}