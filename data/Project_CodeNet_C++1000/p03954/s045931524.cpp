#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 200005;
int arr[MAXN], num[MAXN], n;

bool check(int mid) {
	for (int i = 1; i < 2 * n; i++) num[i] = arr[i] >= mid;
	num[0] = num[1], num[2 * n] = num[2 * n - 1];
	int l = n, r = n;
	while (num[l - 1] != num[l]) --l;
	while (num[r + 1] != num[r]) ++r;
	return r - n < n - l ? num[r] : num[l];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < 2 * n; i++) scanf("%d", arr + i);
	int l = 1, r = 2 * n;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%d\n", l);
	return 0;
}