#include <iostream>
using namespace std;
typedef long long ll;
const int N=2010,mod=1000000007;
int a[N*N],b[N*N],f[N][N];
int add(int a,int b){
    a+=b;
    return a>=mod?a-mod:a;
}
int mul(int a,int b){
    return 1LL*a*b%mod;
}
int pow(int a,int b)
{
    ll res=1%mod;
    for(;b;b>>=1){
        if(b&1) res=(ll)(res*a)%mod;
        a=(ll)a*a%mod;
    }
    return res;
}

int function(int n,int m)
{
    return mul(a[n+m-1],mul(b[m-1],b[n]));
}
void init(int n)
{
	a[0]=1;
	for(int i=1;i<=n;i++)
		a[i]=mul(a[i-1],i);
	b[n]=pow(a[n],mod-2);
	for(int i=n;i;--i)
		b[i-1]=mul(b[i],i);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1) return 0&puts("1");
	init(n*k);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=0;--j)
			f[i][j]=add(f[i][j+1],j==0?0:mul(f[i-1][j-1],mul(n-i+1,function(k-2,(i-1)*k-(j-1)+1))));
	printf("%d\n",f[n][0]);
	return 0;
}