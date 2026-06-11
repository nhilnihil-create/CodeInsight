#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N;
	cin >> N;
	long long ans = 1e18;
	for (long long i = 1; i*i <= N; ++i) {
		if (0 == N % i) {
			long long y = 0;
			long long subi = N / i; 
			while (subi > 0) {
				y++;
				subi /= 10;
			}
			ans = min(ans, y);
		}
	}
	cout << ans << endl;
	return 0;
}