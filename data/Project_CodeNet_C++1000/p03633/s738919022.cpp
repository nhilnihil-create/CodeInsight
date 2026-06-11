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

// �ő���񐔂����߂�֐�
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

// �ŏ����{�������߂�֐�
long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {

	long long N;
	cin >> N;

	vector<long long> T(N, 0);
	for (long long i = 0; i < N; i++) {
		cin >> T[i];
	}

	sort(T.begin(), T.end());

	long long ans = T[0];
	long long v_max = 0;
	long long v_min = 0;
	long long v_gcd = 0;

	for (long long i = 1; i < N; i++) {
		v_max = max(ans, T[i]);
		v_min = min(ans, T[i]);
		if (0 != v_max % v_min) {
			v_gcd = gcd(v_max, v_min);
			v_max = v_max / v_gcd;
			v_min = v_min / v_gcd;
			ans = v_max * v_min * v_gcd;
		}
		else {
			ans = v_max;
		}
	}

	cout << ans << endl;

	return 0;
}