#include <bits/stdc++.h>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)

const int MD = 1000000007;

int n, A[111111];
int main() {
	int ans = 1;
	cin >> n;
	For(i,1,n) scanf("%d", &A[i]);
	A[1] = 1;
	int cnt = 1;
	For(i,2,n) {
		A[i] = min(A[i], A[i - 1] + 2);
		ans = (long long)ans * (cnt + 1) % MD;
		if (A[i] > A[i - 1] + 1) ++cnt; else A[i] = A[i - 1];
	}
	cout << ans << endl;
	return 0;
}