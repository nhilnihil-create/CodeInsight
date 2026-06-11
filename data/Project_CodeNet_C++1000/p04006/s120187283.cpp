#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define inf 1<<30
using namespace std;
const int MAXN=4010;
ll n,x,a[MAXN],nm[MAXN][MAXN];
int main()
{
	ll ans=0;
	scanf("%lld%lld",&n,&x);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[n+i]=a[i],ans+=a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			nm[i][0]=a[i];
			nm[i][j]=min(nm[i][j-1],a[n+i-j]);
		}
	}
	for(int k=0;k<n;k++){
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum+=nm[i][k];
		}
		ans=min(ans,sum+x*k);
	}
	printf("%lld\n",ans);
}