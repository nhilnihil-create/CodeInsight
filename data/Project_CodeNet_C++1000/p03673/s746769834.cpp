#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; cin >> N ; 
  vector<long long> a(N) ; 
  for(int i = 0 ; i < N ; i++) cin >> a.at(i) ; 
  
  if(N %2 == 0 ){
    for(int i = N-1 ; i >= 0  ; i -= 2){
      cout << a.at(i) << " " ;  
    }
    for(int i = 0 ; i < N ; i+=2){
      cout << a.at(i) << " " ; 
    }
  }
  else{
     for(int i = N-1 ; i >= 0   ; i -= 2){
       cout << a.at(i) << " " ;  
     }
     for(int i = 1 ; i < N ; i+=2){
       cout << a.at(i) << " " ; 
     }
  }
  cout << endl; 
  return 0 ; 
}