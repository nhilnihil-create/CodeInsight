#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005
using namespace std;
typedef long long ll;
struct mat{
	ll a[15][15];
}dan;
int n,m,a[N],d[N],fa[N][65],now[N];
ll k,b[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),d[i]=a[i]-a[i-1],now[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		swap(now[x],now[x+1]);
	}
	for(int i=1;i<=n;i++) fa[i][0]=now[i];
	for(int i=1;i<=62;i++)
		for(int p=1;p<=n;p++) fa[p][i]=fa[fa[p][i-1]][i-1];
	for(int i=1;i<=n;i++){
		now[i]=i;
		for(int p=0;p<=62;p++){
			if(k&(1LL<<p)) now[i]=fa[now[i]][p];
		}
		b[i]=d[now[i]];
	}
	for(int i=1;i<=n;i++,b[i]+=b[i-1]) printf("%lld\n",b[i]);
	return 0;
}