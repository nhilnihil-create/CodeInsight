#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=2005,mod=1000000007;
int n,k,c[N*N],dp[N][N];
inline void add(int &a,ll b){
	a=(a+b)%mod;
}
inline int ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	n=read(); k=read();
	if(k==1){puts("1"); return 0;}
	c[k-2]=1; for(int i=k-1;i<=n*k;i++)c[i]=(ll)c[i-1]*i%mod*ksm(i-(k-2),mod-2)%mod;
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			add(dp[i+1][j],(ll)dp[i][j]*c[n*k-i*(k-1)-j-1]);
			add(dp[i][j+1],dp[i][j]);
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	ll ans=dp[n][n];
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans<<endl;
}
/*
5*4*3=4*3*2
*/