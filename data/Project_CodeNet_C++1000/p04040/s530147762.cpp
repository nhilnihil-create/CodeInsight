#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;

inline int read(){
	int sum=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return f*sum;
}

const int N=200055;
const int Mod=1000000007;
int n,m,A,B,ans,jc[N]={1};

inline int fpow(int a,int b){
	int ret=1;
	for(;b;b>>=1,a=a*a%Mod) if(b&1) ret=ret*a%Mod;
	return ret;
}

inline int inv(int x){
	return fpow(x,Mod-2);
}

inline int C(int n,int m){
	return jc[n]*inv(jc[m])%Mod*inv(jc[n-m])%Mod;
}

inline int get(int x1,int y1,int x2,int y2){
	int x=x2-x1+1,y=y2-y1+1;
	return C(x+y-2,y-1);
}

signed main(){
	n=read();m=read();A=read();B=read();
	for(int i=1;i<N;i++) jc[i]=jc[i-1]*i%Mod;
	int x=n-A,y=B+1;
	while(x&&y<=m){
		ans=(ans+get(1,1,x,y)*get(x,y,n,m)%Mod)%Mod;
		x--;y++;
	}
	printf("%lld\n",ans);
	return 0;
}
