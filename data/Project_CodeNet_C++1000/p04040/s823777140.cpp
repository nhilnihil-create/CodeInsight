//Badwaper gg
#include<bits/stdc++.h>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
#define pb push_back
#define re register ll
#define fr first
#define sd second
#define FOR(i,a,b) for(re i=a;i<=b;i++)
#define REP(i,a,b) for(re i=a;i>=b;i--)
#define lowbit(x) (x&(-x))
#define Z(x) (x>=mod?x-mod:x)
#define N 200010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
const int mod=1e9+7;
int fac[N],inv[N];
int h,w,a,b;
inline int C(int n,int m){return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	h=read(),w=read(),a=read(),b=read();int Maxn=N-10;
	fac[0]=1;FOR(i,1,Maxn)fac[i]=1LL*fac[i-1]*i%mod;
	inv[0]=inv[1]=1;FOR(i,2,Maxn)inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,Maxn)inv[i]=1LL*inv[i]*inv[i-1]%mod;
	int ans=0;
	FOR(i,b,w)
	{
//		cout<<"WTF:"<<i<<" "<<C(h-a+i-1,h-a-1)<<" "<<C(a-1+(w-i-1),a-1)<<endl;
		ans=Z(ans+1LL*C(h-a+i-1,h-a-1)*C(a-1+(w-i-1),a-1)%mod);
	}
	printf("%d\n",ans);
	return 0;
}
