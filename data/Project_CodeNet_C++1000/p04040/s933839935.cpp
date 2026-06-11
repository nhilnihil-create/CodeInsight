#include<bits/stdc++.h>
#define ll long long
#define re register
#define ull unsigned ll
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*t;
}
const int P=1e9+7;
const int N=2e5+5;
int H,W,A,B,Ans,fac[N],inv[N];
int Mod(int x){return x>=P?x-P:x;}
int ksm(int x,int k){
	int res=1;
	while(k){
		if(k&1)res=1ll*res*x%P;
		x=1ll*x*x%P,k>>=1;
	}return res;
}
void Pre(int n){
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%P;
	inv[n]=ksm(fac[n],P-2);for(int i=n;i>=1;i--)inv[i-1]=1ll*inv[i]*i%P;
}
int C(int n,int m){return (n<m||m<0||n<0)?0:1ll*fac[n]*inv[m]%P*inv[n-m]%P;}
int F(int n,int m){return C(n+m-2,n-1);}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	H=read(),W=read(),A=read(),B=read(),Pre(2e5);
	for(int i=B+1;i<=W;i++)Ans=Mod(Ans+1ll*F(H-A,i)*F(A,W-i+1)%P);
	printf("%d",Ans);
	return 0;
}
