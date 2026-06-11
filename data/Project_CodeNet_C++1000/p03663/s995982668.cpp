#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void query(long long x) {
  cout << "? " << x << endl;
  cnt++;
}

long long getRes(int len) {
  long long low = 1, high = 0;
  for (int i = 1; i < len; i++) {
    low *= 10;
  }
  for (int i = 1; i <= len; i++) {
    high = high * 10 + 9;
  }
  while (high - low > 1) {
    long long mid = (1ll * high + low) >> 1ll;
    query(10ll * mid);
    char ver;
    cin >> ver;
    if (ver == 'N') {
      low = mid;
    } else {
      high = mid;
    }
  }
  return high;
}

int main() {
  int mn = -1000, mx = 10000;
  long long curMin = 1, curMax = 9;
  for (int i = 1; i <= 10; i++) {
    char verMin, verMax;
    query(curMin);
    cin >> verMin;
    query(curMax);
    cin >> verMax;
    if (verMin == 'N') {
      mx = min(mx, i - 1);
    }
    if (verMax == 'N') {
      mn = max(mn, i + 1);
    }
    curMin *= 10;
    curMax *= 10;
    curMax += 9;
  }
  if (mx == 10000) {
    int res = 1;
    for (int i = 1; i < mn; i++) {
      res = res * 10;
    }
    cout << "! " << res << endl;
  } else {
    long long res = getRes(mx);
    cout << "! " << res << endl;
  }
//  else {
//    int res = 0;
//    for (int i = 1; i <= mx; i++) {
//      res = res * 10 + 9;
//    }
//    cout << "! " << res << endl;
//  }
  return 0;
}
