#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;

signed main() {
  
  string S;
  cin >> S;
  
  int gu = 0;
  int pa = 0;
  for( int i = 0; i < S.size(); i++ ){
    if( S.at(i) == 'g' ) gu++;
    else pa++;
  }  
  cout << (gu-pa)/2 << endl;
}

