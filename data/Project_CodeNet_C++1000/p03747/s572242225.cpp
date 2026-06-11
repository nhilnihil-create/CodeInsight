#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
const int maxn = 1e5 + 55;
ll n, l, t;
vector<pi> a;
vi f;
ll count(ll p) {
	ll T = t;
	pi t = a[p];
	ll cnt = 0;
	for(auto i : a) {
		if(t.second==i.second) continue;
		ll z = (t.second==1?(i.first-t.first):(t.first-i.first))%l;
		if(z<0) z += l;
		if(z <= 2*T) {
			cnt++;
			cnt += (2ll*T-z)/l;
		}
	}
	return cnt;
}
pi calc(int i) { // {pos, val}
	ll np = count(i);
	if(a[i].second==1) np = i + np;
	else np = i - np;
	np = (np%n + n)%n;
	ll nx = a[i].first;
	if(a[i].second==1)
		nx = (nx+t)%l;
	else
		nx = (l + ((nx-t)%l))%l;
	return {np, nx};
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n  >> l >> t;
	a.resize(n);
	for(auto &i : a) {
		cin >> i.first >> i.second;
		if(i.second==1)
			f.pb((i.first+t)%l);
		else
			f.pb((l + ((i.first-t)%l))%l);
	}
	sort(all(f));
	if(n==1) return cout << f[0], 0;
	pi a = calc(0), b = calc(1);
	pi c, d;
	if(n==2) c = b;
	else c = calc(2);
	if(n<4) d = b;
	else d = calc(3);
	//for(auto i : f) cout << i << " "; cout << "\n";
	//cout << a.first << " " << a.second << "\n";
	//cout << b.first << " " << b.second << "\n";
	//return 0;
	int s = 0;
	while(f[(a.first+s)%n] != a.second || f[(b.first+s)%n] != b.second || f[(c.first+s)%n] != c.second || f[(d.first+s)%n] != d.second) s++;
	for(int i = 0; i < n; i++) cout << f[(i+s)%n] << "\n";
}
