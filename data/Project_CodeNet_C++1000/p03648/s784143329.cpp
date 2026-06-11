#include <iostream>
#include <stdio.h>
#include <string.h>
#define int long long

using namespace std;

signed main()
{
	int n=50,K;
	scanf("%lld",&K);
	int avg=K/n,rst=K%n;
	printf("%lld\n",n);
	for(int i=1;i<=rst;i++) printf("%lld ",n-1+avg-rst+n);
	for(int i=rst+1;i<=n;i++) printf("%lld ",n-1+avg-rst);
	printf("\n");
}
