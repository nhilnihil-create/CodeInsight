#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == s[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
  }
  for (int i = 0; i + 2 < n; ++i) {
    if (s[i] == s[i + 2]) {
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
  }
  puts("-1 -1");
  return 0;
}