#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,M;
  cin >> N >> M;
  int X[N];
  ll num[100001];
  ll d[M];
  ll pa[M];
  int ans = 0;
  for (int i = 0; i < M; i++) {
    d[i] = 0;
    pa[i] = 0;
  }
  for (int i = 0; i <= 100000; i++) {
    num[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    cin >> X[i];
    num[X[i]]++;
    d[X[i] % M]++;
  }
  for (int i = 0; i <= 100000; i++) {
    pa[i%M] += num[i] / 2;
  }

  for (int i = 1; i < M; i++) {
    if (M % 2 != 0 || i != M/2) {
      ll a = min(d[i],d[M-i]);
      ans += a;
      d[i] -= a;
      d[M-i] -= a;
    }
  }

  for (int i = 0; i < M; i++) {
    if (i == 0) {
      ans += d[0] / 2;
      continue;
    }
    if (i == M/2 && M % 2 == 0) {
      ans += d[M/2] / 2;
      continue;
    }
    ans += min(d[i] / 2,pa[i]);
  }
  cout << ans << endl;
  return 0;
}