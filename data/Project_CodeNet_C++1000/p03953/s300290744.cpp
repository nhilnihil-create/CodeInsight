#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1000100;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
ll K;
ll n,i,k,m,x[N],y[N],a[N],b[N];
void mul(ll*c,ll*A,ll*B){
	static int a[N],b[N],i;
	for(i=1;i<=n;i++)a[i]=A[i],b[i]=B[i];
	for(i=1;i<=n;i++)c[i]=a[b[i]];
}
int main(){
	//freopen("1.out","w",stdout);
	n=read();
	for(i=1;i<=n;i++)x[i]=read();
	for(i=n;i;i--)x[i]=x[i]-x[i-1];
	for(i=1;i<=n;i++)a[i]=b[i]=i;
	m=read();scanf("%lld",&K);
	//printf("%lld\n",K);
	for(i=1;i<=m;i++)
		k=read(),swap(b[k],b[k+1]);
	for(;K;K>>=1,mul(b,b,b))
	if(K&1)mul(a,a,b);
	for(i=1;i<=n;i++)y[i]=y[i-1]+x[a[i]],printf("%lld.0\n",y[i]);;
	return 0;
}