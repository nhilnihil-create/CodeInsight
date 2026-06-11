#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long n, a, b, c, d;

int main() {
	cin >> n >> a >> b >> c >> d;
	a = abs(a - b);
	a <<= 1, c <<= 1, d <<= 1;
	for (int i = 1; i < n; ++i)
		if (a > 0) a -= (c + d) / 2;
		else a += (c + d) / 2;
	a = abs(a);
	if (a > (n - 1) * (d - c) / 2) cout << "NO";
	else cout << "YES";
	return 0;
}
