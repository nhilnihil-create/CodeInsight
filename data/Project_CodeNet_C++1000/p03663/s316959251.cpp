/**
 *    author:  tourist
 *    created: 20.11.2019 14:09:37       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto Ask = [&](long long x) {
    cout << "? " << x << endl;
    string u;
    cin >> u;
    return (u == "Y");
  };
  int n = (int) 1e9;
  if (Ask(n)) {
    long long m = 10;
    while (!Ask(m - 1)) {
      m *= 10;
    }
    cout << "! " << m / 10 << endl;
  } else {
    while (!Ask(n)) {
      n /= 10;
    }
    int low = n, high = n * 10 - 1;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (Ask(10LL * mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    cout << "! " << low << endl;
  }
  return 0;
}
