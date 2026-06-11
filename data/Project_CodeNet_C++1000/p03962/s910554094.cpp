#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  int N;
  if ( a == b && b == c){
    N = 1;
  }
  else if ( a == b && a != c ){
    N = 2;
  }
  else if ( b == c && a != b){
    N = 2;
  }
  else if ( a == c && a != b){
    N = 2;
  }
  else {
    N= 3;
  }
  
  cout << N ;
}
