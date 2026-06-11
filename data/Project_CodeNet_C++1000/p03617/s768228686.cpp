#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	ll q, h, s, d,n;
	cin >> q >> h >> s >> d;
	cin >> n;
	ll bestprice1 = min({ q * 4,h * 2,s });
	ll bestprice2 = min({ q * 8,h * 4,s * 2,d });
	if (bestprice1*2>=bestprice2) {
		cout << n / 2 * bestprice2 + n % 2 * bestprice1 << endl;
	}
	else {
		cout << n * bestprice1 << endl;
	}
	return 0;
}