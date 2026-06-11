#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=300010,M=1000010,P=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=0xcfcfcfcf;
const double eps=1e-9,pi=asin(1)*2;
inline ll read();
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
inline int ADD(int a,int b) { return a+b>=P?a+b-P:a+b; }
inline int MINUS(int a,int b) { return a-b<0?a-b+P:a-b; }
#define plus(a,b) a=ADD(a,b)
#define minus(a,b) a=MINUS(a,b)
#define mul(a,b) a=(1ll*a*(b))%P
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp(x,y) make_pair(x,y)

int n,m;
int l[N],r[N];
int c[N];

#ifdef FILE
const int READ_SIZE=1<<20;
char buf[READ_SIZE],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,READ_SIZE,stdin),p1==p2)?EOF:*p1++
#endif
inline ll read()
{
	ll s=0;
	bool flag=false;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=true;
	for(;'0'<=ch&&ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+(ch^'0');
	if(flag) return -s;
	return s;
}

int main()
{
#ifdef FILE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
#endif
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int L=read()-1,R=read();
		for(int l=1,r=0;l<=L;l=r+1)
		{
			r=min(L/(L/l),R/(R/l));
			if(L/l<R/l) c[l]++,c[r+1]--;
		}
		c[L+1]++,c[R+1]--;
	}
	for(int i=1;i<=m;i++) c[i]+=c[i-1];
	for(int i=1;i<=m;i++) printf("%d\n",c[i]);
	return 0;
}