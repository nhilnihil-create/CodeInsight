#include<iostream>
using namespace std;
long long n, a[120000], ret = 1;
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	long long L = 0, C = 0;
	for (int i = 0; i < n; i++) {
		while (L < n && a[L] >= C * 2) {
			bool P = true;
			if (a[L] == C * 2)P = false;
			C++; L++;
			if (P == false)break;
		}
		ret *= (L - i); C--; ret %= 1000000007;
	}
	cout << ret << endl;
	return 0;
}