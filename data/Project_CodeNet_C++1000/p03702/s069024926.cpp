#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF (1LL<<30)

ll N, A, B;
vector<ll> h;

bool enough(ll T) {
	vector<ll> b;
	for (ll i = 0; i < N; i++) {
		if(h[i] > B*T) b.push_back(h[i]-B*T);
	}
	ll cnt=0;
	for (ll i = 0; i < b.size(); i++) {
		if(b[i]%(A-B)==0) cnt += b[i]/(A-B);
		else cnt += b[i]/(A-B)+1;
	}
	return cnt <= T;
}

ll binary_search() {
	ll ng = 0;
	ll ok = INF;

	while (abs(ok - ng) > 1) {
		//cout << ok <<" "<< ng << endl;
		ll mid = (ok + ng) / 2;

		if (enough(mid)) ok = mid;
		else ng = mid;
	}
	return ok;
}


int main() {
	cin >> N >> A >> B;
	
	for (ll i = 0; i < N; i++) {
		int a; cin >> a;
		h.push_back(a);
	}

	ll ans = binary_search();
	printf("%lld\n", ans);
}

