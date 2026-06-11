#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<pair<int, int>> x;
  REP(i, N) {
    int j;
    cin >> j;
    j--;
    x.push_back({j, i});
  }

  vector<int> a(N * N, -1);
  sort(x.begin(), x.end());
  for (int j = N - 1; j >= 0; --j) {
    int i = x[j].second;
    int xi = x[j].first;

    a[xi] = i;
    int rem = N - i - 1;
    for (int k = N * N - 1; k > xi && rem > 0; --k) {
      if (a[k] == -1) {
        a[k] = i;
        rem--;
      }
    }

    if (rem > 0) {
      cout << "No\n";
      return 0;
    }
  }

  REP(j, N) {
    int i = x[j].second;
    int xi = x[j].first;

    int rem = i;
    for (int k = 0; k < xi && rem > 0; ++k) {
      if (a[k] == -1) {
        a[k] = i;
        rem--;
      }
    }

    if (rem > 0) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  for (int x : a) cout << x + 1 << ' ';
  cout << '\n';
  return 0;
}
