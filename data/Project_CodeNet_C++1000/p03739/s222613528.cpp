#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	long long ans0 = 0; 
	{
		long long sum0 = 0;
		//+-+-
		for (int i = 0; i < N; ++i) {
			sum0 += A[i];
			if (0 == i%2) {
				if (sum0 <= 0) {
					ans0 += (1 - sum0);
					sum0 = 1;
				}
			}
			else {
				if (sum0 >= 0) {
					ans0 += (sum0 -(-1));
					sum0 = -1;
				}
			}
		}
	}	
	long long ans1 = 0;
	{
		long long sum1 = 0;
		//-+-+
		for (int i = 0; i < N; ++i) {
			sum1 += A[i];
			if (1 == i % 2) {
				if (sum1 <= 0) {
					ans1 += (1 - sum1);
					sum1 = 1;
				}
			}
			else {
				if (sum1 >= 0) {
					ans1 += (sum1 - (-1));
					sum1 = -1;
				}
			}
		}
	}
	cout << min(ans0,ans1)<<endl;
	return 0;
}