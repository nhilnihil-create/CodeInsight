#include <cstdio>

int f[2001][2001],n,k,invmul[4000001],_mul[4000001];
const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int C(const int &n,const int &m){return mul(mul(_mul[n],invmul[m]),invmul[n-m]);}
int main(){
	scanf("%d%d",&n,&k);
	if(k==1){
		puts("1");
		return 0;
	}
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=n*k;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=n*k;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=n*k;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=1;
		for(int j=1;j<=i;j++)
			f[i][j]=add((j<i)?f[i-1][j]:0,mul(f[i][j-1],C(n*k-i-(j-1)*(k-1)-1,k-2)));
	}
	printf("%d ",mul(f[n][n],_mul[n]));
}