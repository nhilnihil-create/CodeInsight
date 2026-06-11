#include "bits/stdc++.h"
using namespace std;

long long N;
static vector<long long> V[100000];

long long DFS(long long P) {
	if (V[P].empty()) return 0;
	vector<long long> VX;
	long long Cur = 0;
	for (int X : V[P]) VX.push_back(DFS(X));
	sort(VX.begin(), VX.end());
	for (long long Y : VX) Cur = max(Cur, Y) + 1;
	return Cur;
}

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		long long A;
		cin >> A;
		A--;
		V[A].push_back(i);
	}
	cout << DFS(0) << endl;
}