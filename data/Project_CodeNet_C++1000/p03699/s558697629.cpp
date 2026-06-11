#include "bits/stdc++.h"
using namespace std;

int main() {
	int N; 
	cin >> N;
	vector<int>A(N);
	vector<int>B;
	int sum = 0;
	for (int i = 0;i<N;++i) {
		cin >> A[i];
		sum += A[i];
		if (0 != A[i]%10) {
			B.push_back(A[i]);
		}
	}
	sort(B.begin(),B.end());
	if (0 != sum%10) {
		cout <<sum <<endl;
		return 0;
	}
	if (0 == B.size()) {
		cout << 0 <<endl;
	}
	else {
		cout << sum - B[0] << endl;
	}
	return 0;
}