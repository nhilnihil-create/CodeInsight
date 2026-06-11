#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  int M = 0 , L=0 , P=0 ; 
  
  for(int i = 0 ; i < N ; i++){
    long long a ;
    cin >> a ; 
    if(a%2 != 0 && a%4 != 0 ) P++  ;
    else if(a%4 == 0 ) L++ ; 
  }
  
  if( P <= L || ( P == L+1  && P+L == N  )) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}