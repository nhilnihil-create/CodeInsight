#include <bits/stdc++.h>
using namespace std;
 
#define int long long

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;

  vector<int> A(N);
  for ( int i = 0; i < N; i++ ) {
    cin >> A[i];
  }

  int ans = A[0]-1;
  int now = 2;
  for ( int i = 1; i < N; i++ ) {    
    ans += (A[i]-1)/now;
    if ( A[i] == now ) now++;
    // cout << ans << " " << now << endl;
  }

  cout << ans << endl;

  return 0;
}
