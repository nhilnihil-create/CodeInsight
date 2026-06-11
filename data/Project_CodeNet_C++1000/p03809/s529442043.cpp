#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005
using namespace std;
typedef long long ll;
struct edge{
	int k,next;
}e[N<<1];
int n,home[N],cnt=-1,w[N],D=1;
ll f[N],a[N];
void add(int x,int y){
	cnt++;
	e[cnt].k=y;
	e[cnt].next=home[x];
	home[x]=cnt;
}
void dfs(int k,int F){
	if(w[k]==1){
		f[k]=a[k];return;
	}
	ll sum=0;
	for(int i=home[k];~i;i=e[i].next) if(e[i].k!=F){
		dfs(e[i].k,k);
		if(!D) return;
		if(f[e[i].k]>a[k]){
			D=0;return;
		}
		sum+=f[e[i].k];
	}
	if(sum<a[k]){
		D=0;return;
	}
	if(sum>a[k]+a[k]){
		D=0;return;
	}
	f[k]=a[k]+a[k]-sum;
}
int main(){
	memset(home,-1,sizeof(home));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n==2){
		if(a[1]!=a[2]) puts("NO");
		else puts("YES");
		return 0;
	}
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		w[x]++;w[y]++;
	}
	int F;
	for(int i=1;i<=n;i++) if(w[i]>1){
		F=i;
		dfs(i,0);
		break;
	}
	if(D&&!f[F]) puts("YES");
	else puts("NO");
	return 0;
}