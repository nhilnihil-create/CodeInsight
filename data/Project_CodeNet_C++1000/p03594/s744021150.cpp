#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int H, W, D;
int X[500][500];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> H >> W >> D;
  rep(x, W) rep(y, H) {
    int color = 0;
    if (((x+y+INF)/D) % 2) color ^= 1;
    if (((x-y+INF)/D) % 2) color ^= 2;
    X[x][y] = color;
  }

  rep(y, H) {
    rep(x, W) {
      cout << "RYGB"[X[x][y]];
    }
    cout << "\n";
  }
  return 0;
}
