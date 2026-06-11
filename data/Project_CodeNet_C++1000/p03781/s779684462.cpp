#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int x; cin >> x;
	int st = 1, en = x, mid, ret = 0;
	while (st <= en) {
		mid = st + en >> 1;
		if ((long long)mid * (mid + 1) / 2 >= x) ret = mid, en = mid - 1;
		else st = mid + 1;
	}
	cout << ret << "\n";
	
	return 0;
}
