#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;
double pi = 3.14159265358979;

ll r(ll x, ll y) {
  if (y == 0) return 1;
  else if (y % 2 == 0) return r(x, y/2) * r(x, y/2);
  else return x * r(x, (y-1)/2) * r(x, (y-1)/2);
}

int main() {
  ll n, p;
  cin >> n >> p;
  vector<int> a(n);
  ll a0 = 0;
  ll a1 = 0;
  for (int i = 0; i < n; i++) {
    ll A = 0;
    cin >> A;
    A %= 2;
    a[i] = A;
    if (A == 0) a0++;
    else a1++;
  }
  ll sum = 0;

  if (p == 0) {
    sum++;
    ll j = 2;
    while (j <= a1) {
      ll bo = 1;
      ll si = 1;
      ll m = min(a1-j, j);
      for (int k = 1; k <= m; k++) {
        bo *= k;
        si *= (a1 - k + 1);
      }
      si /= bo;
      sum += si;
      j += 2;
    }
  }
  
  else if (p == 1) {
    ll j = 1;
    while (j <= a1) {
      ll bo = 1;
      ll si = 1;
      ll m = min(a1-j, j);
      for (int k = 1; k <= m; k++) {
        bo *= k;
        si *= (a1 - k + 1);
      }
      si /= bo;
      sum += si;
      j += 2;
    }
  }
  
  ll A = r(2, a0);
  
  sum *= A;
  
  printf("%lld\n", sum);
}