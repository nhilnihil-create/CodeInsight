#include<bits/stdc++.h>
#define MAXN 110000
using namespace std;
template <typename T> inline void read(T &s)
{
	s = 0;char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) s = ((s+(s<<2))<<1)+ch-'0',ch = getchar();
}
int n,m,cnt,root,Ans[MAXN],pre[MAXN];
struct Bit
{
	#define lowbit(x) (x)&(-x)
	int tmp[MAXN];
	inline void Insert(int x,int val){for(;x<=m+1&&x;x+=lowbit(x)) tmp[x] += val;}
	inline int Query(int x){int Sum = 0;for(;x;x-=lowbit(x)) Sum += tmp[x];return Sum;}
}Bit;
struct LINE{int l,r;}a[MAXN*3];
vector <int> v[110000],nxt[110000];
struct SPLAY{int father,child[2],val,ans,id,siz,lazy;}t[MAXN];
inline void Connect(int u,int f,int side){t[u].father = f,t[f].child[side] = u; }
inline void Update(int u){t[u].siz = t[t[u].child[0]].siz + t[t[u].child[1]].siz + 1;}
inline void Pushdown(int u)
{
	if(!t[u].lazy||!u) return;
	if(t[u].child[0]) t[t[u].child[0]].ans += t[u].lazy,t[t[u].child[0]].lazy += t[u].lazy;
	if(t[u].child[1]) t[t[u].child[1]].ans += t[u].lazy,t[t[u].child[1]].lazy += t[u].lazy;
	t[u].lazy = 0;
}
inline bool Identify(int u){return t[t[u].father].child[0] == u ? 0 : 1;}
inline void Rotate(int u)
{
	int f = t[u].father,gf = t[f].father,fson = Identify(u),gfson = Identify(f),B = t[u].child[fson^1];
	Connect(u,gf,gfson),Connect(f,u,1 ^ fson),Connect(B,f,fson),Update(f),Update(u);
}
inline void Splay(int at,int to)
{
	Pushdown(at);
	static int up,Stk[MAXN],Sl;
	up = at,Sl = 0;
	while(up) Stk[++Sl] = up,up = t[up].father;
	while(Sl) Pushdown(Stk[Sl--]);
	while(t[at].father != to)
	{
		up = t[at].father;
		if(t[up].father == to) Rotate(at);
		else if(Identify(up) == Identify(at)) Rotate(up),Rotate(at);
		else Rotate(at),Rotate(at);
	}
	if(!to) root = at;
}
inline int FindKth(int siz)
{	
	int at = root;
	while(true)
	{
		Pushdown(at);
		int tmp = t[at].siz - t[t[at].child[1]].siz;
		if(tmp < siz) siz -= tmp,at = t[at].child[1];
		else
		{
			if(siz <= t[t[at].child[0]].siz) at = t[at].child[0];
			else break;
		}
	}
	return Splay(at,0),at;
}
inline void Insert(int u,int id)
{
	int at = root,f = 0;
	if(t[at].lazy) Pushdown(at);
	while(at)
	{
		f = at,at = t[at].child[u >= t[at].val];
		if(t[at].lazy) Pushdown(at);
	}
	at = id;
	if(f) t[f].child[u>t[at].val] = at;
	t[at].child[0] = t[at].child[1] = 0,t[at].father = f,t[at].val = u,t[at].lazy = 0,t[at].siz = 1;
	Splay(at,0);
}
void Build(int l,int r,int f,bool flag)
{
	if(l > r) return;
	int mid = l + r >> 1;
	t[mid].ans = t[mid].lazy = t[mid].val = 0,t[mid].father = f,t[f].child[flag] = mid,t[mid].id = mid-1,t[mid].siz = 1;
	if(mid == m+2) t[mid].val = 2147483647;
	if(mid == 1) t[mid].val = -2147;
	Build(l,mid-1,mid,0),Build(mid+1,r,mid,1),Update(mid);
}
inline void Change(int id,int val)
{
	Splay(id,0),Bit.Insert(pre[id]+1,-1),pre[id] = val,Bit.Insert(pre[id]+1,1);
	if(!t[id].child[0]) root = t[id].child[1],t[root].father = 0;
	else
	{
		int chl = t[id].child[0];
		while(t[chl].child[1]) chl = t[chl].child[1];		
		Splay(chl,id),root = chl,Connect(t[id].child[1],chl,1),Connect(chl,0,1),Update(chl);
	}
	t[id].val = val,t[id].child[0] = t[id].child[1] = t[id].father = 0,t[id].siz = 1;
	Insert(val,id);
}
inline void D(int u)
{
	Pushdown(u);
	if(t[u].child[0]) D(t[u].child[0]);
	Ans[t[u].id] = t[u].ans;
	if(t[u].child[1]) D(t[u].child[1]);
}
inline void Calc(int L)
{
	int ll = FindKth(Bit.Query(L));
	t[t[ll].child[1]].lazy += 1,t[t[ll].child[1]].ans += 1;
}
int main()
{
	read(n),read(m),Bit.Insert(1,m+1);
	for(int i = 1;i<=n;++i) read(a[i].l),read(a[i].r),v[a[i].r].push_back(i);
	Build(1,m+2,0,0),root = (3+m) >> 1;
	for(int i = 1;i<=m;++i) for(int j = i;j<=m;j+=i) nxt[j].push_back(i);
	for(int i = 1;i<=m;++i)
	{
		for(auto x:nxt[i]) Change(x+1,i);
		for(auto x:v[i]) Calc(a[x].l);
	}
	D(root);
	for(int i = 1;i<=m;++i) printf("%d\n",Ans[i]);
	return 0;
}