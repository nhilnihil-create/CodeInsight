#include <bits/stdc++.h>
using namespace std;

long long x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> x;

	long long lo = 1, mid, hi = 1e15;
	while (lo <= hi) {
		mid = (lo+hi) / 2;
		long long R = (mid / 2 + (mid&1)) * 6 + (mid / 2) * 5;
		long long L = R - ((mid&1) ? 6 : 5) + 1;
		if (L <= x && x <= R) {
			cout << mid << '\n';
			return 0;
		}
		else if (R <= x) {
			lo = mid+1;
		}
		else {
			hi = mid-1;
		}
	}

	return 0;
}