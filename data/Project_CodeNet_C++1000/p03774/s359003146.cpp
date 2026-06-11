#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {

	ll n, m; cin >> n >> m;
	
	vector<pair<ll, ll>> pa_ab;
	for (int i = 0; i < n; i++) {
			ll f, s; cin >> f >> s;
			pa_ab.push_back({ f,s });
	}

	vector<pair<ll, ll>> pa_cd;
	for (int i = 0; i < m; i++) {
			ll f, s; cin >> f >> s;
			pa_cd.push_back({ f,s });
	}

	for (int i = 0; i < n; i++) {
		int ansIndex;
		ll dist = 9223372036854775807LL;
		for (int j = 0; j < m; j++) {
			ll tmpDist = 0;
			tmpDist += abs(pa_ab[i].first - pa_cd[j].first);
			tmpDist += abs(pa_ab[i].second - pa_cd[j].second);
			if (chmin(dist, tmpDist)) ansIndex = j;
		}
		
		cout << ansIndex + 1 << endl;
	}

	return 0;
}