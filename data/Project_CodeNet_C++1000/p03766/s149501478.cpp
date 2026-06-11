#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1001000,P=1000000007;
int i,j,k,n,m,sum;
int f[N];
int main() {
	scanf("%d",&n);
	f[1]=n;f[2]=(ll) n*n%P;sum=((ll) n*n+n)%P;
	for (i=3;i<=n;i++) {
		f[i]=((ll) (n-1)*(n-1)+(n-i+2)+sum+P-f[i-2])%P;
		sum=(sum+f[i])%P;
	}
	printf("%d\n",f[n]);
}