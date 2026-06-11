#include<iostream>
#include<cstdio>
#include<cstring>

template<typename T>inline void read(T &x)
{
	char c=x=0;
	for(c=getchar();!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
}

namespace fuck
{
	typedef long long ll;
	const int N=100100,M=N*2;
	int begin[N],next[M],to[M];
	ll A[N],f[N];
	int n,e;
	void add(int x,int y,bool k=1)
	{
		to[++e]=y;
		next[e]=begin[x];
		begin[x]=e;
		if(k)add(y,x,0);
	}
	bool dfs(int p=1,int h=0)
	{
		ll sum=0,max=0;
		int cnt_son=0;

		for(int i=begin[p],q;i;i=next[i])
			if((q=to[i])!=h)
			{
				cnt_son++,dfs(q,p);

				sum+=f[q],max=std::max(max,f[q]);
			}
		if(!cnt_son)
		{
			f[p]=A[p];
			if(p==1)return !f[p];
			return 1;
		}
		if(sum<A[p] || sum>A[p]*2)return 0;

		if(max*2<=sum)f[p]=sum-2*(sum-A[p]);
		else if(sum-max<sum-A[p])return 0;
		else f[p]=sum-2*(sum-A[p]);

		if(p==1)
		{
			if(cnt_son>1 && f[p]!=0)return 0;
			if(cnt_son==1 && f[p]!=A[p])return 0;
		}

		return 1;
	}
	void initialize()
	{
		read(n);
		for(int i=1;i<=n;i++)read(A[i]);
		for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	}
	void solve()
	{
		initialize();
		printf("%s\n",dfs()?"YES":"NO");
		
//		for(int i=1;i<=n;i++)
//			printf("%lld ",f[i]);
//		printf("\n");
	}
}
int main()
{
	fuck::solve();
	return 0;
}
