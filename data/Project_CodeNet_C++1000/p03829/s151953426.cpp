#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	long A, B, ans = 0;
	cin >> N >> A >> B;
	vector<long> X(N);
	for (long& i : X) cin >> i;
	for (int i = 1; i < N; i++) ans += min((X[i] - X[i - 1]) * A, B);
	cout << ans;
}