#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
using namespace std;
const int N=101;
int n,m,flg,a[N],b[N],cnt;
inline int read(){
	char ch=getchar(); int x=0, f=1;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;}
inline void swp(int &a,int &b){int t=a;a=b;b=t;}
int main()
{
	//freopen("Arrays and Palindrome.in","r",stdin);
	n=read(); m=read();
	for(RG int i=1;i<=m;i++)
	{
		a[i]=read();
		if(a[i]%2) flg++;
	}
	if(m==1)
	{
		if(n==1) printf("1\n1\n1\n");
		else printf("%d\n2\n%d 1\n",n,n-1);
		return 0;
	}
	if(flg>2) printf("Impossible\n");
	else
	{
		for(RG int i=2;i<=m;i++) if(a[i]%2) a[1]%2 ? swp(a[m],a[i]) : swp(a[1],a[i]);
		b[++cnt]=a[1]+1;
		for(RG int i=2;i<m;i++) b[++cnt]=a[i];
		if(a[m]>1) b[++cnt]=a[m]-1;
		for(RG int i=1;i<=m;i++) printf("%d ",a[i]); printf("\n");
		printf("%d\n",cnt);
		for(RG int i=1;i<=cnt;i++) printf("%d ",b[i]); printf("\n");
	}
	return 0;
}