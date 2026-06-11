#include <algorithm>
#include <cstdio>

const int N=100005;

int x[N],to[N],q[N];
bool use[N];

int main(){
	int n,m;long long k;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		to[i]=i;
	}
	for (int i=n;i;i--) x[i]-=x[i-1];
	scanf("%d%lld",&m,&k);
	for (int i=1;i<=m;i++){
		int a;
		scanf("%d",&a);
		std::swap(to[a],to[a+1]);
	}
	for (int i=1;i<=n;i++)
	if (!use[i]){
		int tot=0;
		use[q[tot++]=i]=1;
		for (int j=to[i];!use[j];j=to[j])
			use[q[tot++]=j]=1;
		for (int j=0;j<tot;j++)
			to[q[j]]=q[(j+k)%tot];
	}
	long long pos=0;
	for (int i=1;i<=n;i++) printf("%lld\n",pos+=x[to[i]]);
}