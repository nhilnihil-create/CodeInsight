#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];

  multiset<ll> left, right;
  ll lsum = 0, rsum = 0;
  for (int i = 0; i < N; i++) {
    left.insert(A[i]);
    lsum += A[i];
    right.insert(C[i]);
    rsum += C[i];
  }
  ll ans = lsum - rsum;

  vector<ll> a(N + 1);
  a[0] = lsum;
  for (int i = 0; i < N; i++) {
    ll x = *left.begin();
    left.erase(left.find(x));
    lsum -= x;
    left.insert(max(B[i], x));
    lsum += max(B[i], x);
    a[i + 1] = lsum;
  }

  vector<ll> c(N + 1);
  c[0] = rsum;
  for (int i = 0; i < N; i++) {
    ll x = *right.rbegin();
    right.erase(right.find(x));
    rsum -= x;
    right.insert(min(B[N - 1 - i], x));
    rsum += min(B[N - 1 - i], x);
    c[i + 1] = rsum;
  }

  for (int i = 0; i < N + 1; i++) {
    ans = max(ans, a[i] - c[N - i]);
  }
  cout << ans << endl;
}