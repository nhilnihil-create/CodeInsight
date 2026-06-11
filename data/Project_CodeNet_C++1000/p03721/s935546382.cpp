#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ll n, k;
	cin >> n >> k;
	vector<pair<ll,ll>> v;
	for(int i = 0; i < n; ++i){
		ll a, b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(), v.end());
	int i = 0;
	ll sum = 0;
	while(sum < k){
		sum += v[i].second;
		++i;
	}
	cout << v[i-1].first;

	return 0;
}
