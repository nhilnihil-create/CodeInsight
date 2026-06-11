#include<cstdio>
#include<iostream>

using namespace std;

#define N 100001 

int a[N];
long long cnt[N<<1];

void read(int &x)
{
	x=0; char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) { x=x*10+c-'0'; c=getchar(); }
}

int main()
{
	int n,m;
	read(n); read(m);
	for(int i=1;i<=n;++i) read(a[i]);
	int l,r;
	long long tot=0;
	for(int i=1;i<n;++i)
	{
		l=a[i];
		r=a[i+1];
		if(l>r) r+=m;
		tot+=r-l;
		if(r-l>1)
		{
			cnt[l+2]++; 
			cnt[r+1]-=r-(l+2)+2;
			cnt[r+2]+=r-(l+2)+1;
		}
	}
	for(int i=1;i<=m*2;++i) cnt[i]+=cnt[i-1];
	for(int i=1;i<=m*2;++i) cnt[i]+=cnt[i-1];
	long long ans=tot;
	for(int i=1;i<=m;++i) ans=min(ans,tot-cnt[i]-cnt[i+m]);
	cout<<ans;
}