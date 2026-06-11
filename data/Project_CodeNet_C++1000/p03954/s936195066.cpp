#include<bits/stdc++.h>
using namespace std;
int n;
int l,r;
int a[10000005];
inline int read()
{
   int s=0,w=1;
   char ch;
   ch=getchar();
   while(ch>'9'||ch<'0')
   {
	  if(ch=='-')
	 {
	   w=-1;
	 }
	   ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
	  s=(s<<1)+(s<<3)+(ch^48);
	  ch=getchar();}
	  return s*w;
}
inline bool check(int a,int b,int c)
{
	return a<=c&&b<=c;
}
inline bool checkb(int a,int b,int c)
{
	return a>c&&b>c;
}
inline int pd(int x)
{
	for(int i=0;i<n-1;i++)
	{
		if(checkb(a[n+i],a[n+i+1],x)||checkb(a[n-i],a[n-i-1],x)) 
		{
			return 0;
		}
		if(check(a[n+i],a[n+i+1],x)||check(a[n-i],a[n-i-1],x))
		{
			return 1;
		}
		
	}
	return check(a[1],a[1],x);
}
int main()
{
	//freopen("pyramid.in","r",stdin);
	//freopen("pyramid.out","w",stdout);
	n=read();
	for(int i=1;i<=2*n-1;i++)
	{
		a[i]=read();
	}
	l=1;
	r=2*n-1;
	int mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(pd(mid))
		{
			r=mid;
		}
		else 
		{
			l=mid+1;	
		}
	}
	cout<<r;
	return 0;

}


