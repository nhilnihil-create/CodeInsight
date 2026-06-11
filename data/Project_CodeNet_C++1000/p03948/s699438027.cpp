#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define int long long

int n, A[N], T;

map < int, int > Map;

main() {
	cin >> n >> T;
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
	int Mi = 1e9, ans = 0;
	for(int i = 1; i <= n; ++ i) {
		Mi = min(Mi, A[i]);
		ans = max(ans, A[i] - Mi);
	}
	
	Mi = 1e9;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; ++ i) {
		++ Map[A[i]];
		Mi = min(Mi, A[i]);
		if(A[i] - Mi == ans) {
			cnt1 += Map[Mi];
			++ cnt2;
			Map[Mi] = 0;
		}
	}
	cout << min(min(cnt1, cnt2), 10000000000LL);
}