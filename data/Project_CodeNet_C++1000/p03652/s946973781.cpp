#include <iostream>

using namespace std;

const int MAX_N = 305;

int sol;
int fav [MAX_N][MAX_N];
int del [MAX_N];

int cnt [MAX_N];
void recalc (int n, int m) {
  for (int i = 1; i <= m; i++) {
    cnt[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!del[fav[i][j]]) {
        cnt[fav[i][j]]++;
        break;
      }
    }
  }

  /*
  for (int j = 1; j <= m; j++) {
    cout << cnt[j] << " ";
  }
  cout << endl;
  */

  pair<int, int> mx = make_pair(-1, -1); // <cnt, idx>
  for (int i = 1; i <= m; i++) {
    if (!del[i]) {
      mx = max(mx, make_pair(cnt[i], i));
    }
  }

  sol = min(sol, mx.first);
  del[mx.second] = 1;
}

int main () {
  int n, m;
  cin >> n >> m;

  sol = MAX_N;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> fav[i][j];
    }
  }

  for (int i = 1; i <= m; i++) {
    recalc(n, m);
  }
  cout << sol << endl;
}
