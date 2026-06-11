#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	map<ll, int> mp;
	for(int i = 0; i < n; i++){
		ll x; cin>>x;
		mp[x]++;
	}
	ll ans = 0;
	vector<ll> vec;
	for(auto x : mp){
		if(x.second >= 4)ans = max(ans, x.first*x.first);
		if(x.second >= 2)vec.push_back(x.first);
	}
	sort(vec.rbegin(), vec.rend());
	if(vec.size() >= 2){
		ans = max(ans, vec[0]*vec[1]);
	}
	cout<<ans<<endl;

	return 0;
}