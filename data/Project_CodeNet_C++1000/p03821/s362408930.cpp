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

	long long N;
	cin >> N;

	vector<long long> A(N, 0);
	vector<long long> B(N, 0);

	for (long long i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}

	long long ans = 0;
	for (long long i = N - 1; i >= 0; i--) {
		A[i] += ans;
		ans += (B[i] - A[i] % B[i]) % B[i];
	}

	cout << ans << endl;

	return 0;
}