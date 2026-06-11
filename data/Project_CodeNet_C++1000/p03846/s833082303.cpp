#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

/*
When n is odd, 5 for instance, the sequence of the absolute differences of the left and the right will be:
4, 2, 0, 2, 4
so, there should be one 0 and two identical even numbers to have the consistent order.
When n is even, 6 for instance, the sequence of the absolute differences of the left and the right will be:
5, 3, 1, 1, 3, 5
so, there should be two identical odd numbers to have the consistent order.
If the consistent order exists, there are 2^(n/2) possible orders since there are two identical values
for each different values.
*/

const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  map<int, int> diffs;  // how many identical abs diffs
  rep(i, n) {
    int pos;
    cin >> pos;
    diffs[pos]++;
  }

  // start from 0 if n is odd; start from 1 if n is even
  // if n is odd, possible abs diffs are 0, 2, 4, 6...
  // if n is even, possible abs diffs are 1, 3, 5, 7...
  for (int i = !(n%2); i < n; i += 2) {
    if (i == 0) {
      if (diffs[i] != 1) {  // there is no possible orders if there is more than one person with only one possible position
        cout << 0 << endl;
        return 0;
      }
    }
    else if (diffs[i] != 2) {  // there must be two people with the same abs diffs
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  rep(i, n/2) ans = (ans * 2) % mod;  // there are 2^(n/2) possible orders if it exists
  cout << ans << endl;
}