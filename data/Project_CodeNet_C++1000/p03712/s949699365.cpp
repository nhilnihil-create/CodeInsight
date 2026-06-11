#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int h, w;
  cin >> h >> w;
  char c[h][w];
  rep(i, h){
    rep(j, w) cin >> c[i][j];
  }
  
  for(int i = 0; i < h + 2; i++) {
    for(int j = 0; j < w + 2; j++) {
      if(i == 0 || i == h + 1 || j == 0 || j == w + 1) cout << '#';
      else cout << c[i - 1][j - 1];
    }
    cout << endl;
  }
  return 0;
}
