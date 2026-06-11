#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ra[9];

void put(int r) {
  if (r >= 1 && r <= 399) {
    ra[0] |= 1;
    return;
  }
  if (r >= 400 && r <= 799) {
    ra[1] |= 1;
    return;
  }
  if (r >= 800 && r <= 1199) {
    ra[2] |= 1;
    return;
  }
  if (r >= 1200 && r <= 1599) {
    ra[3] |= 1;
    return;
  }
  if (r >= 1600 && r <= 1999) {
    ra[4] |= 1;
    return;
  }
  if (r >= 2000 && r <= 2399) {
    ra[5] |= 1;
    return;
  }
  if (r >= 2400 && r <= 2799) {
    ra[6] |= 1;
    return;
  }
  if (r >= 2800 && r <= 3199) {
    ra[7] |= 1;
    return;
  }
  ra[8] += 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    put(x);
  }
  
  int ansmin = 0, ansmax = 0;
  for (int i = 0; i < 8; i++) {
    ansmin += ra[i];
    ansmax += ra[i];
  }
  if (ra[8] != 0) {
    ansmax += ra[8];
  }
  cout << max(1, ansmin) << " " << ansmax << endl;
  return 0;
}
