#include<bits/stdc++.h>
using namespace std;

int n,m,buc[100005],buc2[100005],d[100005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		++buc[x],++buc2[x%m];
	}
	int ans=buc2[0]/2;
	if(m%2==0)ans+=buc2[m/2]/2;
	for(int i=1;i<=(m-1)/2;++i){
		int t=min(buc2[i],buc2[m-i]);
		ans+=t;
		d[i]+=t,d[m-i]+=t;
	}
	for(int i=1;i<m;++i)
		if(i*2!=m){
			int sum=0,cnt[2]={};
			for(int j=i;j<=100000;j+=m)
				sum+=buc[j],++cnt[buc[j]&1];
			if(d[i]<=cnt[1])cnt[1]-=d[i];
			else cnt[1]=d[i]-cnt[1]&1;
			ans+=(sum-d[i]-cnt[1])/2;
		}
	printf("%d\n",ans);
}
