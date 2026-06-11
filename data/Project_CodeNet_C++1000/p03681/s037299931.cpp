#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	long long N, M;
	cin >> N >> M;

	long long ans = 1;

	long long bv = 1000000007;

	if (abs(N - M) > 1) {
		cout << 0 << endl;
	}
	else if (abs(N - M) == 1) {
		for (long long i = 1; i <= N; i++) {
			ans *= i;
			ans %= bv;
		}
		for (long long i = 1; i <= M; i++) {
			ans *= i;
			ans %= bv;
		}
		cout << ans << endl;
	}
	else {
		ans = 2;
		for (long long i = 1; i <= N; i++) {
			ans *= i;
			ans %= bv;
		}
		for (long long i = 1; i <= M; i++) {
			ans *= i;
			ans %= bv;
		}
		cout << ans << endl;
	}

	

	return 0;
}