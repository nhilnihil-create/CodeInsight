#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, m, a, b;
ll M = 1e9 + 7;
int main()
{
	ll i, t1, t2;
	cin >> n >> m;
	n--, m--;
	cin >> t2;
	for (i = 1; n; i++, n--) {
		scanf("%lld", &t1);
		a = (a + i * n * (t1 - t2) % M) % M;
		t2 = t1;
	}
	cin >> t2;
	for (i = 1; m; i++, m--) {
		scanf("%lld", &t1);
		b = (b + i * m * (t1 - t2) % M) % M;
		t2 = t1;
	}
    cout << a * b % M << endl;
    return 0;
}