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
	vector<ll> a(3*n);
	for(auto &x : a){
		cin>>x;
	}
	vector<ll> f(3*n), b(3*n);
	{
		ll sum = 0;
		map<ll, int> mp;
		for(int i = 0; i < n; i++){
			sum += a[i];
			mp[a[i]]++;
		}
		f[n - 1] = sum;
		for(int i = n; i < 3*n; i++){
			sum += a[i];
			mp[a[i]]++;
			ll val = (*mp.begin()).first;
			mp[val]--; if(!mp[val])mp.erase(val);
			sum -= val;
			f[i] = max(sum, f[i - 1]);
		}
	}
	{
		ll sum = 0;
		map<ll, int> mp;
		for(int i = 2*n; i < 3*n; i++){
			sum += a[i];
			mp[a[i]]++;
		}
		b[2*n] = sum;
		for(int i = 2*n - 1; i >= 0; i--){
			sum += a[i];
			mp[a[i]]++;
			ll val = (*mp.rbegin()).first;
			mp[val]--; if(!mp[val])mp.erase(val);
			sum -= val;
			b[i] = min(sum, b[i + 1]);
		}
	}
	ll ans = -1e18;
	for(int i = n - 1; i < 2*n; i++){
		ans = max(ans, f[i] - b[i + 1]);
	}
	cout<<ans<<'\n';


	return 0;
}