#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> a(N);
	vector <ll> idx(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> a[ii];
		idx[a[ii]-1] = ii;
	}

	ll ans = 0;
	set<ll> s;
	s.insert(-1);
	s.insert(N);
	for (int ii = 0; ii < N; ++ii){
		ll val = ii + 1;
		//idx[ii]を基準にlidxを求める
		auto itr = s.upper_bound(idx[ii]);
		ll ridx = *itr - 1;
		itr--;
		ll lidx = *itr + 1;
		s.insert(idx[ii]);

		//ansに追加
		ans += val * (idx[ii] - lidx + 1) * (ridx - idx[ii] + 1);
	}

	cout << ans << endl;

	return 0;
}
