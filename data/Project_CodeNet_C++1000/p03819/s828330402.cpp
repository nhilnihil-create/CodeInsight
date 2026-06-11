//Snuke Line
#include <cstdio>
#include <algorithm>
inline char gc()
{
	static char now[1<<16],*S,*T;
	if(S==T) {T=(S=now)+fread(now,1,1<<16,stdin); if(S==T) return EOF;}
	return *S++;
}
inline int read()
{
	int x=0; char ch=gc();
	while(ch<'0'||'9'<ch) ch=gc();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=gc();
	return x;
}
int const N=3e5+10;
int const M=1e5+10;
int n,m;
struct range{int fr,to;} rg[N];
bool cmpRg(range x,range y) {return x.fr<y.fr;}
int sgCnt,rt[M];
struct seg{int cnt; int L,R;} sg[N*20];
void update(int s) {sg[s].cnt=sg[sg[s].L].cnt+sg[sg[s].R].cnt;}
void ins(int &s,int fr,int to,int x)
{
	sg[++sgCnt]=sg[s]; s=sgCnt;
	if(fr==to) {sg[s].cnt++; return;} 
	int mid=fr+to>>1;
	if(x<=mid) ins(sg[s].L,fr,mid,x);
	else ins(sg[s].R,mid+1,to,x);
	update(s);
}
int query(int s1,int s2,int fr,int to,int fr0,int to0)
{
	if(fr0<=fr&&to<=to0) return sg[s2].cnt-sg[s1].cnt;
	int mid=fr+to>>1; int res=0;
	if(fr0<=mid) res+=query(sg[s1].L,sg[s2].L,fr,mid,fr0,to0);
	if(mid<to0) res+=query(sg[s1].R,sg[s2].R,mid+1,to,fr0,to0);
	return res;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) rg[i].fr=read(),rg[i].to=read();
	std::sort(rg+1,rg+n+1,cmpRg);
	rt[0]=0; int p=1;
	for(int i=1;i<=m;i++)
	{
		rt[i]=rt[i-1];
		while(rg[p].fr==i) ins(rt[i],1,m,rg[p].to),++p;
	}
	printf("%d\n",n);
	for(int d=2;d<=m;d++)
	{
		int ans=n,i;
		for(i=d;i<=m;i+=d) ans-=query(rt[i-d],rt[i-1],1,m,i-d+1,i-1);
		if(i-d+1<=m) ans-=query(rt[i-d],rt[m],1,m,i-d+1,m);
		printf("%d\n",ans);
	}
	return 0;
}