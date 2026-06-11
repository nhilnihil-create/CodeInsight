#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;

signed main() {
  string S;
  cin >> S;
  for( int i = 0; i < S.size()-1; i++ ){
    if( S.at(i) == S.at(i+1) ){
      cout << i+1 << " " << i+2 << endl;
      return 0;
    }
  }
  
  if( S.size() > 2 ){
    for( int i = 0; i < S.size()-2; i++ ){
      if( S.at(i) == S.at(i+2) ){
        cout << i+1 << " " << i+3 << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << endl;

}

