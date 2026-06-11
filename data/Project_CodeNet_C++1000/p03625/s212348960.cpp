#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  map<long long , long long> A ; 
  for(int i = 0 ; i < N ; i++){
    long long P ; 
    cin >> P ; 
    A[P]++ ;
  }
  

  long long X = 0 , Y  = 0; 
  for(auto a : A){
    if( a.second >= 2 && X <= a.first) {
      Y = X ; 
      X = a.first ;
    	if( a.second >=4 && X<= a.first){
      		X = a.first; 
      		Y = a.first ; 
    	}
    }
    
  }
  
  cout << X*Y << endl ; 
}