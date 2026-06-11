#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,a;
  cin >> n;
  
  for ( int i = 0; i < 2; i++){
    a = n % 10;
    if( a == 9 ){
      cout << "Yes" << endl;
      return 0;
    }
    n /= 10;
  }
  
  cout << "No" << endl;
  
  
  
  
}

