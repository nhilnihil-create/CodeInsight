#include <bits/stdc++.h>
using namespace std;

int main(){
	long n, m;
	scanf("%ld%ld", &n, &m);
	long ans = 0;
	long s = m / 2;
	if(n <= s) {
		ans += n;
		m -= 2 * n;
	}else{
		ans += s;
		m -= 2 * s;
	}
	ans += m / 4;
	printf("%ld\n", ans);
}
