#include<bits/stdc++.h>
using namespace std;
long long dfs(long long n,long long x)
{
	if(x>n) swap(x,n);
	if(n%x==0) return n/x*2*x-x;
	else return n/x*2*x+dfs(x,n%x);	
}
int main ()
{
	long long n,x;
	scanf("%lld%lld",&n,&x);
	printf("%lld\n",dfs(n-x,x)+n);
	
}