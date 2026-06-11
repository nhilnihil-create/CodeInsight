#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0;i<N;++i) {
		cin >> A[i];
		A[i]--;
	}
	int now = 0;
	for (int i = 0;i<N;++i) {
		if (now == 1) {
			cout <<i <<endl;
			return 0;
		}
		now = A[now];
	}
	cout << -1<<endl;
	return 0;
}