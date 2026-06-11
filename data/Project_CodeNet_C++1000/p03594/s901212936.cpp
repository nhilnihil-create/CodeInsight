#include <bits/stdc++.h>
using namespace std;

int h, w, d;
string col = "RGBY";
vector<string> res;
vector<vector<int>> memo, ch;

void solve();
void dfs(int i, int j);

int main() {
  cin >> h >> w >> d;
  solve();
  for (auto s : res) cout << s << endl;
  return 0;
}

void solve() {
  memo.assign(h, vector<int>(w, -1));
  ch.assign(h, vector<int>(w, 0));
  // dfs(0, 0);
  res.resize(h);
  if (d & 1) {
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) memo[i][j] = (i + j) & 1;
  } else if (d == 2) {
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j)
        memo[i][j] = (i & 1) * 2 + (((j / 2) ^ (i / 2)) & 1);
  } else {
    for (int i = -d; i < h + d; ++i)
      for (int j = -d; j < w + d; ++j)
        if ((i + j) % d == 0 && (i % (d / 2) == 0)) {
          int c = (i % d != 0) * 2 + ((((i + d) / d) ^ ((j + d) / d)) & 1);
          int pm[2] = {1, -1};
          for (int t = 0; t < 2; ++t) {
            int len = d, x = i, y = j;
            while (len) {
              for (int k = 0; k < len; ++k) {
                int ny = y + k;
                if (x >= 0 && x < h && ny >= 0 && ny < w) memo[x][ny] = c;
              }
              len -= 2;
              x += pm[t];
              ++y;
            }
          }
        }
  }
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) res[i] += col[memo[i][j]];
}

void dfs(int i, int j) {
  if (i == h) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) cout << memo[i][j];
      cout << endl;
    }
    cout << endl;
    return;
  }
  auto change = [&](int c) {
    bool res = 1;
    int pm[2] = {1, -1};
    for (int px = 0; px < 2; ++px)
      for (int py = 0; py < 2; ++py)
        for (int dx = 0; dx <= d; ++dx) {
          int dy = d - dx;
          int nx = i + dx * pm[px], ny = j + dy * pm[py];
          if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          ch[nx][ny] ^= 1 << c;
          if (ch[nx][ny] == 15 || memo[nx][ny] == c) res = 0;
        }
    return res;
  };
  for (int c = 0; c < 4; ++c)
    if (!(ch[i][j] >> c & 1)) {
      int nx = i, ny = j + 1;
      if (ny == w) {
        ny = 0;
        ++nx;
      }
      memo[i][j] = c;
      if (change(c)) dfs(nx, ny);
      change(c);
      memo[i][j] = -1;
    }
}