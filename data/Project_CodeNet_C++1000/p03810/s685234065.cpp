#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
int n,a[100001];
class IO{char buffer[10000001];char *h;int len;inline char gchar(){return *h++;}inline bool validdigit(char c){return c>='0' && c<='9';}public:inline void init(){len=fread(buffer,1,10000000,stdin);h=buffer;}inline int nextint(){register int i=0;register char c;do c=gchar();while(!validdigit(c));do{i=i*10+c-48;c=gchar();}while(validdigit(c));return i;}}io;
int gcd(int a,int b){if(a<b)swap(a,b);for(register int t=a%b;t;a=b,b=t,t=a%b);return b;}
bool dfs()
{
	register int cnt=0,last=0,tmp;
	for(register int i=1;i<=n;++i)(a[i]&1)?last=i:++cnt;
	if(cnt&1)return true;
	if(cnt+1<n || a[last]==1)return false;
	tmp=a[last]-1;
	for(register int i=1;i<=n;++i)
		if(i!=last)tmp=gcd(tmp,a[i]);
	for(register int i=1;i<=n;++i)a[i]/=tmp;
	return !dfs();
}

int main()
{
	io.init();n=io.nextint();
	for(register int i=1;i<=n;++i)
		a[i]=io.nextint();
	puts(dfs()?"First":"Second");
}