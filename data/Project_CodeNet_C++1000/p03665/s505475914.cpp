#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
using namespace std;

int main()
{
  ll N, P; cin >> N >> P;
  vector<ll> A(N);
  bool odd = false;
  rep(i, 0, N) {
  	cin >> A[i];
    if (A[i] % 2) odd = true;
  }
  if (!odd) {
  	if (P) {
    	cout << 0 << endl;
    } else {
    	cout << ((ll) 1 << N) << endl;
    }
  } else {
  	cout << ((ll) 1 << (N - 1)) << endl;
  }
}