#include <bits/stdc++.h>

#define MAXN (100010)

int n, a[MAXN];

bool solve(){
	int odd = 0, even = 0, sit;
	for(int i = 1; i <= n; ++ i){
		if(a[i] & 1){
			++ odd;
			sit = i;
		}
		else{
			++ even;
		}
	}
	
	if(even & 1) return true;
	if(odd >= 2) return false;
	
	if(a[sit] == 1) return false;
	-- a[sit];
	
	int gcd = std::__gcd(a[1], a[2]);
	for(int i = 3; i <= n; ++ i){
		gcd = std::__gcd(gcd, a[i]);
	}
	for(int i = 1; i <= n; ++ i){
		a[i] /= gcd;
	}
	
	return !solve();
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", a + i);
	}
	if(n == 1) return printf("Second\n"), 0;
	printf(solve() ? "First\n" : "Second\n");
	return 0;
}