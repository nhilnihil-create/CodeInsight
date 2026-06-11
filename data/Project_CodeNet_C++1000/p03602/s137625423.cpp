#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int a[310][310];
int dist[310][310];
bool no_need[310][310];

int main() {
  // 入力
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  // ワーシャルフロイド法
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = a[i][j];
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  bool flag = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (a[i][j] != dist[i][j]) flag = false;
    }
  }

  ll ans = -1;
  if (flag) {
    for (int i = 0; i < N; i++) { // 始点
      for (int j = i + 1; j < N; j++) { // 終点
        for (int k = 0; k < N; k++) { // 中継点
          if (i == k || j == k) continue;
          if (a[i][j] == a[i][k] + a[k][j]) no_need[i][j] = true;
        }
      }
    }

    ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (no_need[i][j]) continue;
        ans += a[i][j];
      }
    }
  }

  // 解答
  cout << ans << endl;

  return 0;
}
