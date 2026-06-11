#include<bits/stdc++.h>
#define int long long
using namespace std;
struct SPLAY
{
	static const int N=200005;
	int ch[N][2],fa[N],size[N],cnt[N],val[N],sz,root;
	int newnode(int v,int f)
	{
		sz++;
		ch[sz][0]=ch[sz][1]=0;
		fa[sz]=f;
		size[sz]=cnt[sz]=1;
		val[sz]=v;
		return sz;
	}
	void pushup(int k)
	{
		size[k]=cnt[k]+size[ch[k][0]]+size[ch[k][1]];
	}
	void rotate(int x)
	{
		int f=fa[x],d=ch[f][0]==x?1:0;
		fa[x]=fa[f];
		fa[f]=x,fa[ch[x][d]]=f;
		ch[f][d^1]=ch[x][d],ch[x][d]=f;
		if(fa[x]) ch[fa[x]][ch[fa[x]][0]==f?0:1]=x;
		pushup(f),pushup(x);
	}
	void splay(int x,int k=0)
	{
		while(fa[x]!=k)
		{
			int f=fa[x],g=fa[f];
			if(g!=k)
				rotate((ch[f][0]==x)==(ch[g][0]==f)?f:x);
			rotate(x);
		}
		if(k==0)
			root=x;
	}
	void insert(int v)
	{
		int now=root,f=0;
		while(now&&val[now]!=v)
			f=now,now=ch[now][v>val[now]];
		if(now)
			cnt[now]++;
		else
		{
			now=newnode(v,f);
			if(f)
				ch[f][v>val[f]]=now;
		}
		splay(now);
	}
	int rank(int v)
	{
		int now=root,ans=1;
		while(now)
		{
			if(val[now]>v)
				now=ch[now][0];
			else
			{
				ans+=size[ch[now][0]];
				if(val[now]==v)
				{
					splay(now);
					return ans;
				}
				ans+=cnt[now];
				now=ch[now][1];
			}
		}
		return ans;
	}
	int kth(int k)
	{
		int now=root;
		while(now)
		{
			if(k<=size[ch[now][0]])
				now=ch[now][0];
			else
			{
				k-=size[ch[now][0]]+cnt[now];
				if(k<=0)
					return val[now];
				now=ch[now][1]; 
			}
		}
	}
	int pre(int v,int fl=0)
	{
		int ans=-1e18,id=0,now=root;
		while(now)
		{
			if(val[now]>=v)
				now=ch[now][0];
			else
			{
				if(val[now]>ans)
					ans=val[now],id=now;
				now=ch[now][1];
			}
		}
		return fl?id:ans;
	}
	int suc(int v,int fl=0)
	{
		int ans=1e18,id=0,now=root;
		while(now)
		{
			if(val[now]<=v)
				now=ch[now][1];
			else
			{
				if(val[now]<ans)
					ans=val[now],id=now;
				now=ch[now][0];
			}
		}
		return fl?id:ans;
	}
	void remove(int v)
	{
		rank(v);
		if(cnt[root]>1)
			cnt[root]--;
		else if(!ch[root][0]&&!ch[root][1])
			root=0;
		else if(!ch[root][0]||!ch[root][1])
			root=ch[root][0]?ch[root][0]:ch[root][1],fa[root]=0;
		else
		{
			int p=pre(v,1),o=root;
			splay(p);
			fa[ch[o][1]]=p;
			ch[p][1]=ch[o][1];
			pushup(p);
		}
	}
}s;
const int N=200005;
int a[N],sum[N],n,k,ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	s.insert(0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]-=k;
		sum[i]=sum[i-1]+a[i];
		ans+=s.rank(s.suc(sum[i]))-1;
		s.insert(sum[i]);
	}
	cout<<ans<<endl;
	return 0;
}