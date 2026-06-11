#include<cstdio>
using namespace std;
typedef long long ll;
const int N=2020,M=4004000,P=1000000007;
int i,j,k,n,m,ans;
int f[N][N];
int Jc[M],Jc_[M];
int ksm(int x,int y) {
	int z=1;
	for (;y;y>>=1,x=(ll) x*x%P) if (y&1) z=(ll) z*x%P;
	return z;
}
void pre(int n) {
	int i;
	Jc[0]=Jc_[0]=1;
	for (i=1;i<=n;i++) Jc[i]=(ll) Jc[i-1]*i%P;
	Jc_[n]=ksm(Jc[n],P-2);
	for (i=n-1;i;i--) Jc_[i]=(ll) Jc_[i+1]*(i+1)%P;
}
int C(int n,int m) {
	if (n<m) return 0;
	return (ll) Jc[n]*Jc_[m]%P*Jc_[n-m]%P;
}
int main() {
	scanf("%d%d",&n,&m);
	if (m==1) return puts("1"),0;
	pre(n*m);
	f[0][0]=1;
	for (i=0;i<=n;i++)
		for (j=0;j<=i;j++) {
			if (j<i) f[i][j+1]=(f[i][j+1]+f[i][j])%P;
			f[i+1][j]=((ll) f[i][j]*C((i+1)*(m-1)+j-1,m-2)+f[i+1][j])%P;
		}
	ans=(ll) f[n][n]*Jc[n]%P;
	printf("%d\n",ans);
}