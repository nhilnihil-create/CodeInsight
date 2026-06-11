#include<bits/stdc++.h>
using namespace std ;

int main() {
  int N; 
  cin >> N ; 
  vector<int> T(N) ; 
  int Tot = 0 ;
  for(int i = 0 ; i < N ; i++) cin >>T.at(i) ;
  for(int i = 0 ; i < N ; i++) Tot += T.at(i) ;  
  
  int M ; 
  cin >> M ; 
  vector<int> P(M) , X(M) ; 
  for(int i = 0 ; i < M ; i++) cin >> P.at(i) >> X.at(i) ;
  
  for(int i = 0 ; i < M ; i++){
    cout << Tot - T.at(P.at(i)-1) + X.at(i) << endl ; 
  }
}

