#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W,h,w;
  cin >> H >> W >> h >> w;
  int Matrix[H+1][W+1];
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) {
      Matrix[i][j] = 1;
    }
  }
  if (h == 1 && w == 1) {
    cout << "No" << endl;
    return 0;
  } else if (h == 1) {
    int tmp[W+1];
    for (int i = 1; i <= W; i++) {
      if (i % w == 1) {
        tmp[i] = 100000000 - w + 1;
      } else if (i % w == 0) {
        tmp[i] = -100000000;
      } else {
        tmp[i] = 1;
      }
    }
    ll s = 0;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        Matrix[i][j] = tmp[j];
        s += Matrix[i][j];
      }
    }
    if (s > 0) {
      cout << "Yes" << endl;
      for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
          cout << Matrix[i][j] << " ";
        }
        cout << endl;
      }
    } else  {
      cout << "No" << endl;
    }
    return 0;
  } else if (w == 1) {
    int tmp[H+1];
    for (int i = 1; i <= H; i++) {
      if (i % h == 1) {
        tmp[i] = 100000000 - h + 1;
      } else if (i % h == 0) {
        tmp[i] = -100000000;
      } else {
        tmp[i] = 1;
      }
    }
    ll t = 0;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        Matrix[i][j] = tmp[i];
        t += Matrix[i][j];
      }
    }
    if (t > 0) {
      cout << "Yes" << endl;
      for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
          cout << Matrix[i][j] << " ";
        }
        cout << endl;
      }
    } else {
      cout << "No" << endl;
    }
    return 0;
  }
  ll sum = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (i % h == 0 && j % w == 0) {
        Matrix[i][j] = -100000000;
      } else if (i % h == 1 && j % w == 1) {
        Matrix[i][j] = 100000000 - (h*w) + 1;
      } else {
        Matrix[i][j] = 1;
      }
      sum += Matrix[i][j];
    }
  }
  if (sum > 0) {
    cout << "Yes" << endl;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        cout << Matrix[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}