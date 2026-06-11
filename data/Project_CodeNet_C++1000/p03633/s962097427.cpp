#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ;
  cin >> N ; 
  long long A ;
  cin >> A ; 
  long long  ans = A  ;  
  for(int i = 1 ; i < N ; i++){
    long long B ; 
    cin >> B ; 
    ans = lcm(ans,B) ; 
  }
  
  cout << ans << endl ; 
}