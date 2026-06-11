#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define reg register
typedef long long ll;
const int p=1e9+7;
const int maxn=5005;
int n,f[maxn][maxn]={1},i,j,len;
ll res;
char ch;
inline ll qpow(ll a,ll b){
	res=1;while(b){if(b&1)res=res*a%p;a=a*a%p;b>>=1;}return res;
}
int main(){
	scanf("%d\n",&n);while((ch=getchar())!='\n')len++;
	for(i=0;i<=n;++i)for(j=0;j<=i;++j){
            f[i+1][j+1]=(f[i+1][j+1]+(f[i][j]<<1)%p)%p;
            f[i+1][max(j-1,0)]=(f[i+1][max(j-1,0)]+f[i][j])%p;
		}
	printf("%d\n",f[n][len]*qpow(qpow(2,len),p-2)%p);
    return 0;
}