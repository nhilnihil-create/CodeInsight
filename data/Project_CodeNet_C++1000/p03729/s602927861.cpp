#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "YES";
const string NO = "NO";

void solve(string A, string B, string C) {
  bool pred = A.back() == B.front() && B.back() == C.front();
  cout << (pred ? YES : NO) << endl;
}

int main() {
  string A;
  cin >> A;
  string B;
  cin >> B;
  string C;
  cin >> C;
  solve(A, B, C);
  return 0;
}
