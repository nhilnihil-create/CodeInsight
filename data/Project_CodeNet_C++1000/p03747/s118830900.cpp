#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,l,t;
	scanf("%lld%lld%lld",&n,&l,&t);
	pair<long long,int> x[n];int w;
	for(int i=0;i<n;i++){
		scanf("%lld%d",&x[i].first,&w);
		x[i].second=(w==1?1:-1);
	}
	long long ans[n],offset=0;
	for(int i=0;i<n;i++){
		ans[i]=x[i].first+x[i].second*t;
		offset+=(ans[i]>0?ans[i]:ans[i]-l+1)/l;
		ans[i]%=l;ans[i]+=l;ans[i]%=l;
	}
	offset%=n;offset+=n;offset%=n;
	sort(ans,ans+n);
	for(int i=0;i<n;i++){
		printf("%lld\n",ans[(i+offset)%n]);
	}
}
