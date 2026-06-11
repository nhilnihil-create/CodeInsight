#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N,K;
	cin >> N >> K;
	map<ll, ll> mp;
	vector<ll> A(N);
	rep(i,N) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll sa = 1e18, sa_prev = 1e18;
	rep(i,N-1) {
		if(A[i+1] - A[i] > 0) chmin(sa, A[i+1] - A[i]);
	}
	while(1) {
		rep(i,N) {
			ll a = A[i] % sa;
			if(a != 0) chmin(sa, a);
		}
		if(sa == sa_prev) {
			break;
		}
		sa_prev = sa;
	}
	rep(i,N) {
		if(A[i] < K) continue;
		if((A[i] - K) % sa == 0) {
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;

  return 0;
}
