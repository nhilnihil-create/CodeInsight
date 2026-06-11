#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;
 
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0
 
int main() {
  long n;
  cin >> n;
 
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
 
  bool plus;
  long sum = 0;
  long count_plus = 0;
 
  plus = false;
 
  for (int i = 0; i < n; i++) {
    plus = !plus;
    sum += a.at(i);
    if (plus) {
      if (sum > 0) {
        continue;
      } else {
        count_plus += 1 - sum;
        sum = 1;
      }
    } else {
      if (sum < 0) {
        continue;
      } else {
        count_plus += 1 + sum;
        sum = -1;
      }
    }
  }
  long count_minus = 0;
  plus = true;
  sum = 0;
 
  for (int i = 0; i < n; i++) {
    plus = !plus;
    sum += a.at(i);
    if (plus) {
      if (sum > 0) {
        continue;
      } else {
        count_minus += 1 - sum;
        sum = 1;
      }
    } else {
      if (sum < 0) {
        continue;
      } else {
        count_minus += 1 + sum;
        sum = -1;
      }
    }
  }
  cout << min(count_plus, count_minus) << endl;
}
