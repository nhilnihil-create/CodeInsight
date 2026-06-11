#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	map<long long, int>mp;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		mp[n]++;
	}
	vector<long long>A;
	vector<long long>B;
	long long ans = 0;
	for (auto p : mp) {
		if (p.second>=2) {
			A.push_back(p.first);
		}		
		if (p.second >= 4) {
			B.push_back(p.first);
		}
	}
	sort(A.rbegin(),A.rend());	
	sort(B.rbegin(), B.rend());
	if (A.size() >= 2) {
		ans = max(ans,A[0] * A[1]);
	}
	if (B.size() >= 1) {
		ans = max(ans, B[0] * B[0]);
	}
	cout << ans << endl;
	return 0;
}