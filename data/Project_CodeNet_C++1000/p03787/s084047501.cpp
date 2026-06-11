#include<iostream>
#include<cstdio>
#include<cstring>

template<typename T>inline void read(T &x)
{
	char c=x=0;
	for(c=getchar();!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
}

namespace Good_problem
{
	typedef long long ll;
	const int N=101000,M=N*4;
	int begin[N],next[M],to[M];
	int n,m,e;
	ll A,B,C;
	void add(int x,int y,bool k=1)
	{
		to[++e]=y;
		next[e]=begin[x];
		begin[x]=e;
		if(k)add(y,x,0);
	}
	int col[N];
	bool dfs(int p,int x)
	{
		if(col[p])return col[p]==x;
		col[p]=x;

		bool ret=1;
		for(int i=begin[p],q;i;i=next[i])
			if(!dfs(q=to[i],3-x))ret=0;
		return ret;
	}
	void initialize()
	{
		read(n),read(m);
		for(int i=1,u,v;i<=m;i++)
			read(u),read(v),add(u,v);
	}
	void solve()
	{
		initialize();
		A=B=C=0;
		for(int i=1;i<=n;i++)
			if(!col[i])
			{
				if(!dfs(i,1))B++;
				else if(begin[i])A++;
				else C++;
			}
		printf("%lld\n",2*A*A+2*A*B+B*B+2*n*C-C*C);
	}
}

int main()
{
	Good_problem::solve();
	return 0;
}
