#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define il inline 
#define re register
#define LL long long
using namespace std;
const int mod = 1e9 + 7;
const int INF = (1 << 30);
const int maxn = 2e5 + 50;
LL read() {
    LL res = 0, f = 1; char ch = ' ';
    while (!isdigit(ch)) { ch = getchar(); if (ch == '-') f = -1; } 
    while (isdigit(ch)) res = (res << 3) + (res << 1) + ch - '0', ch = getchar();
    return res * f;
}

int n, a[maxn], ans;
bool Check(int k) {
	for (re int i = 0; i < n - 1; ++i) {
		if ((a[n + i] > k && a[n + i + 1] > k) || (a[n - i] > k && a[n - i - 1] > k)) return 0;
		if ((a[n + i] <= k && a[n + i + 1] <= k) || (a[n - i] <= k && a[n - i - 1] <= k)) return 1;
	}
	return a[1] <= k;
}
int main() {
	n = read();
	for (re int i = 1; i < 2 * n; ++i) a[i] = read();
	int l = 1, r = 2 * n - 1;
	while (l <= r) {
		int mid = (l + r >> 1);
		if (Check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}
