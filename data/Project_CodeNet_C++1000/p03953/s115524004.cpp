#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
const int MAXN=1e5+5;

ll n,m,k;
ll a[MAXN],ans[MAXN],id[MAXN];
ll sta[MAXN],top;
bool vis[MAXN];

int main(){

	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),id[i]=i;
	for(int i=n;i>=1;i--) a[i]-=a[i-1];
	scanf("%lld%lld",&m,&k);
	for(int i=1;i<=m;i++){
	    int x;
        scanf("%d",&x);
        swap(id[x],id[x+1]);
	}
	for(int i=1;i<=n;i++){
	    if(vis[i]) continue;
	    top=0;
	    for(int j=i;j<=n&&!vis[j];j=id[j]) sta[++top]=j,vis[j]=1;
	    for(int j=1;j<=top;j++) ans[sta[j]]=a[sta[(j+k-1)%top+1]];
	}
	for(int i=1;i<=n;i++)
		ans[i]+=ans[i-1],printf("%lld\n",ans[i]);

	fclose(stdin);
	fclose(stdout);
}
