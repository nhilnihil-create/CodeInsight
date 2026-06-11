//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int I,O,T,J,L,S,Z;
int ans;
main()
{
	re(I),re(O),re(T),re(J),re(L),re(S),re(Z);
	if(J && L && I && (J&1)+(L&1)+(I&1)>=2)ans+=3,--J,--L,--I;
	ans+=O;
	ans+=J/2*2;J%=2;
	ans+=L/2*2;L%=2;
	ans+=I/2*2;I%=2;
	printf("%lld\n",ans);
}
