#include<bits/stdc++.h>
#define ll long long
using namespace std;
void qmax(int &x,int y) {if (x<y) x=y;}
void qmin(int &x,int y) {if (x>y) x=y;}
inline int read()
{
	char s;
	int k=0,base=1;
	while((s=getchar())!='-'&&s!=EOF&&!(isdigit(s)));
	if(s==EOF)exit(0);
	if(s=='-')base=-1,s=getchar();
	while(isdigit(s)){k=k*10+(s^'0');s=getchar();}
	return k*base;
}
inline void write(int x)
{
	static char cnt,num[15];cnt=0;
	if (!x)
	{
		putchar('0');
		return;
	}
	for (;x;x/=10) num[++cnt]=x%10;
	for (;cnt;putchar(num[cnt--]+48));
}
const int maxn=100000;
int n,id,X,Y;
int to[maxn<<1],ne[maxn<<1],po[maxn];
int sg[maxn];
void add(int x,int y)
{
	id++;
	to[id]=y;ne[id]=po[x];po[x]=id;
}
void dfs(int x,int fa)
{
	for (int i=po[x];i;i=ne[i])
	{
		if (to[i]!=fa) 
		{
			dfs(to[i],x);
			sg[x]^=(sg[to[i]]+1);
		}
	}
}
int main()
{
#ifdef ylx
	freopen("agc017d.in","r",stdin);
	freopen("agc017d.out","w",stdout);
#endif
	n=read();
	for (int i=1;i<n;i++)
	{
		X=read();Y=read();
		add(X,Y);
		add(Y,X);
	}
	dfs(1,-1);
	if (sg[1])
	{
		printf("Alice");
	} else printf("Bob");
	return 0;
}
