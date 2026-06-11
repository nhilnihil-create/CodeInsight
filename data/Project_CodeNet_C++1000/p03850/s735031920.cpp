#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define Rep(i,x) for(int i=head[x];i+1;i=nxt[i])
#define rep2(i,a,b) for(int i=(a);i<(b);i++)
#define ff first
#define ss second
using namespace std;
const int N=100005;
const long long inf=1e15;
typedef long long ll;
//------------------------------------------head---------------------------------------------------//
ll a[N];
int op[N];
ll f[N][2];
inline void Updmax(ll &x,ll y){x=(x<=y)?y:x;}
int main()
{
	int m=0;//ll tot=0;
	ll tot=0,ans=0,pos=0,ma=0;
	int n;scanf("%d",&n);scanf("%d",&a[1]);rep(i,2,n)
	{
		char s[4];int x;scanf("%s%d",s+1,&x);
		op[i-1]=(s[1]=='+');a[i]=x;
	}
	ans=a[1];
	rep(i,1,n-1){if(op[i])ans+=a[i+1];else ans-=a[i+1];}
	//printf("%lld\n",ans);
	per(i,n-1,1)
	{
		if(op[i]==1) tot+=2ll*a[i+1];
		else
		{
			ma=max(ma,ans+pos-tot);
			pos+=2ll*a[i+1];
			tot=0;
		}
	}
	printf("%lld\n",max(ans,ma));
	return 0;
	// 0 min
	// 1 max
	//n=m;//f[1][0][1]=f[1][0][0]=a[1];
	/*rep(i,0,n)rep(j,0,1)f[i][j]=-inf;f[1][0]=a[1];
	//rep(i,1,n)printf("%d ",a[i]);
	op[0]=-1;
	op[n]=1;a[++n]=0;
	rep(i,1,n-1)
	{
		if(op[i]==1)
		{
			//printf("Case owo:%d\n",i);
			Updmax(f[i+1][0],f[i][0]-a[i+1]);
			Updmax(f[i+1][1],f[i][0]-a[i+1]);
			Updmax(f[i+1][1],f[i][1]+a[i+1]);
			Updmax(f[i+1][0],f[i][1]+a[i+1]);
			
		}
		else
		{
			Updmax(f[i+2][0],f[i][0]+(a[i+1]-a[i+2]));
			Updmax(f[i+2][1],f[i][0]+(a[i+1]-a[i+2]));
			Updmax(f[i+2][1],f[i][1]-(a[i+1]-a[i+2]));
			Updmax(f[i+2][0],f[i][1]-(a[i+1]-a[i+2]));
		}
	}*/
	//printf("%lld\n",max(f[n][0],f[n][1]));
	return 0;
}