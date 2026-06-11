#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
long long abs(long long n) {
  if (n < 0) {
    n = -n;
  }
  return n;
}
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

int main() {
  long long n;
  cin >> n;
  vector <long long> v(n);
  long long sum = 0;
  rep(i, n) {
    cin >> v.at(i);
    sum += v.at(i);
  }
  long long min = 2*(long long)pow(10, 9);
  long long tmp = 0;
  for (int i = 0; i < n-1; i++) {
    tmp += v.at(i);
    long long c = tmp-(sum-tmp);
    if (c < 0) {
      c = -c;
    }
    if (min > c) {
      min = c;
    }
  }
  cout << min << endl;
}