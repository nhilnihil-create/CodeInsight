#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 300000+5
#define ll long long
using namespace std;
ll n,A[N],ans;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=3*n;i++) scanf("%lld",&A[i]);
	sort(A+1,A+1+3*n);
	for(ll i=(3*n)-1;i>=n+1;i-=2) ans += A[i];
	printf("%lld",ans);
	return 0;
}