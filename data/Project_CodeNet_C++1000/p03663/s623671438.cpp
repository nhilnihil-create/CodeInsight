#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool query(ll x) {
  cout << "? " << x << endl;
  char c;
  cin >> c;
  return c == 'Y';
}

int main(int argc, char *argv[]) {
  vector<bool> a(10, true);
  int len = -1;
  for (ll i = 1, j = 10; i <= 9; i++, j *= 10) {
    if (!query(j)) {
      len = i;
      break;
    }
  }
  if (len == -1) {
    for (ll i = 1, j = 9; i <= 10; i++, j = j * 10 + 9) {
      if (query(j)) {
        len = i;
        break;
      }
    }
  }
  ll low = 1;
  for (int i = 2; i < len; i++) {
    low = low * 10;
  }
  ll high = low * 10 - 1;
  while (low <= high) {
    ll mid = (low + high) / 2;
    if (query(mid)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (len == 1) high = 0;
  for (int i = (high == 0 ? 1 : 0); i <= 9; i++) {
    if (query(high * 100 + i * 10)) {
      cout << "! " << high * 10 + i << endl;
      break;
    }
  }
  return 0;
}
