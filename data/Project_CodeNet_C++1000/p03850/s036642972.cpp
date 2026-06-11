#include<bits/stdc++.h>
#define N 100005
#define LL long long
#define INF (1LL<<60)
using namespace std;
int n,m; LL a[N],b[N],sum,ans=-INF;
int main()
{
	int i,x; char op;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i==1) op='+'; else scanf("%c",&op);
		scanf("%d ",&x),sum+=x;
		if(op=='-') a[++m]=x; else b[m]+=x;
	  }
	if(!m) ans=sum;
	for(i=1;i<=m;i++){
		ans=max(ans,sum-2*(a[i]+b[i]));
		sum-=2*a[i];
	  }
	cout<<max(ans,sum);
	return 0;
}