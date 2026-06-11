#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& x : A) cin >> x;
	long long r = 1;
	int s = 0;
	for (int i = 0; i < N; ++ i) {
		while (s < i) {
			if (A[i-1] < 2*i-1-2*s) ++ s; else break;
		}
		int n = i - s + 1;
		(r *= n) %= mod;
	}
	cout << r << endl;
}
