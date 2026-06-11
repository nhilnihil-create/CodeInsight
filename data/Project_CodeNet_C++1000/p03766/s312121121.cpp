#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 2000200
#define mod 1000000007
using namespace std;
namespace IO{
	int Top=0;char SS[20];
	void write(int x){
		if(!x){putchar('0');return;} if(x<0) x=-x,putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) putchar(SS[Top]+'0'),--Top;
	}
	int read(){
		int nm=0; char cw=getchar(); for(;!isdigit(cw);cw=getchar());
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0'); return nm;
	}
}using namespace IO;
int add(int x,int y){return (x+y>=mod)?x+y-mod:x+y;} 
int mul(int x,int y){return (LL)x*(LL)y%mod;}
int mus(int x,int y){return (x-y<0)?x-y+mod:x-y;}
void upd(int &x,int y){x=add(x,y);}
int qpow(int x,int sq){
	int res=1;
	for(;sq;sq>>=1,x=mul(x,x)) if(sq&1) res=mul(res,x);
	return res;
}
int n,m,G[M],F[M],S[M],fac[M],ifac[M],ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),F[0]=S[0]=1;
	for(int i=1;i<=n;i++) F[i]=i>2?S[i-3]:0,upd(F[i],F[i-1]),S[i]=add(S[i-1],F[i]);
	for(int i=0;i<n;i++) upd(ans,mul(F[i],i+(i<n-1)));
	for(int i=0;i<n-1;i++) upd(ans,mul(F[i],mul(n-1,n-1)));
	upd(ans,F[n]),write(ans),putchar('\n');return 0;
}