#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int arr[MAXN], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", arr + i);
	sort(arr + 1, arr + 1 + n);
	reverse(arr + 1, arr + 1 + n);
	int p = 0;
	for (int i = 1; i <= n; i++)
		if (arr[i] >= i) p = i;
		else break;
	if ((arr[p] - p) & 1) return puts("First") * 0;
	int q = 0;
	for (int i = p + 1; i <= n; i++)
		if (arr[i] >= p) ++q;
		else break;
	if (q & 1) return puts("First") * 0;
	puts("Second");
	return 0;
}