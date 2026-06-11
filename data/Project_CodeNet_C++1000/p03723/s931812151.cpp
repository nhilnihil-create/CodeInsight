#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	long long ans;
	if (A == B && B == C && A % 2 == 0)
		ans = -1;
	else if (A == B && B == C && A % 2 == 0)
		ans = 0;
	else {
		ans = 0;
		while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
			int a = A, b = B, c = C;
			A = (b + c) / 2;
			B = (c + a) / 2;
			C = (a + b) / 2;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}