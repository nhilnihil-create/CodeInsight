#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,X,Y;
  cin >> N >> K >> X >> Y;
    
    if ( N-K >=0 ){
      
    cout << K*X + ( N-K )*Y << endl;
    
  }
  
    else if ( N-K < 0 ){
          
    cout << N*X << endl;
      
  }
  
}