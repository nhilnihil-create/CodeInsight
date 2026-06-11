#include<cstdio>
int n,p[100010],m,x,r[100010],v[100010],beg[100010],cnt1,cnt2;
long long a[100010],k,ans[100010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",a+i),a[i-1]=a[i]-a[i-1],p[i-1]=i-1;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;++i)scanf("%d",&x),p[x]^=p[x-1],p[x-1]^=p[x],p[x]^=p[x-1];
	for(int i=0;i<n;++i)if(!r[i]){
		v[beg[++cnt2]=++cnt1]=i;r[i]=cnt2;
		for(int j=p[i];j!=i;j=p[j])v[++cnt1]=j,r[j]=cnt2;
	}beg[cnt2+1]=n+1;
	for(int i=1;i<=cnt2;++i){
		int len=beg[i+1]-beg[i];
		for(int j=beg[i];j<beg[i+1];++j)ans[v[j]]=v[(j-beg[i]+k)%len+beg[i]];
	}
	ans[0]=a[ans[0]];for(int i=1;i<n;++i)ans[i]=a[ans[i]]+ans[i-1];
	for(int i=0;i<n;++i)printf("%lld.0\n",ans[i]);
	return 0;
}