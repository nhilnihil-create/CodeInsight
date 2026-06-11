#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ;
  vector<int> a(N) ,b(N); 
  
  for(int i = 0 ; i < N ; i++){
    cin >> a.at(i) ; 
    b.at(i) = 0 ; 
  }
  int i = 0 ; 
  int cnt = 0 ; 
  
  while(b.at(i) != 2){
    
    b.at(i)++ ; 
    i = a.at(i)-1 ; 

    if(b.at(1)==1){
      cout << cnt << endl ;
      return 0 ; 
    }
        cnt++ ; 
  }
  

  cout << "-1" << endl ; 
  
}