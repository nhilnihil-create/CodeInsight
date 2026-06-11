#include <bits/stdc++.h>
 
#define int long long
 
// loop
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 	// a ~ b-1	(ascending)
#define REP(i, n) FOR(i, 0, n)							// 0 ~ n-1
#define NREP(i, n) FOR(i, 1, n + 1)						// 1 ~ n
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)	// a ~ b	(descending)
#define RREP(i, n) RFOR(i, n, 0)						// n ~ 0
#define RNREP(i, n) RFOR(i, n, 1)						// n ~ 1
 
// container operation
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define ASORT(c) std::sort((c).begin(), (c).end())
#define DSORT(c) std::sort((c).begin(), (c).end(), std::greater<typeof((c).front())>())
#define SIZE(x) ((int)(x).size())
 
// debug
#define check(x) std::cout << #x << " = " << x << '\n'
 
// print
#define cout(x) std::cout << x << '\n'
 
// type alias
using VI = std::vector<int>;
using VII = std::vector<VI>;
using VB = std::vector<bool>;
using VBB = std::vector<VB>;
using VS = std::vector<std::string>;
using PII = std::pair<int, int>;

std::string yes = "Yes\n";
std::string no = "No\n";

void solve();

signed main() {
  solve();
  return 0;
}

void solve() {
  int x;
  std::cin >> x;
  if (x < 1200) {
    cout("ABC\n");
  } else {
    cout("ARC\n");
  }
}
