#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N), B(N);
  rep(i,0,N-1) cin >> A[i] >> B[i];

  ll p = 0;
  for (ll i = N-1; 0 <= i; --i)
  {
    ll d = A[i] + p;
    if (d % B[i] != 0)
    {
      p += B[i] - d % B[i];
    }
  }

  cout << p << endl;
  return 0;
}
