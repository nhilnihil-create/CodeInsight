#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;

int main() {
	int N;
	cin >> N;
	string S1, S2;
	cin >> S1 >> S2;
	vector<ll> A(N);
	vector<bool> st(N, true); //縦置きがtrue
	int i = 0;
	while (i < N) {
		if (S1[i] == S2[i]) {
			if (i) {
				if (st[i - 1])
					A[i] = A[i - 1] * 2;
				else
					A[i] = A[i - 1];
			}
			else
				A[i] = 3;
			A[i] %= MOD;
			i++;
		}
		else {
			if (i) {
				if (st[i - 1])
					A[i] = A[i - 1] * 2;
				else
					A[i] = A[i - 1] * 3;
			}
			else
				A[i] = 6; //Debug #1
			A[i] %= MOD;
			A[i + 1] = A[i];
			st[i + 1] = false;
			i += 2;
		}
	}
	cout << A[N - 1] << endl;
}