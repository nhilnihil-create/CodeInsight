#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define N 200002
ll n,X;
ll cal(ll x,ll y)
{
	if(x%y==0)return y*(2*(x/y)-1);
	return cal(y,x%y)+2*y*(x/y);
}
int main()
{
	scanf("%lld%lld",&n,&X);
	if(X>n/2)X=n-X;
	printf("%lld\n",cal(n-X,X)+n);
}
