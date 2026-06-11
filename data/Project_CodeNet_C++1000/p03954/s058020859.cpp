#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define inf 2147483647
#define mid (l+r)/2
#define lowbit(x) x&-x
#define N 3005
#define log 40
using namespace std;
int n;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[500005];
int check1(int a1,int b1,int c){return ((a[a1]<=c)&&(a[b1]<=c));}
int check2(int a1,int b1,int c){return ((a[a1]>c)&&(a[b1]>c));}
bool check(int x)
{
	for(int i=0;i<n-1;i++)
	{
		if(check2(n+i,n+i+1,x)||check2(n-i,n-i-1,x))
	        return 0;
		if(check1(n+i,n+i+1,x)||check1(n-i,n-i-1,x))
		    return 1;
	}
	return check1(1,1,x);
} 
int main()
{
	//freopen("x.in,"r",stdin);
	//freopen("x.out,"w",stdout);
	scanf("%d",&n);
	int i;
	for(i=1;i<=2*n-1;i++)
	    scanf("%d",&a[i]);
	int l=1,r=2*n-1;
	while(l<r)
	{
		if(check(mid))
		    r=mid;
		else
		    l=mid+1;
	}
	cout<<r;
}