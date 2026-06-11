#include<bits/stdc++.h>
using namespace std ; 

int main(){
  string W ;
  cin >> W ; 
  int N = W.size() ; 
  vector<int> C(N);
  
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      
        if(W.at(i) == W.at(j)){
          C.at(i)++ ; 
        }

    }
  }
  
  
  for(int i = 0 ; i < N ; i++){
    if( C.at(i) % 2 != 0 ){
      cout << "No" << endl ; 
      return 0 ; 
    }
    
  }
  
  cout << "Yes" << endl ; 
           
           

}