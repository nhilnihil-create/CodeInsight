#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

signed main() {
  int N;
  cin >> N;
  
  int ans = 0;
  int now = 0;
  for( int i = 0; i < N; i++ ){
    int A;
    cin >> A;
    if( A == 0 ){
      ans += now/2;
      now = 0;
    }else now += A;
  }
  ans += now/2;
  cout << ans << endl;
}