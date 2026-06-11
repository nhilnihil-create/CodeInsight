#include <bits/stdc++.h>
using namespace std;

int a[55];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n, greater<int>());
	int ans = 0;
	for(int i = 0; i < k; i++)
		ans += a[i];
	printf("%d\n", ans);
}
