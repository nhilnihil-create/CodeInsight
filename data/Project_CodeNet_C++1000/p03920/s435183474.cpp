#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

set<string> st;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> v;
	// for(ll i = 0; i * (i - 1) <= N; i++){
	for(ll i = 0; i <= 10000; i++){
		v.push_back(i * (i + 1) / 2);
	}

	while(N > 0){
		auto itr = lower_bound(v.begin(), v.end(), N);
		ll k = distance(v.begin(), itr);
		cout << k << endl;
		N -= k;
	}
}
