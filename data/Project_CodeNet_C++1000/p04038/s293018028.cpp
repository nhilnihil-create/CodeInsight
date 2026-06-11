#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc()) if(ch=='-') positive=0;
	for(;isdigit(ch);ch=gc()) x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(ll x){
	if(x<0){
		x=-x;putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writep(ll x){write(x);putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=2005,mo=1e9+7,M=4e6+5;
int fac[M],inv[M],f[N][N];
int C(int n,int m){
	return (ll)fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int ksm(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mo){
		if(p&1) res=(ll)res*x%mo;
	}
	return res;
}
int main(){
	int n=read(),m=read(),k=n*m;
	For(i,fac[0]=1,k) fac[i]=(ll)fac[i-1]*i%mo;
	inv[k]=ksm(fac[k],mo-2);
	Rep(i,k-1,0) inv[i]=(ll)inv[i+1]*(i+1)%mo;
	f[0][0]=1;
	For(i,1,n) For(j,0,i){
		f[i][j]=f[i-1][j];
		if(j) f[i][j]=(f[i][j]+(ll)C(n-i+(n-j+1)*(m-1)-1,m-2)*f[i][j-1]%mo*(n-j+1))%mo;
	}
	if(m==1) f[n][n]=1;
	cout<<f[n][n];
}