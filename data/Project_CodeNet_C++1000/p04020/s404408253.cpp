#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += A[i] / 2;
		A[i] %= 2;
		if (A[i] > 0 && i < n-1 && A[i+1] > 0) {
			A[i]--;
			A[i+1]--;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}