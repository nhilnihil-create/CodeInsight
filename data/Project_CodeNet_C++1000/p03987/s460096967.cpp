#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 200005;
typedef long long lld;
lld n;
lld a[N];
lld st[N], top = 0;
lld lef[N], rig[N];
lld ans = 0;
int main() {
//	freopen("data.in", "r", stdin);
	scanf("%lld", &n);
	for(lld i = 1; i <= n; i++) 
		scanf("%lld", &a[i]);
	for(lld i = 1; i <= n; i++) {
		if(a[i] > st[top]) {
			st[++top] = a[i]; 
			continue;
		}
		while(a[i] < st[top]) {
			rig[st[top]] = i;
			top--;
		}
		st[++top] = a[i];
	}
	while(top > 0){
		rig[st[top]] = n + 1;
		top--;
	}
	top = 0;
	for(lld i = n; i >= 1; i--) {
		if(a[i] > st[top]) {
			st[++top] = a[i];
			continue;
		}
		while(a[i] < st[top]) {
			lef[st[top]] = i;
			top--;
		}
		st[++top] = a[i];
	}
	while(top > 0) {
		lef[st[top]] = 0;
		top--;
	}
	for(lld i = 1; i <= n ;i++) {
		lld left = i - lef[a[i]];
		lld right = rig[a[i]] - i;
		lld tmp = 1ll * right * left;
		ans += 1ll * tmp * a[i];
	}
	printf("%lld\n", ans);
	return 0;
}