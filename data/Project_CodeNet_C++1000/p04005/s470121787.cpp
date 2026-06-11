#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

ll f(ll a, ll b, ll c) {
	ll x = a * b, y = a * c, z = b * c;
	if (x < y) return x < z ? x : z;
	else return y < z ? y : z;
}

int main(){
	ll a, b, c;
	cin >> a >> b >> c;
	if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) cout << 0 << endl;
	else cout << f(a, b, c) << endl;
	return 0;
}
