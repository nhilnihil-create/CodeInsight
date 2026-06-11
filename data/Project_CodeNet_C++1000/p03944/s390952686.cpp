#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int W,H,N;
  cin >> W >> H >> N;
  vector<vector<int>> L(N, vector<int>(3));
  rep(i,N) cin >> L[i][0] >> L[i][1] >> L[i][2];
  int left=0,right=W,bottom=0,top=H;
  rep(i,N) {
    if(L[i][2]==1) left = max(left,L[i][0]);
    if(L[i][2]==2) right = min(right,L[i][0]);
    if(L[i][2]==3) bottom = max(bottom,L[i][1]);
    if(L[i][2]==4) top = min(top,L[i][1]);
  }
  if(left >= right || top <= bottom) cout << 0 << endl;
  else cout << (right-left)*(top-bottom) << endl;
}