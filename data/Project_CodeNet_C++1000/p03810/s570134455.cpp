#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x; 
}
#define MN 100000
int n,a[MN+5];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
bool check()
{
	int s=n&1,i;
	for(i=1;i<=n;++i)s^=a[i]&1;
	if(s)return true;
	for(i=1;i<=n;++i)if(a[i]>1&&(a[i]&1))break;
	if(i>n)return false;
	for(--a[i],i=1,s=0;i<=n;++i)s=gcd(s,a[i]);
	for(i=1;i<=n;++i)a[i]/=s;
	return !check();
}
int main()
{
	n=read();
	if(n==1)return 0*puts("Second");
	for(int i=1;i<=n;++i)a[i]=read();
	puts(check()?"First":"Second");
}