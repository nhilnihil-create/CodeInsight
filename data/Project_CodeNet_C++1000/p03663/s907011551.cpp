#include <iostream>

using namespace std;

typedef long long ll;

bool query (ll n) {
  cout << "? " << n << endl;

  char ans;
  cin >> ans;
  return (ans == 'Y');
}

void report (ll n) {
  cout << "! " << n << endl;
  exit(0);
}

void solve_powers () {
  ll cur = 9;
  while (true) {
    if (query(cur)) {
      report((cur + 1) / 10);
    } else {
      cur = (cur + 1) * 10 - 1;
    }
  }
}

void solve_others () {
  ll cur = 10;
  ll l, r;
  while (true) {
    if (!query(cur)) {
      l = cur / 10;
      r = cur - 1;
      break;
    } else {
      cur *= 10;
    }
  }
  
  for (ll k = 1LL << 32; k != 0; k /= 2) {
    if (l + k <= r && !query(10LL * (l + k))) {
      l += k;
    }
  }

  report(l + 1);
}

int main () {
  if (query(10000000001LL)) {
    solve_powers();
  } else {
    solve_others();
  }
}
