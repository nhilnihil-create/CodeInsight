#include <bits/stdc++.h>

using namespace std;

long long solve(long long x, long long y) {
  long long res = 1e18;
  for (long long i = 1; i < x; ++i) {
    long long a = (x-i)*y;
    long long b = i*(y/2);
    long long c = i*(y-y/2);
    long long mx = max(a, max(b, c));
    long long mn = min(a, min(b, c));
    if (mx - mn < res) res = mx-mn;
  }
  return res;
}

long long solve2(long long x, long long y) {
  long long a = (x/3)*y;
  long long b = x*y - 2*a;
  return abs(a-b);
}

long long solve3(long long x, long long y) {
  long long a = ((x+2)/3)*y;
  long long b = x*y - 2*a;
  return abs(a-b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long h, w;
  cin >> h >> w;

  long long a = min(solve(h, w), solve(w, h)); 
  long long b = min(solve2(h, w), solve2(w, h)); 
  long long c = min(solve3(h, w), solve3(w, h)); 

  cout << min(min(a, b),c) << endl;

  return 0;
}

