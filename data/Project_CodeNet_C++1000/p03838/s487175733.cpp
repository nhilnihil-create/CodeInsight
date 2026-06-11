#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll x, y;
	cin >> x >> y;
	ll ans = 2e9+5;
	ll a = x, b = y;
	if (a<=b) ans = min(ans, b-a);
	a = -x, b = y;
	if (a <= b) ans = min(ans , b-a+1);
	a = x, b = -y;
	if (a <= b) ans = min(ans, b-a+1);
	a = -x, b = -y;
	if (a <= b) ans = min(ans, b-a+2);
	cout << ans << endl;
	return 0;
}