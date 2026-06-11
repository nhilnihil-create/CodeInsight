#include<bits/stdc++.h>
using namespace std;

void out()
{
	puts("No");
	exit(0);
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=500+5;
int cnt[N],px[N],q[N],a[N*N];
bool x_xiao(int a,int b)
{
	return px[a]<px[b];
}

int main()
{
	//freopen("1.in","r",stdin);
	int n;
	cin>>n;
	rep(i,1,n)cin>>px[i];
	rep(i,1,n)q[i]=i;
	sort(q+1,q+n+1,x_xiao);
	rep(i,1,n)cnt[i]=q[i]-1;
	int j1=1,j2=1,j3=1;//[j2,n]>i,[1,j1)solved,[j2,j3)solved
	rep(i,1,n*n)
	if(px[q[j2]]==i)
	{
		if(cnt[j2])out();
		a[i]=q[j2];
		cnt[j2]=n-q[j2];
		++j2;
		if(j3<j2)j3=j2;
	}
	else
	{
		while(!cnt[j3]&&j3<=n)++j3;
		if(j3<=n)
		{
			a[i]=q[j3];
			--cnt[j3];
			continue;
		}
		while(!cnt[j1]&&j1<=n)++j1;
		if(j1>n)out();
		a[i]=q[j1];
		--cnt[j1];
	}
	puts("Yes");
	rep(i,1,n*n)printf("%d ",a[i]);
}