#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N=2010;
ll n,x,a[N],mn[N],ans,sum;
int main(){
	scanf("%lld%lld",&n,&x);
	for(int i=0;i<n;i++) scanf("%lld",a+i),ans+=a[i];
	memset(mn,0x3f,sizeof(mn));
	for(int i=0;i<n;i++){
		sum=0ll;
		for(int j=0;j<n;j++) mn[j]=min(a[(j-i+n)%n],mn[j]),sum+=mn[j];
		ans=min(ans,sum+i*x);
	}printf("%lld\n",ans);
}