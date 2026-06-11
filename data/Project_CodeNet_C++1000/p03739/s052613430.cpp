#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long > A;

long long solve(int p) {
  long long res = 0;
  long long curr = 0;
  for (int i = 0; i < n; ++i) {
    if ((i+p)%2 == 0) {
      if (curr + A[i] <= 0) {
        res += abs(curr+A[i]-1);
        curr = 1;
      } else {
        curr += A[i];
      }
    } else {
      if (curr + A[i] >= 0) {
        res += abs(curr+A[i]+1);
        curr = -1;
      } else {
        curr += A[i];
      }
    }
  }
  return res;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  A.resize(n);
  for (auto &a : A) cin >> a;
  cout << min(solve(0), solve(1)) << endl;

  return 0;
}

