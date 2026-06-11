#include<bits/stdc++.h>
using namespace std;
#define pc(x) putchar(x)
namespace ib {char b[100];}
inline void pi(int x){
	if(x==0) {pc(48); return;}
	if(x<0) {pc('-'); x=-x;}
	char *s=ib::b;
	while(x) *(++s)=x%10,x/=10;
	while(s!=ib::b) pc((*(s--))+48);
}
inline void ri(int &x){
	x=0; static char c; bool t(0);
	while(c=getchar(),c<'0'||c>'9') if(c=='-') t=1; else t=0;
	do x=(x<<1)+(x<<3)+c-'0'; while(c=getchar(),c>='0'&&c<='9');
	if(t) x=-x;
}
const int M=1e9+7,N=2024;
int JC[N*N],RJC[N*N],f[N][N];
inline int ksm(int n,int c){
	int jc=1;
	while(c){
		if(c&1) jc=(long long)jc*n%M;
		n=(long long)n*n%M; c>>=1; 
	}
	return jc;
}
inline int C(int n,int m){
	if(m==0||m==n) return 1;
	if(m>n) return 0;
	return (long long)JC[n]*RJC[m]%M*RJC[n-m]%M;
}
int main(){
	int i,j,n,k; ri(n); ri(k);
	if(k==1){pc('1'); return 0;}
	JC[0]=1; for(i=1;i<=2000*2000;++i) JC[i]=(long long)JC[i-1]*i%M;
	RJC[2000*2000]=ksm(JC[2000*2000],M-2);
	for(i=2000*2000-1;i>=0;--i) RJC[i]=(long long)RJC[i+1]*(i+1)%M;
	f[0][0]=1;
	for(i=0;i<=n;++i)
	for(j=0;j<=n;++j){
		f[i][j+1]=(f[i][j+1]+f[i][j])%M;
		if(j) f[i+1][j-1]=(f[i+1][j-1]+(long long)(n-i)*C(n*k-i*k-j-1,k-2)%M*f[i][j])%M;
	}
	cout<<f[n][0];
	return 0;
}