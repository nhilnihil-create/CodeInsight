#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, m, a, x, y, t, M = 1e9 + 7, Z = 1e9;
int main()
{
	ll i;
	cin >> n >> m;
	for (i = 1; i<= n; i++) {
		scanf("%lld",&a);
		a = a + Z;
		x = (x + a * (i - 1)) % M;
		t = (a * (n - i)) % M;
		x = (x - t + M) % M;
	}
	for (i = 1; i<= m; i++) {
		scanf("%lld",&a);
		a = a + Z;
		y = (y + a * (i - 1)) % M;
		t = (a * (m - i)) % M;
		y = (y - t + M) % M;
	}
	cout << (x * y) % M;
    return 0;
}
