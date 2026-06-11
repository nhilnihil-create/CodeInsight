#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	vector <ll> x(3);
	cin >> x[0] >> x[1] >> x[2];

	sort(x.begin(), x.end());

	ll ans = 0;
	map< tuple<ll, ll, ll>, int> m;
	m[make_tuple(x[0],x[1],x[2])] = 1;

	while(true){
		if ((x[0]%2==1)||(x[1]%2==1)||(x[2]%2==1)) break;
		vector <ll> y(3);
		for (int ii = 0; ii < 3; ++ii){
			y[ii] = (x[(ii+1)%3] + x[(ii+2)%3])/2;
		}
		sort(y.begin(), y.end());
		x = y;
		if (m[make_tuple(x[0],x[1],x[2])]==1) {
			ans = -1;
			break;
		} else {
			m[make_tuple(x[0],x[1],x[2])] = 1;
			ans++;
		}
	}

	cout << ans << endl;


	return 0;
}
