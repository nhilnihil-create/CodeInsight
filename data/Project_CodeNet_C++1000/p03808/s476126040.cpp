#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N;
  cin >> N;
  ll A[N];
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }
  ll p = ((N*(N+1LL)) / 2LL);
  if (sum % p != 0) {
    cout << "NO" << endl;
    return 0;
  }
  ll S = sum / p;
  ll Ssum = 0;
  for (int i = 1; i < N; i++) {
    if (A[i] - A[i-1] > S) {
      cout << "NO" << endl;
      return 0;
    }
    ll a = S - (A[i] - A[i-1]);
    if (a % N != 0) {
      cout << "NO" << endl;
      return 0;
    }
    Ssum += a / N;
  }
  if (A[0] - A[N-1] > S) {
    cout << "NO" << endl;
    return 0;
  }
  ll ab = S - (A[0] - A[N-1]);
  if (ab % N != 0) {
    cout << "NO" << endl;
    return 0;
  }
  Ssum += ab / N;
  
  cout << "YES" << endl;
  return 0;
}