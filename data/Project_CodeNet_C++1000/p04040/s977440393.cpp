#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define poly vector<ll>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
inline ll read(){
	ll x=0;char ch=getchar();bool d=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') d=0;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return d?x:-x;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writep(ll x){write(x);putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=2e5+5,mo=1e9+7;
int fac[N],inv[N];
int C(int n,int m){
	if(n<m) return 0;
	return (ll)fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int S(int sx,int sy,int tx,int ty){
	return C(tx+ty-sx-sy,tx-sx);
}
int ksm(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mo){
		if(p&1) res=(ll)res*x%mo;
	}
	return res;
}
void init(int n){
	For(i,fac[0]=1,n) fac[i]=(ll)fac[i-1]*i%mo;
	inv[n]=ksm(fac[n],mo-2);
	Rep(i,n-1,0) inv[i]=(ll)inv[i+1]*(i+1)%mo;
}
int main(){
	int n=read(),m=read(),h=read(),w=read();
	if(w==m) return putchar('0'),0;
	init(N-1);int ans=S(1,1,n,m);
	For(i,n-h+1,n){
		int t=(ll)S(1,1,i,w)*S(i,w+1,n,m)%mo;
		ans=(ans-t+mo)%mo;
	}
	cout<<ans;
}