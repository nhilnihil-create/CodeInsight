#include<cstdio>
int n, m;
int a[105], odd[105],even[105],cnt1,cnt2;
int main() {
	scanf("%d%d", &n, &m);
	int i;
	int cnt2 = 0;
	for (i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0) even[++cnt2] = a[i];
		else odd[++cnt1] = a[i];
	}
	if (cnt1 > 2) {
		printf("Impossible");
	}
	else {
		int cnt=0, ans[100005];
		if (cnt1 == 0) {
			ans[++cnt] = 1;
			for (i = 1; i <= cnt2; i++) {
				ans[++cnt] = even[i];
			}
			ans[cnt]--;
		}
		else if (cnt1 == 1) {
			if (odd[1] > 1) ans[++cnt] = odd[1] - 1;
			ans[++cnt] = 2;
			for (i = 1; i <= cnt2; i++) {
				ans[++cnt] = even[i];
			}
			ans[cnt]--;
		}
		else {
			if (odd[1] > 1) ans[++cnt] = odd[1] - 1;
			ans[++cnt] = 2;
			for (i = 1; i <= cnt2; i++) {
				ans[++cnt] = even[i];
			}
			if (odd[2] > 1) ans[++cnt] = odd[2] - 1;
		}
		if (cnt1 >= 1) printf("%d ", odd[1]);
		for (i = 1; i <= cnt2; i++) printf("%d ",even[i]);
		if (cnt1 > 1) printf("%d", odd[2]);
		printf("\n%d\n", cnt);
		for (i = 1; i <= cnt; i++) printf("%d ", ans[i]);
	}
	return 0;
}