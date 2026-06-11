#include<bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	long long res = A[0] - 1;
	int ma = 1;
	for (int i = 1; i < N; i++) {
		if (A[i] == ma + 1) ma++;
		if (A[i] <= ma) continue;
		res += (A[i]-1) / (ma+1);
	}
	cout << res << endl;
}