#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  double sum = 0.0;
  cin >> N;
  vector<int> a(N);
  for ( int i = 0; i < N; i++ ) {
    cin >> a[i];
    sum += a[i];
  }
  
  int SUM = round(sum/N);
  int ans = 0;
  for ( int i = 0; i < N; i++ ) {
    ans += ( a[i] - SUM ) * ( a[i] - SUM );
  }
  
  cout << ans << endl;
    
  return 0;
}