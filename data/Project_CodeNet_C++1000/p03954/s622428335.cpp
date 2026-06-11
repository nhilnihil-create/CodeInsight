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

bool f(vector<int>& a, int mid) {
  int N = a.size();
  vector<bool> v(N);
  REP(i, N) v[i] = a[i] >= mid;

  int m = N / 2;

  int l = m - 1;
  while (l >= 0 && v[l] != v[l + 1]) l--;

  int r = m + 1;
  while (r < N && v[r] != v[r - 1]) r++;

  if (l == -1 && r == N) {
    int nsteps = (N - 1) / 2;
    return v[m] ^ (nsteps % 2);
  }

  return m - l < r - m ? v[l] : v[r];
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  N = 2 * N - 1;
  vector<int> a(N);
  REP(i, N) cin >> a[i];

  int lo = 1, hi = N;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (f(a, mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << lo << "\n";
  return 0;
}
