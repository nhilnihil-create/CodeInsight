#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0;i<N;++i) {
		cin >> A[i];
	}
	sort(A.begin(),A.end());
	if (1 == N%2) {
		for (int i = 0;i<N;++i) {
			//02244......
			if (((i+1)/2)*2 !=A[i]) {
				cout << 0<<endl;
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			//113355......
			if ((1+(i/2) * 2) != A[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	int ans = 1;
	for (int i = 0;i<N/2;++i) {
		ans *= 2;
		ans %= 1000000007;
	}
	cout << ans<<endl;
	return 0;
}

