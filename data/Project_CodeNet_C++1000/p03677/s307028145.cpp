#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M=1e6+5;

int a[M];
ll ans=0,Max=0,d[M];

int main()
{
	//freopen("buying.in","r",stdin);
	//freopen("buying.out","w",stdout);
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int i=1;i<m;i++){
		if(a[i]<a[i+1]){
			d[a[i]+2]++; 
			d[a[i+1]+1]-=a[i+1]-a[i];
			d[a[i+1]+2]+=a[i+1]-a[i]-1;
			ans+=a[i+1]-a[i];
		}
		else{
			d[a[i]+2]++;
			if(a[i]<n) d[1]+=n-a[i],d[2]-=n-a[i]-1;
			else d[2]++;
			d[a[i+1]+1]-=a[i+1]-a[i]+n;
			d[a[i+1]+2]+=a[i+1]-a[i]+n-1;
			ans+=a[i+1]-a[i]+n;
		}
	}
	for(int i=1;i<=n;i++) d[i]+=d[i-1];
	for(int i=1;i<=n;i++) d[i]+=d[i-1];
	for(int i=1;i<=n;i++) Max=max(Max,d[i]);
	printf("%lld\n",ans-Max);
	return 0;
}