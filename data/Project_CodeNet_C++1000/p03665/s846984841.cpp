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
  rep(i, 0, N) cin >> A[i];
  vector<ll> odd, even;
  rep(i, 0, N) {
  	if (A[i] % 2) odd.push_back(A[i]);
    else even.push_back(A[i]);
  }
//  ll Ecomb, Ocomb;
  if (odd.size() == 0) {
  	if (P == 1) {
    	cout << 0 << endl;
    } else {
    	cout << ((ll)1 << even.size()) << endl;
    }
  } else {
  	cout << ((ll)1 << (odd.size() - 1 + even.size())) << endl;
  }    
}