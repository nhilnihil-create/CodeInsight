#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for ( int i = 0; i < N; i++ ) {
    cin >> a[i];
  }
  
  int ans = 0;
  long long min = 10000000;
  for ( int i = -100; i <= 100; i++ ) {
    int ANS = 0;
    for ( int j = 0; j < N; j++ ) {
      ANS += ( a[j] - i ) * ( a[j] - i );
    }
    if ( ANS < min ) {
      ans = ANS;
      min = ANS;
    }
  }
  
  cout << ans << endl;
    
  return 0;
}