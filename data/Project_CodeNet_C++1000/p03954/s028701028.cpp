#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005], n;
bool check(int k){
	int i, j;
	for(i = 1 ; i <= n * 2 - 1 ; ++i)
		b[i] = a[i] >= k;
	if(b[n - 1] == b[n] || b[n] == b[n + 1])
		return b[n];
	i = n - 1, j = n + 1;
	while(i){
		if(b[i] == b[i + 1]) return b[i];
		if(b[j] == b[j - 1]) return b[j];
		--i, ++j;
	}
	return !((n & 1) ^ b[n]);
}
int main(){
	int i, l, r, mid, ans = 0;
	scanf("%d", &n);
	for(i = 1 ; i <= n * 2 - 1 ; ++i)
		scanf("%d", &a[i]);
	l = 1, r = 2 * n - 1;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
