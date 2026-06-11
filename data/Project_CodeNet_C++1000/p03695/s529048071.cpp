#include "bits/stdc++.h"
using namespace std;

int main() {
	int N; 
	cin >> N;
	vector<int>A(8);
	int count = 0;
	for (int i = 0;i<N;++i) {
		int num;
		cin >> num;
		if (num < 3200) {
			A[num / 400]++;
		}
		else {
			count++;
		}
	}

	int ans = 0;
	for (int i = 0;i<8;++i) {
		if (A[i]>0) {
			ans++;
		}
	}
	if (0 != ans) {
		cout << ans << " " << ans + count << endl;
	}
	else {
		cout << 1 << " " << ans + count << endl;
	}
	return 0;
}