#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N=2004,P=1e9+7;

int n,k,fac[N*N],inv[N*N],ifac[N*N],f[N][N];

int C(int n,int m)
{
	if(n<m||n<0||m<0)
		return 0;
	return (ll)fac[n]*ifac[m]%P*ifac[n-m]%P;
}

int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)
		return puts("1"),0;
	fac[0]=fac[1]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2; i<=n*k; i++)
	{
		fac[i]=(ll)fac[i-1]*i%P;
		inv[i]=(ll)inv[P%i]*(P-P/i)%P;
		ifac[i]=(ll)ifac[i-1]*inv[i]%P;
	}
	// f[i][j] 当前安排了i个白球 有j个颜色安排上了
	// 限制是 i>=j
	// 带标号dp 
	// 钦定当前加入的球最靠前的一个最靠前 
	for(int i=1; i<=n; i++)
	{
		f[i][0]=1;
		for(int j=1; j<=i; j++)
		{
			f[i][j]=f[i-1][j];
			f[i][j]=(f[i][j]+(ll)f[i][j-1]*C(n*k-i-(j-1)*(k-1)-1,k-2)%P*(n-j+1))%P;
		}
	}
	printf("%d",f[n][n]);
	return 0;
}
