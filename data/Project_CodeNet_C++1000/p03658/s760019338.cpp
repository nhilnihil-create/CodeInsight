#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N, L[55] = {}, K, max = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	sort(L, L + N, greater<int>());
	for (int i = 0; i < K; i++) {
		max += L[i];
	}
	cout << max << endl;

	return 0;
}