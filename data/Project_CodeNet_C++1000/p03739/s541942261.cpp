#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

long count(vector<int> a, bool plus) {
  plus = !plus;
  long sum = 0;
  long count = 0;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    plus = !plus;
    sum += a.at(i);
    if (plus) {
      if (sum > 0) {
        continue;
      } else {
        count += 1 - sum;
        sum = 1;
      }
    } else {
      if (sum < 0) {
        continue;
      } else {
        count += 1 + sum;
        sum = -1;
      }
    }
  }
  return count;
}

int main() {
  long n;
  cin >> n;

  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  cout << min(count(a, true), count(a, false)) << endl;
}
