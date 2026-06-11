#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int col[8];
  for (int i = 0; i < 8; i++) {
    col[i] = 0;
  }

  int fre = 0;
  for (int i = 0; i < n; i++) {
    int rate;
    cin >> rate;
    int cnt = 0;
    if (rate >= 3200) {
      fre++;
    } else {
      col[rate / 400]++;
    }
  }

  int color = 0;
  for (int i = 0; i < 8; i++) {
    if (col[i] > 0) color++;
  }

  int mn = color;
  int mx = color + fre;
  if (mn == 0) mn++;
  cout << mn << ' ' << mx << endl;
}