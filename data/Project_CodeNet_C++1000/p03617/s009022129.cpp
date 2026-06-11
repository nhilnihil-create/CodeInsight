#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll q,h,s,d; cin >> q >> h >> s >> d;
	ll n; cin >> n;
	h=min(2*q,h);
	s=min(2*h,s);
	ll w=n/2;
	ll y=n%2;
	ll ans=min(2*s,d)*w+y*s;
	cout << ans << endl;
}