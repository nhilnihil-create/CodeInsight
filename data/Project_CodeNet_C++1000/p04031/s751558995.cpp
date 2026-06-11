#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = INT_MAX;
  for (int i = -100; i <= 100; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      cnt += (a[j]-i)*(a[j]-i);
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
