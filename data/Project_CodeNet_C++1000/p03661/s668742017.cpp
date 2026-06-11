#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

#define rp(i,t) for(int i=0;i<(t);i++)
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#define rsp(i,s,t) for(int i=(s);i<(t);i++)
#define rrp(i,t,s) for(int i=(t);i>=(s);i--)
#define rcp(i,s,b,d) for(int i=(s);b;d)
#define mst(a,x) memset(a,x,sizeof(a))
#define INF 0x3f3f3f3f
#define N 200002

#define Dp puts("")
#define Dw printf
#define Ds printf("#")

typedef long long ll;
char ch,last;
ll n,a[N],sf[N],sb[N],ans;

inline void read(ll &x){x=ch=0;do{last=ch;ch=getchar();}while(ch<'0'||'9'<ch);do{x=x*10+ch-'0';ch=getchar();}while('0'<=ch&&ch<='9');if(last=='-')x=-x;}

int main(void)
{
	read(n);
	rep(i,1,n)read(a[i]),sf[i]=sf[i-1]+a[i];
	rrp(i,n,1)sb[i]=sb[i+1]+a[i];
	ans=abs(sf[1]-sb[2]);
	rsp(i,2,n)ans=min(ans,abs(sf[i]-sb[i+1]));
	printf("%lld",ans);
	return 0;
}
