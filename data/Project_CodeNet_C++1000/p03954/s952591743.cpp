#include<bits/stdc++.h>
using namespace std;
int len,c[10],a[500005],b[500005],n;
int work(int i,int j,int k){
	int cnt=0;
	if(i==0) cnt++;
	if(j==0) cnt++;
	if(k==0) cnt++;
	if(cnt>=2) return 0;
	return 1;
}
int calc(int i,int j,int k){
	len=3;
	c[1]=i; c[2]=j; c[3]=k;
	sort(c+1,c+len+1);
	return c[2];
}
int check(int x){
	for(int i=1;i<=2*n+1;++i)
		if(a[i]>=x) b[i]=1;
		else b[i]=0;
	int p0=1e9+7,p1=1e9+7;
	for(int i=1;i<2*n-1;++i)
		if(b[i]==b[i+1]){
			if(b[i]) p1=min(p1,min(abs(n-i),abs(n-i-1)));
			else p0=min(p0,min(abs(n-i),abs(n-i-1)));
		}
	if(p0==1e9+7 && p1==1e9+7) return b[1];
	return p0>p1;
}
int main(){
//	freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	int l,r,mid;
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;++i)
		scanf("%d",a+i);
	l=r=a[1];
	for(int i=2;i<=2*n-1;++i)
		l=min(l,a[i]),r=max(r,a[i]);
	int ans=l;
	while(l<=r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}