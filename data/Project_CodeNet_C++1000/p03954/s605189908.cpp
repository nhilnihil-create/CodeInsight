#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,nn,a[N],b[N],l,r;
inline bool check(int k)
{
	for(int i=1;i<=nn;i++)
		if(a[i]<k) b[i]=0;
		else b[i]=1;
	int pos1=1e8,pos0=1e8;	
	for(int i=1;i<nn;i++)
		if(b[i]==b[i+1])
		{
			if(b[i]) 
			{
				pos1=min(pos1,min(abs(n-i),abs(n-(i+1))));
			}
			else 
			    pos0=min(pos0,min(abs(n-i),abs(n-(i+1))));
		}
	if(pos1==1e8&&pos0==1e8)
	   return (n&1)==b[n];
	return pos1<pos0;
}
int main()
{
//	freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	scanf("%d",&n);//n=read();
	nn=2*n-1;
	for(int i=1;i<=nn;i++)
	{
		scanf("%d",&a[i]);//a[i]=read();
	}
	l=-1;r=1e8;
	while(r-l>1)
	{ 
		int mid=(l+r)/2;	
		if(check(mid)) l=mid;
		else r=mid;
	}	
	printf("%d",l);//write(l);
	return 0;
}