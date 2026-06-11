#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())
#define maxIndex(v) max_element(v.begin(), v.end()) - v.begin()
#define maxElement(v) *max_element(v.begin(), v.end())
#define minIndex(v) min_element(v.begin(), v.end()) - v.begin()
#define minElement(v) *min_element(v.begin(), v.end())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
using namespace std;

int main()
{
  ll N, ans = 1; cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) {
  	cin >> A[i];
  }
  vsort(A);
  if (N % 2) {
    if (A[0] != 0) {
    	cout << 0 << endl;
      	return 0;
    }
    for (ll i = 1; i < N - 1; i += 2) {
    	if (A[i] != i + 1 || A[i + 1] != i + 1) {
        	cout << 0 << endl;
          	return 0;
        }
    }
    rep(i, 0, (N - 1) / 2) {
    	ans *= 2;
      	ans = ans % MOD;
    }
  } else {
    for (ll i = 0; i < N - 1; i += 2) {
    	if (A[i] != i + 1 || A[i + 1] != i + 1) {
        	cout << 0 << endl;
          	return 0;
        }
    }
    rep(i, 0, N / 2) {
    	ans *= 2;
      	ans = ans % MOD;
    }
  }
  cout << ans % MOD << endl;
}