/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++) 
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,b,a,h[100010],lb=0,ub=1e9,mid;

bool check()
{
	LL ss=b*mid,ret=0;
	rep(i,n)
	{
		if(h[i]-ss>0) ret+=(h[i]-ss+a-b-1)/(a-b);
	}
	return ret<=mid;
}

int main()
{
	cin>>n>>a>>b;
	rep(i,n) scanf("%lld",&h[i]);
	while(lb<ub)
	{
		mid=(lb+ub)/2;
		if(check()) ub=mid;
		else lb=mid+1;
	}
	cout<<lb<<endl;
	rt0;
}