#include<bits/stdc++.h>
using namespace std ;


int main(){
  int N , K  ;
  cin >> N >> K  ;
  
  int64_t cnt = K; 
  
  for(int i = 1 ; i < N ; i++){
    cnt = cnt*(K-1) ; 
  }
  cout << cnt << endl ;
  
}