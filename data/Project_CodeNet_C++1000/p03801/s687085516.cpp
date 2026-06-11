#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1e5;
int n;
struct node
{
	int a,num;
}q[N+5];
long long ans[N+1];

bool cmp(node x,node y)
{
	if(x.a!=y.a)
	    return x.a>y.a;
	else
	    return x.num<y.num;
}
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&q[i].a);
		q[i].num=i;
	}
	sort(q+1,q+1+n,cmp);
	int t=2,f=1;
	while(t<=n)
	{
		while(q[t].a==q[t-1].a)
		    t++;//因为要输出最小字典序，所以大一点的都要舍掉 
		ans[q[f].num]+=1ll*(q[f].a-q[t].a)*(t-1);
		if(q[f].num<q[t].num)
	        q[f].a=q[t].a;
	    else
	        f=t;
	    t++;
	}
	ans[q[f].num]+=1ll*q[f].a*n;
	for(int i=1;i<=n;i++)
	    printf("%lld\n",ans[i]);
	return 0;
}