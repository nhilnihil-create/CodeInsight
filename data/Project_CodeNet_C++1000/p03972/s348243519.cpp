#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define RG register
#define LL long long
using namespace std;
const int N=2e5+10;
struct node{ LL scr; int flg; }pt[N];
int n,m,tot;
LL ans;
template<typename I> inline void read(I &ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}
	ot=x*f;}
template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}
inline bool cmp(node a,node b){return a.scr<b.scr;}
int main()
{
	//freopen("Gr-idian MST.in","r",stdin);
	read(n,m); tot=n+m;
	for(RG int i=1;i<=n;i++) read(pt[i].scr);
	for(RG int i=1;i<=m;i++) read(pt[i+n].scr), pt[i+n].flg=1;
	sort(pt+1,pt+1+tot,cmp);
	n++; m++;
	for(RG int i=1;i<=tot && n && m;i++)
	{
		ans+=pt[i].scr*(pt[i].flg ? n : m);
		if(pt[i].flg) m--; else n--;
	}
	printf("%lld\n",ans);
	return 0;
}