#include<stdio.h>
#include<deque>
#include<vector>
using namespace std;
int a[121212], indeg[121212], D[121212];
int max(int a, int b) { if (a < b)return b; return a; }
deque<int>Q;
int main() {
	int n, k, i, j, ans; scanf("%d%d", &n,&k);
	for (i = 1; i <= n; i++)scanf("%d", &a[i]);
	if (k == 1) {
		ans = 0;
		for (i = 1; i <= n; i++)if (a[i] != 1)ans++;
		printf("%d", ans);
		return 0;
	}
	ans = a[1] != 1;
	a[1] = 1;
	for (i = 1; i <= n; i++)indeg[a[i]]++;
	for (i = 1; i <= n; i++)if (indeg[i] == 0)Q.push_back(i);
	while (!Q.empty()) {
		int now = Q.front(); Q.pop_front();
		indeg[a[now]]--;
		if (D[now] == k - 1) ans+=(a[now]!=1);
		else D[a[now]] = max(D[a[now]], D[now] + 1);
		if (indeg[a[now]] == 0)Q.push_back(a[now]);
		a[now] = 0;
	}
	for (i = 2; i <= n; i++) {
		int now = i;
		vector<int>L;
		while (a[now]) {
			L.push_back(D[now]);
			int temp = now;
			now = a[now];
			a[temp] = 0;
		}
		int mx = 0, mxw = 0;
		for (j = 0; j < L.size(); j++) {
			if (L[j] > mx)L[j] = mx, mxw = j;
		}
		now = 0;
		for (j = 0,k = mxw; j < L.size(); j++, k++) {
			now++;
			if (now == k) ans++, now = 0;
			now = max(now, L[j]);
		}
	}
	printf("%d", ans);
	return 0;
}