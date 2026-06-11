#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define rep(i,a,n) for (int i =a; i<n; i++)
using namespace std;

int main() {
  int H,W; cin >> H >> W;
  char a[H][W]; rep(i,0,H) rep(j,0,W) cin >> a[i][j];
  
  rep(i,0,H+2) {
    rep(j,0,W+2) {
      if (i == 0 || i == H+1) cout << "#"; 
      else if (j == 0 || j == W+1) cout << "#";
      else cout << a[i-1][j-1];
    }
    cout << endl;
  }
}