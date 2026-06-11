#include <bits/stdc++.h>

#define MAXN (100010)
#define mod (1000000007)

int n;
int x[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", x + i);
	}
	int ans = 1;
	for(int i = 1, j = 1; i <= n; ++ i){
		while(j < n && x[j] >= 2 * (j - (i - 1)) - 1) 
		    ++ j;
		ans = (1ll) * ans * (j - i + 1) % mod;
	}
	printf("%d\n", ans);
	return 0;
}