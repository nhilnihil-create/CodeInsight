#include <bits/stdc++.h>
using namespace std;

void solve() {
  cout << setprecision(10);
  long long H,W;
  cin >> H >> W;
  if(H%3 == 0 || W%3==0){
    cout << 0 << endl;
    return;
  }
 
  // H方向
  long long min_val = H*W;
  long long S_max, S_min;
  long long S1,S2,S3;
  for(long long i = 1; i < W; i++){
    S1 = H * i;
    S2 = (H/2) * (W - i); 
    S3 = H * W - S1 - S2;
 
    S_max = max(S1, max(S2, S3));
    S_min = min(S1, min(S2, S3));
 
    min_val = min(min_val, S_max - S_min);
 
    S1 = H * i;
    S2 = H * ( (W - i) / 2 );
    S3 = H * W - S1 - S2;
 
    S_max = max(S1, max(S2, S3));
    S_min = min(S1, min(S2, S3));
 
    min_val = min(min_val, S_max - S_min);
 
  }
 
  for(long long i = 1; i < H; i++){
    S1 = W * i;
    S2 = (W/2) * (H - i); 
    S3 = H * W - S1 - S2;
 
    S_max = max(S1, max(S2, S3));
    S_min = min(S1, min(S2, S3));
 
    min_val = min(min_val, S_max - S_min);
 
    S1 = W * i;
    S2 = W * ( (H - i) / 2 ); 
    S3 = H * W - S1 - S2;
 
    S_max = max(S1, max(S2, S3));
    S_min = min(S1, min(S2, S3));
 
    min_val = min(min_val, S_max - S_min);
  }
 
  cout << min_val << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
 }
