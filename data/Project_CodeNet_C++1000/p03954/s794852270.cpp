#include<iostream>
#include<cstdio>
using namespace std;
inline char gc()
{
	static const int SIZE=1<<23;
	static char buf[SIZE],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++;
}
//#define getchar gc
template<typename T>
inline T read(T &x)
{
	x=0;
	char ch;
	bool flag=false;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
		if(ch=='-') flag=true;
	while(ch>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(flag) x=-x;
	return x;
}
template<typename T>
inline void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
template<typename T>
inline void writeln(T x)
{
	write(x);
	putchar('\n');
	return;
}
const int N=200005;
int n;
int a[N];
bool isbig(int pos,int k)
{
	return a[pos]>k;
}
bool check(int k)
{
	for(int i=0;i<n-1;i++)
	{
		if(isbig(n+i,k)&&isbig(n+i+1,k)) return false;
		if(isbig(n-i,k)&&isbig(n-i-1,k)) return false;
		if(!isbig(n+i,k)&&!isbig(n+i+1,k)) return true;
		if(!isbig(n-i,k)&&!isbig(n-i-1,k)) return true;
	}
	return !isbig(1,k);
}
int main()
{
	read(n);
	for(int i=1;i<=2*n-1;i++)
		read(a[i]);
	int l=1,r=2*n-1,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	write(ans);
	return 0; 
}