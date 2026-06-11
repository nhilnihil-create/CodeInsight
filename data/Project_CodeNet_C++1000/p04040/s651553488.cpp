#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<int,int>
#define vint vector<int>
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define red(i,a,b) for(int i=(a);i>=(b);i--)
#define db double
#define ld long db
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
int read(){
	int g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
const int N=2e5+5;
const int maxn=2e5;
const int mod=1e9+7;
int fac[N],inv[N],n,m,a,b,ans;
int C(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
signed main(){
	//freopen("a","r",stdin);
	n=read(),m=read(),a=read(),b=read();
	fac[0]=1;rep(i,1,maxn)fac[i]=1ll*fac[i-1]*i%mod;
	inv[1]=1;rep(i,2,maxn)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	inv[0]=1;rep(i,1,maxn)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	a=n-a-1;
	rep(i,0,a)ans=(ans+1ll*C(i+b-1,b-1)*C(n+m-2-b-i,n-1-i)%mod)%mod;
	return cout<<ans,signed();
}