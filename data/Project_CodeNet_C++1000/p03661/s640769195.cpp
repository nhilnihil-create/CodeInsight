#include<bits/stdc++.h>
using namespace std;
int n,x;
long long a[200005],ans=1e18;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&x),a[i]=a[i-1]+x;
	for (int i=1;i<n;i++)
		ans=min(ans,abs(a[n]-2*a[i]));
	printf("%lld",ans);
}