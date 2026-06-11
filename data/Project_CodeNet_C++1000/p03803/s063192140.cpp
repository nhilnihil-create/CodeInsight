#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int A, B;
  cin >> A >> B;
  if (A == B) {
    puts("Draw");
    return 0;
  }
  if (A == 1 || B == 1) {
    if (A == 1) {
      puts("Alice");
    } else {
      puts("Bob");
    }
    return 0;
  }

  if (A < B) {
    puts("Bob");
  } else {
    puts("Alice");
  }
}