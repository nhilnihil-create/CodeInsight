#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long

using namespace std;

const int N=1e5+10;
int n,m,a[N]; ll sum[N],sum2[N],ans;

int main(){
	scanf("%d%d",&n,&m);
	rep (i,1,n){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+max(a[i],0);
		sum2[i]=sum2[i-1]+a[i];
	}
	rep (i,1,n-m+1)
		ans=max(ans,sum[i-1]+sum[n]-sum[i+m-1]+max(sum2[i+m-1]-sum2[i-1],0ll));
	printf("%lld\n",ans);
	return 0;
}