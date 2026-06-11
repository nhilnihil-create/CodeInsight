#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll num[100005];
int opt[100005];

int main() {
  int n;
  scanf("%d",&n);
  ll ans=0,sum=0;
  for(int i=1;i<=n;i++) {
  	if (i==1) opt[i]=1;
  	else {
  		char str[5];
  		scanf("%s",str);
  		opt[i]=((str[0]=='+')?1:-1);
	  }
  	scanf("%lld",&num[i]);
	ans+=opt[i]*num[i];
	sum+=num[i];
  }
  for(int i=1;i<=n;i++)
    if (opt[i]==-1) {
    	ll s=sum-2LL*num[i];
    	for(int j=i+1;j<=n&&opt[j]==1;j++) s-=2LL*num[j];
    	ans=max(ans,s);
    	sum-=2LL*num[i];
	}
  printf("%lld\n",ans);
  return 0;
}