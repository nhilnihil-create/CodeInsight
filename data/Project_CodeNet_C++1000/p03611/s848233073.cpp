#include<bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	int cnt[101001] = {0};
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	int ans = 0;
	for (int i=1; i<100001; i++) {
		ans = max(ans, cnt[i-1]+cnt[i]+cnt[i+1]);
	}
	cout << ans;
	return 0;
}