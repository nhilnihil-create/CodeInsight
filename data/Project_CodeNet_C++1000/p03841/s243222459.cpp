#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n; cin >> n;
	ll a[n * n + 1] = {}, b[n + 1], m[n + 1];
	vector<pair<ll, ll>> v;
	for(ll i = 0; i < n; i++){
		ll po; cin >> po;
		a[po] = i + 1;
		b[i + 1] = n - 1;
		v.push_back(pair<ll, ll>(po, i + 1));
		m[i + 1] = po;
	}
	sort(v.begin(), v.end());
	queue<ll> q;
	for(ll i = 0; i < n; ++i) q.push(v[i].second);
	ll flag = 1;
	for(ll i = 1; i <= n * n; i++){
		if(!a[i]) continue;
		ll po = a[i] - 1;
		for(; flag < i && po; flag++){
			if(a[flag]) continue;
			a[flag] = a[i];
			b[a[i]]--;
			po--;
		}
		if(po){
			cout << "No\n";
			return 0;
		}
	}
	for(ll i = 1; i <= n * n; i++){
		if(a[i]) continue;
		while(!b[q.front()]) q.pop();
		if(m[q.front()] > i){
			cout << "No\n";
			return 0;
		}
		a[i] = q.front();
		b[q.front()]--;
	}
	cout << "Yes\n";
	for(ll i = 1; i <= n * n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}