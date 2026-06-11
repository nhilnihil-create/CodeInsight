#include <algorithm>
#include <cstdio>
using namespace std;
long long f[100005],g[100005];
int main(){
	int n,m,a,b;
	long long sum=0,ans;
	scanf("%d%d%d",&n,&m,&a);
	for (int i=1;i<n;i++){
		scanf("%d",&b);
		sum+=b-a;
		f[a+1]+=a+1;
		f[b+1]-=a+1;
		g[a+1]++;
		g[b+1]--;
		if (a>b){
			sum+=m;
			f[1]+=a+1-m;
			f[b+1]+=m;
			g[1]++;
		}
		a=b;
	}
	ans=sum;
	for (int i=1;i<=m;i++){
		f[i]+=f[i-1];
		g[i]+=g[i-1];
		ans=std::min(ans,sum+f[i]-g[i]*i);
	}
	printf("%lld\n",ans);
}