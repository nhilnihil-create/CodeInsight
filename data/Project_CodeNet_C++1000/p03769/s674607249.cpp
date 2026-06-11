#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
ll n;
struct cc
{
	int l,r,num[210];
};
int num;
cc ksm(ll x)
{
	cc t;
	if(x==1)
	{
		memset(t.num,0,sizeof(t.num));
		t.l=101;
		t.r=100;
		return t;
	}
	t=ksm(x/2);
	t.num[++t.r]=++num;
	if(x&1) t.num[--t.l]=++num;
	return t;
}
int ans;
int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	cin>>n;
	++n;
	cc t=ksm(n);
	printf("%d\n",(t.r-t.l+1)*2);
	for(int i=t.l;i<=t.r;++i)
	printf("%d ",t.num[i]);
	for(int i=t.l;i<=t.r;++i)
	printf("%d ",i-t.l+1);
}
