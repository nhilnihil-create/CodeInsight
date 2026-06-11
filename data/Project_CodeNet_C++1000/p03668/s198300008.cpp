#include <bits/stdc++.h>
using namespace std;
inline int read()
{int x=0;
char c=getchar();
while (c<'0'||c>'9') c=getchar();
while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
return x;
}
int sg[100005],head[100005],nxt[200005],v[200005],n,tot=0;
inline void add(int a,int b)
{tot++;nxt[tot]=head[a];head[a]=tot;v[tot]=b;}
void dfs(int pos,int f)
{for (int i=head[pos];i;i=nxt[i])
{if (v[i]==f) continue;
dfs(v[i],pos);
sg[pos]^=(sg[v[i]]+1);
}
}
int main (){
	int i,a,b;
	n=read();
	for (i=1;i<n;i++)
	{a=read();b=read();
	add(a,b);add(b,a);
	}
	dfs(1,0);
	puts(sg[1]?"Alice":"Bob");
	return 0;
}