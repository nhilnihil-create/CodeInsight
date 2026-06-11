#include <bits/stdc++.h>
using namespace std;

long long a[10];

int main(){
	long long ans;
	for (int i = 1; i <= 7; i++) scanf("%lld",&a[i]);
	ans = a[1] / 2 * 4 + a[4] / 2 * 4 + a[5] / 2 * 4 + a[2] * 2;
	if (a[1] == 0 || a[4] == 0 || a[5] == 0) ;
	else if (a[1] % 2 == 0 && a[4] % 2 == 0 && a[5] % 2 == 0) ;
	else if (a[1] % 2 == 1 && a[4] % 2 == 1 && a[5] % 2 == 1) ans += 6;
	else if ((a[1] + a[4] + a[5]) % 2 == 0) ans += 2;
	printf("%lld\n", ans / 2);
	return 0;
}