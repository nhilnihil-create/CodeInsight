#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

void solve(ll N) {
  string s = to_string(N);
  reverse(ALL(s));
  bool pred = N == stoi(s);
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll N;
  cin >> N;
  solve(N);
  return 0;
}
