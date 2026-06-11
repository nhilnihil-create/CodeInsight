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
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int W, H; cin >> W >> H;
  ll p[W+1]; FOR(i,0,W) cin >> p[i];
  ll q[H+1]; FOR(i,0,H) cin >> q[i];
  p[W] = q[H] = 1e9;
  sort(p, p + W);
  sort(q, q + H);
  int x = 0, y = 0;
  ll cost = 0;
  while(x < W || y < H) {
    if(p[x] < q[y]) {
      cost += p[x] * (H + 1 - y);
      x++;
    } else {
      cost += q[y] * (W + 1 - x);
      y++;
    }
  }
  cout << cost << endl;
  return 0;
}