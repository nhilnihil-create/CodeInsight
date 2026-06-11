#include <bits/stdc++.h>
using namespace std;
int main() {
	int N; int L = 0; int H = 0; cin >> N;vector<int>A(8);
	for (int X = 0; X < N; X++) {
		int S; cin >> S;
		if (S < 3200 && A[S / 400] == 0) A[S / 400] = 1;
		if (S > 3199)L++;
	}
	cout << max(1,A[0]+A[1]+A[2]+A[3]+A[4]+A[5]+A[6]+A[7]) << " " << L+A[0]+A[1]+A[2]+A[3]+A[4]+A[5]+A[6]+A[7] << endl;
}
