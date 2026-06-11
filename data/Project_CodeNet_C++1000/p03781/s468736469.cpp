#include<bits/stdc++.h>
using namespace std ;

int main () {
  int  N ;
  cin >> N ;
  int ans ;
  for(int i = 0 ; i < 100000 ; i++ ){
    int pre = i * ( i + 1 ) / 2;
    if(pre >= N) {
      ans = i ;
      break ;
    }
  }
  cout << ans << endl ;
}