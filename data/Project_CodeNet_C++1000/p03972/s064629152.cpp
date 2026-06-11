#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll W, H; cin >> W >> H;
  ll p[W]; FOR(i,0,W) cin >> p[i]; // 横線
  ll q[H]; FOR(i,0,H) cin >> q[i]; // 縦線
  sort(p, p + W);
  sort(q, q + H);
  ll ans = 0;
  // (H+W)方向から選ぶ
  ll yoko = 0, tate = 0;
  FOR(i,0,W+H) {
    if(yoko == W) {
      ans += q[tate] * (W + 1 - yoko);
      tate++;
      continue;
    }
    if(tate == H) {
      ans += p[yoko] * (H + 1 - tate);
      yoko++;
      continue;
    }
    // 縦線を(W+1-横線)本引く
    //if(p[yoko] * (H + 1 - tate) > q[tate] * (W + 1 - yoko)) {
    if(p[yoko]> q[tate]) {
      ans += q[tate] * (W + 1 - yoko);
      tate++;
    } else {
      ans += p[yoko] * (H + 1 - tate);
      yoko++;
    }
  }
  cout << ans << endl;
  return 0;
}