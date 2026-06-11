#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define int ll
#define pb push_back


using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/

const int N=1e5+5;	
int n;
struct node{int v,num;}	p[N];
int ans[N];
inline bool cmp(node x,node y){return x.v!=y.v?x.v>y.v:x.num<y.num;}
signed main()
{
	n=read();
	For(i,1,n)	p[i].v=read(),p[i].num=i;
	sort(p+1,p+n+1,cmp);
	int now=1,to=p[1].num;
//	For(i,1,n)	cout<<p[i].v<<' '<<p[i].num<<endl;
	For(i,2,n+1)
	{
		ans[to]+=(p[i-1].v-p[i].v)*now,now++;
		to=min(to,p[i].num);
	}
//	ans[to]=(p[n].v-p[n+1].v)*now,now++;
	For(i,1,n)	writeln(ans[i]);
}