#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> count(200000, 0);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  for (int x : a) {
    count.at(x)++;
    if (x - 1 >= 0) {
      count.at(x - 1)++;
    }
    count.at(x + 1)++;
  }
  int count_max = 0;
  for (int x : count) {
    count_max = max(x, count_max);
  }
  cout << count_max << endl;
}
