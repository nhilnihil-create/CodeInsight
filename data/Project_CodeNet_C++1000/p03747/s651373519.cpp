#include<bits/stdc++.h>
using namespace std;
const int N=200001;
int n,l,t,dir;
struct node{
	int pos,id,dir;
}a[N];
node b[N];
int ans[N],rk[N];

bool cmp(node x,node y)
{
	if(x.pos==y.pos) return x.id<y.id;
	return x.pos<y.pos;
}

int main()
{
	scanf("%d%d%d",&n,&l,&t);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d",&a[i].pos,&a[i].dir);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	rk[1]=1; int tmp=a[1].pos;
	for(int i=1;i<=n;i++)
	{
		int tmp=t;
		if(a[i].dir==1)
		{
			if(tmp>=l-a[i].pos)
			{
				rk[1]=(rk[1]+1)%n;
				tmp-=(l-a[i].pos);
			}
			rk[1]=(rk[1]+tmp/l)%n;
		}
		else
		{
			if(tmp>=a[i].pos+1)
			{
				rk[1]=(rk[1]-1+n)%n;
				tmp-=(a[i].pos+1);
			}
			rk[1]=((rk[1]-tmp/l)%n+n)%n;
		}
	}
	if(rk[1]==0) rk[1]=n;
	//cout<<rk[1]<<endl;
	for(int i=2;i<=n;i++) 
	{
		rk[i]=rk[i-1]+1;
		if(rk[i]>n) rk[i]-=n;
	}
	for(int i=1;i<=n;i++) 
	{
		if(a[i].dir==1) a[i].pos=(a[i].pos+t)%l;
		else a[i].pos=((a[i].pos-t)%l+l)%l;
		b[i]=a[i];
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i].pos<<" "<<a[i].id<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		ans[b[i].id]=a[rk[i]].pos;
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}