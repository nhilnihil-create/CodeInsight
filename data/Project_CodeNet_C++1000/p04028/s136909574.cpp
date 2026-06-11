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
const int N=5e3+5;
const int mod=1e9+7;
int n,m,f[N][N];
char s[N];
int ksm(int x,int y){int re=1;while(y){if(y&1)re=1ll*re*x%mod;x=1ll*x*x%mod;y>>=1;}return re;}
signed main(){
	//freopen("a","r",stdin);
	n=read();scanf("%s",s+1);m=strlen(s+1);
	f[0][0]=1;
	rep(i,0,n-1)rep(j,0,i){
		f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*2%mod)%mod;
		f[i+1][max(j-1,0)]=(f[i+1][max(j-1,0)]+f[i][j])%mod;
	}return cout<<1ll*f[n][m]*ksm(ksm(2,m),mod-2)%mod,signed();
}