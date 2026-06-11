#include <iostream>
#include <algorithm>
using namespace std;
int N, K, a[100009], b[100009];
long long solve(int x) {
	long long ret = 0;
	for (int i = 0; i < N; i++) {
		if ((x & a[i]) == a[i]) ret += b[i];
	}
	return ret;
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
	long long ret = solve(K);
	for (int i = 0; i < 30; i++) {
		if (K & (1 << i)) {
			int val = (K - (1 << i)) | ((1 << i) - 1);
			ret = max(ret, solve(val));
		}
	}
	cout << ret << endl;
	return 0;
}