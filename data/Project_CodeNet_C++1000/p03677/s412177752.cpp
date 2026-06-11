#include<cstdio>
int n,m,a[100010];
long long f[200010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	long long sum=0;
	for(int i=1;i<n;i++){
		int l=a[i-1],r=a[i];
		if(r<l)r+=m;
		f[l+2]++;f[r+1]-=r-l;f[r+2]+=r-l-1;
		sum+=r-l;
	}
	long long ans=sum;
	for(int t=2;t--;)
		for(int i=1;i<=m*2;i++)f[i]+=f[i-1];
	for(int i=1;i<=m;i++)
		if(sum-(f[i]+=f[i+m])<ans)ans=sum-f[i];
	printf("%lld\n",ans);
}