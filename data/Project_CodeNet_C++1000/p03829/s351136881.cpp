#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 123456
using namespace std;
ll n,a,b,A[N],ans;
int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	for(int i=1;i<n;i++)
		ans += min(a*(A[i+1]-A[i]),b);
	printf("%lld\n",ans);
	return 0; 
}