#include <bits/stdc++.h>

using namespace std;

//20 - 25 (wrong solution)
//30

int main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	int ok = 0;
	for (int back = 0; back < n; ++back) {
		long long left = c*1ll*(n-1-back) - d*1ll*back;
		long long right = d*1ll*(n-1-back) - c*1ll*back;
		if(left <= b-a && b-a <= right) {
			ok = 1;
		}
	}
	if(ok) puts("YES");
	else puts("NO");
}