#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> E(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		E[max(a - 1, b - 1)]++;
		E[min(a - 1, b - 1)]--;
	}
	bool ans = true;
	int now = E[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (now % 2 != 0) ans = false;
		now += E[i];
	}
	cout << (ans ? "YES" : "NO") << endl;
}
