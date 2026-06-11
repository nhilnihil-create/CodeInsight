#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int W,H,N;
  cin >> W >> H >> N;
  int left = 0;
  int right = W;
  int top = H;
  int bottom = 0;
  rep(i,N) {
    int x,y,a;
    cin >> x >> y >> a;
    if(a==1) left = max(left,x);
    if(a == 2) right = min(right,x);
    if(a == 3) bottom = max(bottom,y);
    if(a == 4) top = min(top,y);
  }
  if(left >= right || top <= bottom) cout << 0 << endl;
  else cout << (right-left)*(top-bottom) << endl;
  return 0;
}