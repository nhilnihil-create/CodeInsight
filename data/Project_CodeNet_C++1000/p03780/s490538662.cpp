#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define N 5001

int a[N];
bool dp[N][N];
bool suf[N];
int minValue[N][N];
void solve() {
	int n, k; scanf("%d %d", &n, &k);
	long long sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]); sum += a[i];
		if (a[i] >= k) {
			a[i] = k;
		}
	}
	if (sum < k) {
		printf("%d\n", n);
		return;
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = k; j >=0; --j) {
			dp[i][j] |= dp[i - 1][j];
			if (dp[i - 1][j]) {
				int go = min(k, j + a[i]);
				dp[i][go] = true;
			}
		}
	}
	for (int i = n; i >= 0; --i) {
		for (int j = k; j >= 0; --j) {
			minValue[i][j] = -1;
			if (j + 1 <= k) {
				minValue[i][j] = minValue[i][j + 1];
			}
			if (dp[i][j]) {
				minValue[i][j] = j;
			}
		}
	}

	suf[0] = true;
	int ret = 0;
	for (int i = n; i; --i) {
		int v = a[i];
		int lim = k - v;
		bool isGood = true;
		int mini = k;
		for (int j = 0; j <= k; ++j) {
			if (suf[j]) {
				int x = max(k - v - j, 0);
				if (minValue[i - 1][x] != -1) {
					int tt = minValue[i - 1][x] + j;
					mini = min(mini, tt);
				}
			}
		}
		if (mini >= k) {
			++ret;
		}
		
		for (int j = k; j >=0; --j) {
			if (suf[j]) {
				int go = min(k, j + a[i]);
				suf[go] = true;
			}
		}
	}
	printf("%d\n", ret);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
