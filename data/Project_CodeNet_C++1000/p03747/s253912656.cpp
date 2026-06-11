#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	ll n,l,t;
	cin >> n >> l >> t;
	vl wa,wb;
	for(int i=0;i<n;i++) {
		ll x, dir;
		cin >> x >> dir;
		if(dir == 1) {
			wa.push_back(x);
		} else {
			wb.push_back(x);
		}
	}
	ll ot = t;
	t *= 2;
	ll dif = 0;
	for(int i=0;i<wa.size();i++) {
		wa[i] += t;
		dif += wa[i]/l;
		wa[i] %= l;
	}
	wb.insert(wb.end(),wa.begin(),wa.end());
	sort(wb.begin(),wb.end());
	vl res(n,0);
	for(int i=0;i<wb.size();i++) {
		int id = (((i-dif)%n)+n)%n;
		res[id] = wb[i];
	}
	for(int i=0;i<n;i++) {
		res[i] = (((res[i]-ot)%l)+l)%l;
		cout << res[i] << '\n';
	}
}
