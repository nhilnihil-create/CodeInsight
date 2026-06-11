#include<bits/stdc++.h>

using namespace std;

int main(){
  long long H, W;
  cin >> H >> W;
  
  long long s = min(H, W);
  if(H % 3 == 0 || W % 3 == 0) s = 0;
  
  for(int i = 1; i < H; i++){
    long long s1, s2, s3;
    s1 = i * W;
    s2 = (H - i) * (W / 2);
    s3 = (H - i) * (W - W / 2);
    long long s_max = max(s1, max(s2, s3));
    long long s_min = min(s1, min(s2, s3));
    s = min(s_max - s_min, s);
  }
  
  for(int j = 1; j < W; j++){
    long long s1, s2, s3;
    s1 = H * j;
    s2 = (H / 2) * (W - j);
    s3 = (H - H / 2) * (W - j);
    long long s_max = max(s1, max(s2, s3));
    long long s_min = min(s1, min(s2, s3));
    s = min(s_max - s_min, s);
  }
  
  cout << s << endl;
  
  return 0;
}