#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	ll a, b;
	cin >> a >> b;
	ll ans = 1e18 + 7;
	for (int i = 1; i <= a; ++i) {
		vector<ll> v(3);
		v[0] = i * b ;
		v[1] = ((a - i) / 2) * b;
		v[2] = ((a - i + 1)/2) * b;
		sort(v.begin(),v.end());
		ans = min(ans,v[2] - v[0]);
		v[0] = (i * b);
		v[1] = (b / 2) * (a - i);
		v[2] = ((b + 1) / 2) * (a - i);
		sort(v.begin(),v.end());
		ans = min(ans,v[2] - v[0]);
		//cout << x << " " << y << " " << xx << " " << yy << endl;  
	//	cout << ans << endl;
	}
	//cout << ans << endl;
	for (int i = 1; i <= b; ++i) {
		vector<ll> v(3);
		v[0] = i * a;
		v[1] = ((b - i) / 2) * a;
		v[2] = ((b - i + 1)/2) * a;
		sort(v.begin(),v.end());
		ans = min(ans,v[2] - v[0]);
		v[0] = (i * a);
		v[1] = (a / 2) * (b - i);
		v[2] = ((a + 1) / 2) * (b - i);
		sort(v.begin(),v.end());
		ans = min(ans,v[2] - v[0]);
	}
	cout << ans;
}


