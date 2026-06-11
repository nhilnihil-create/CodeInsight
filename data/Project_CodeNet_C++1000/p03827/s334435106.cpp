#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string s ;
  cin >> N >> s ;
  int count = 0 ;
  int mx = 0 ;
  for ( int i=0 ; i < N ; i++){
    if ( s.at(i) == 'I' ) {
      count ++ ;
    }else count -- ;
    mx = max (count , mx) ;
  }
  cout << mx << endl;
}
  