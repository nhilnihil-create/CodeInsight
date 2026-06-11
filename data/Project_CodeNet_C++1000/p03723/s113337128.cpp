#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool isEvenTuple(ll a, ll b, ll c) {
	return (a%2==0) && (b%2==0) && (c%2==0);
} 

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	if (isEvenTuple(a,b,c) && a==b && b==c) {
		cout << -1 << endl;
		return 0;
	}
	while (true)
	{
		if (!isEvenTuple(a, b, c)) break;
		ll x = a/2, y = b/2, z = c/2;
		a = y+z, b = z+x, c = x+y;
		ans++; 
	}
	cout << ans << endl;
	return 0;
}