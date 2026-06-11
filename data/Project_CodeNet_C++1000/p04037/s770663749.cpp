#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int N=200010;
int a[N],b[N],dp[N];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int n;int i,j,now;
	scanf("%d",&n);
	//if(n==1){printf("First\n");return 0;}
	rep(i,1,n)	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	rep(i,1,n)	b[i]=a[i]-a[i-1];
	for(now=0,i=1;i<=n&&now<=n+10;i++){
		if(now>1&&(b[i]&1)==0&&dp[now-1]==1&&dp[now-2]==1)	dp[now-1]=0;
		for(j=0;j<=b[i]&&now<=n+10;j++,now++)	dp[now]=!((b[i]-j)&1);
	}
	//rep(i,0,now-1)	printf("%d\n",dp[i]);
	//rep(i,1,now)	if(dp[i]==0&&dp[i-1]==0)	dp[i]=1;	
	if(dp[n-1]==1)	printf("First\n");
	else printf("Second\n");
}
	