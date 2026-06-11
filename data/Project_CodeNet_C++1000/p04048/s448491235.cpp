#include<bits/stdc++.h>
using namespace std;
int len;
long long ans=0;
long long dfs(long long x,long long n)
{
	if(n%x==0)
        return n*2-x;
    ans=n/x*x*2+dfs(n%x,x);
	return ans;
}
int main()
{
	long long n,k;
	scanf("%lld%lld",&n,&k);
	printf("%lld\n",dfs(k,n-k)+n);
}