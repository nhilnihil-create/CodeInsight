#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
int cnt[100001];
int cnt2[100000];
int odd[100000];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		cnt[X]++;
	}
	for (int i = 1; i <= 100000; i++) {
		cnt2[i%M] += cnt[i];
		odd[i%M] += cnt[i]%2;
	}
	int ans = 0;
	for (int i = 1; i*2 < M; i++) {
		int m = min(odd[i], odd[M - i]);
		int d = abs(odd[i] - odd[M - i]);
		ans += m;
		cnt2[i] -= m;
		cnt2[M - i] -= m;
		odd[i] -= m;
		odd[M - i] -= m;
		if (odd[i] <= odd[M - i]) {
			int t = min(cnt2[i]/2, d/2)*2;
			ans += t;
			cnt2[i] -= t;
			cnt2[M - i] -= t;
			odd[M - i] -= t;
		} else {
			int t = min(cnt2[M - i]/2, d/2)*2;
			ans += t;
			cnt2[i] -= t;
			cnt2[M - i] -= t;
			odd[i] -= t;
		}
		ans += (cnt2[i] - odd[i])/2;
		ans += (cnt2[M - i] - odd[M - i])/2;
	}
	{
		int t = odd[0]/2;
		cnt2[0] -= t*2;
		odd[0] -= t*2;
		ans += t;
		ans += (cnt2[0] - odd[0])/2;
	}
	if(M%2 == 0) {
		int t = odd[M/2]/2;
		cnt2[M/2] -= t*2;
		odd[M/2] -= t*2;
		ans += t;
		ans += (cnt2[M/2] - odd[M/2])/2;
	}
	cout << ans << endl;
}