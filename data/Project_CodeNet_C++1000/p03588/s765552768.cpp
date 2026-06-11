#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<pll> v(N);
	rep(i, N) cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), greater<pll>());
	cout << v[0].first + v[0].second << endl;	
}
