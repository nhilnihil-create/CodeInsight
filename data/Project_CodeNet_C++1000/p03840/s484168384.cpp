#include <bits/stdc++.h>


using namespace std;

int main() {
	long long a[7];

	for (int i = 0; i < 7; ++i) {
		cin >> a[i];
	}

	long long at = a[1] * 2;
	long long ans = 0;

	ans = (a[3]/2)*4 + (a[4]/2)*4 + (a[0]/2)*4;
	ans = max(ans, (a[3]>=1 && a[4]>=1 && a[0]>=1)*6 + ((a[3]-1)/2)*4 + ((a[4]-1)/2)*4 + ((a[0]-1)/2)*4);

	ans += at;

	cout << ans/2 << '\n';

}