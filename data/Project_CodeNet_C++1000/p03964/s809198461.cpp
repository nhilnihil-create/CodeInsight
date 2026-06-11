#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, T[1005], A[1005];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> A[i];
	}
	long long int t[1005] = { 0 };
	long long int a[1005] = { 0 };
	long long int x[1005] = { 0 };
	t[1] = T[1], a[1] = A[1];
	for (int i = 2; i <= N; i++) {
		long long int tt, aa;
		tt = aa = 0;
		if (t[i - 1] % T[i] == 0) {
			tt = t[i - 1] / T[i];
		}else{ tt = t[i - 1] / T[i] + 1; }
		if (a[i - 1] % A[i] == 0) {
			aa = a[i - 1] / A[i];
		}
		else { aa = a[i - 1] / A[i] + 1; }
		x[i] = max(tt, aa);
		t[i] = T[i] * x[i];
		a[i] = A[i] * x[i];
	}
	cout << t[N] + a[N];
	return 0;
}