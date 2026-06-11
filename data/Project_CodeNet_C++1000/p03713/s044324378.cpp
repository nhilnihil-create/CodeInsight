#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll H,W;
  cin >> H >> W;
  if(H%3 == 0 || W%3==0){
    cout << 0 << endl;
    return 0;
  }

  // H方向
  ll min_val = H*W;
  ll S_max, S_min;
  ll S1,S2,S3;
  for(ll i = 1; i < W; i++){
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

  for(ll i = 1; i < H; i++){
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
