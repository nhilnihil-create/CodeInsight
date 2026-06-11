#include<bits/stdc++.h>
using namespace std ; 


int main(){
  int A ,B , C ; 
  cin >> A >> B >> C ; 
  int T = A ; 
  
  for(int i = 1 ; i <= 10000 ; i++ ){
    if(T%B == C){
      cout << "YES" << endl ; 
      return 0 ; 
    }
    //cout << T << endl ; 
    T = T + A   ; 
  }
  
  cout << "NO"  << endl ; 
}