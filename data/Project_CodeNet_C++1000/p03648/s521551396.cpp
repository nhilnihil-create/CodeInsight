#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 56;

LL a[MAX_N];

int main () {
	LL n=50;
	LL k;
	scanf("%lld",&k);
	for (int i=1;n>=i;i++) {
		a[i] = (n-1) + (k/n);
	}
	k%=n;
	for (int i=1;k>=i;i++) {
		a[i] += (k + -(k-1));
	}
	for (int i=k+1;n>=i;i++) {
		a[i] += (-k);
	}
	puts("50");
	for (int i=1;n>=i;i++) {
		if (i!=1) printf(" ");
		printf("%lld",a[i]);
	}
	puts("");
}
