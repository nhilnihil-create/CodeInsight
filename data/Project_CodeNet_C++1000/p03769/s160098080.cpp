#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)

int x[201];

int main(){
	ll n;
	scanf("%lld", &n);
	if (n < 100){
		printf("%lld\n", n << 1);
		for (int i = n; i > 0; --i)printf("%d ", i);
		printf("1");
		f(i, 2, n + 1)printf(" %d", i);
		printf("\n");
		return 0;
	}
	f(i, 1, 101)x[i] = 101 - i;
	f(i, 1, 101)x[i + 100] = i;
	ll need = n - 100, z = 1;
	int b = 0, l = 0;
	while (need){
		int i = 99;
		if (need >> b & 1)swap(x[100], x[99]), need ^= z, --i;
		z <<= 1;
		while (need >= z && i > 1 + l){
			swap(x[i], x[i + 1]);
			--i;
			swap(x[i], x[i + 1]);
			--i;
			need -= z;
		}
		++b;
		l = i + 1;
	}
	printf("200\n%d", x[1]);
	f(i, 2, 201)printf(" %d", x[i]);
	printf("\n");
}
