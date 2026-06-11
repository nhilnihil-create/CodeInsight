#include <iostream>
#include <cstdio>
using namespace std;

long long n, x, s, mn=1e18, a[2005], m[2005];
int main() {
	int i, j;
	cin >> n >> x;
	for(j=0; j<n; j++) cin >> a[j], m[j] = 1e18;
	for(i=0; i<n; i++) {
		s = 0;
		for(j=0; j<n; j++) {
			m[j] = min(m[j], a[(j-i+n)%n]);
			s += m[j];
		}
		mn = min(mn, s + i*x);
	}
	cout << mn;
	return 0;
}
