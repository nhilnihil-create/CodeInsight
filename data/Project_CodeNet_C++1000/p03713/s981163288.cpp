#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;
const int MOD = 1000000007;

signed main() {
  int H, W;
  cin >> H >> W;
  
  int ans = 10000000000;
  
  if( H%3 == 0 || W%3 == 0 ){
    cout << 0 << endl;
    return 0;
  }
  
  ans = min(H, W);
 
  //一度縦で分割
  for( int i = 1; i <= W; i++ ){
    int A = H*i;
    int B, C;
    if( H%2 == 0 ){
      B = (W-i)*(H/2);
      C = (W-i)*(H/2);
    }else{
      B = (W-i)*(H/2);
      C = (W-i)*(H/2+1);
    }
    int sa = max({abs(A-B), abs(A-C), abs(B-C)});
    if( ans > sa ) ans = sa;
  }
  
  //横で分割
  for( int i = 1; i <= H; i++ ){
    int A = W*i;
    int B, C;
    if( W%2 == 0 ){
      B = (H-i)*(W/2);
      C = (H-i)*(W/2);
    }else{
      B = (H-i)*(W/2);
      C = (H-i)*(W/2+1);
    }
    int sa = max({abs(A-B), abs(A-C), abs(B-C)});
    if( ans > sa ) ans = sa;
  }
  
  cout << ans << endl;
  
}
