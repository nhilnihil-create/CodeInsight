#include <bits/stdc++.h>
int n, x, e;
long long ans = 1, MOD = 1e9+7;
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		if(2*(i-e) >= x) (ans *= i+1-e++) %= MOD;
	}
	for(int i=n-e; i>0; i--) (ans *= i) %= MOD;
	printf("%lld\n", ans);
}