#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

void solve(string S) {
  string YAKI = "YAKI";
  bool pred = equal(ALL(YAKI),S.begin());
  cout << (pred ? YES : NO) << endl;
}

int main() {
  string S;
  cin >> S;
  solve(S);
  return 0;
}
