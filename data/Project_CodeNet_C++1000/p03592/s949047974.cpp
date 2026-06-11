#include <bits/stdc++.h>
using namespace std;

int main (){
	int n, m, k, i;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0; i <= m; ++i){
		int p = i * n;
		int q = m - i * 2;
		if(q == 0) continue;
		int r = (k - p) / q;
		if((k - p) == q * r && 0 <= r && r <= n){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
