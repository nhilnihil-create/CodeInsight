#include <iostream>
using namespace std;

int N, M, A[1 << 18], B[1 << 18];
int cnt[1 << 18];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		if (A[i] > B[i]) swap(A[i], B[i]);
		cnt[A[i]]++; cnt[B[i]]--;
	}
	for (int i = 1; i <= N; i++) cnt[i] += cnt[i - 1];
	for (int i = 1; i <= N; i++) {
		if (cnt[i] % 2 == 1) { cout << "NO" << endl; return 0; }
	}
	cout << "YES" << endl;
	return 0;
}