#include <cstdio>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int a[n]; for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	int ans = 0;
	for (int a_i = 0; a_i < n; ++a_i) {
		int like_i = a[a_i] - 1; //idxに変換

		if (like_i < a_i) continue; // すでに調査済み

		if (a[like_i] - 1 == a_i) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}