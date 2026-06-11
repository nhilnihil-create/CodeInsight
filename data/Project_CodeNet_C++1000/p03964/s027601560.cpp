#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;
long long gcd(long long a, long long b)
{
  return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main()
{
  int N;
  cin >> N;
  vector<long long> A(N), T(N);
  rep(i, N)
  {
    cin >> T[i] >> A[i];
  }
  long long sum_a = 1;
  long long sum_t = 1;

  rep(i, N)
  {
    long long n = max((sum_t + T[i] - 1) / T[i], (sum_a + A[i] - 1) / A[i]);
    sum_t = T[i] * n;
    sum_a = A[i] * n;
  }
  long long ans = sum_a + sum_t;
  cout << ans << endl;
  return 0;
}