#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	int m = 0; //要素数m
	rep(i, n) {
		int a;
		scanf("%d", &a);
		if(a % 2 == 1) m++;
	}
	if(m == 0) {
		if(p == 0) printf("%lld\n", 1ll << n); //2^n
		else printf("0\n");
	}
	else {
		printf("%lld\n", 1ll << (n - 1)); //2^n-1
	}
	return 0;
}