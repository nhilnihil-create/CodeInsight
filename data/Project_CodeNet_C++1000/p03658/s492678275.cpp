#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> l(n);
  for (int &x : l) {
    cin >> x;
  }

  sort(l.begin(), l.end());
  reverse(l.begin(), l.end());
  int sum = 0;

  for (int i = 0; i < k; i++) {
    sum += l.at(i);
  }

  cout << sum << endl;
}
