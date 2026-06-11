#include<iostream>
#include<string.h>
#define N 120000
using namespace std;
long long s[N],t[N],a[N];
long long ans,n,m;
long long add(long long x,long long y,long long l,long long r){
	if(x==0)x=m;
	if(y==0)y=m;
	l%=m;
	r%=m;
//	printf("%lld %lld %lld %lld\n",x,y,l,r);
	t[x]+=l-1;
	t[y+1]-=r;
	s[x]+=1;
	s[y+1]-=1; 
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++){
		a[i]+=a[i-1]/m*m;
		while(a[i]<a[i-1])a[i]+=m;
	}
	for(long long i=1;i<n;i++){
		if(a[i+1]-a[i]<2)continue;
		if((a[i])/m==(a[i+1]-1)/m){
			add((a[i]+1)%m,(a[i+1])%m,0,a[i+1]-a[i]-1);
		}else{
			long long o=m-(a[i]+1)%m; 
			add((a[i]+1)%m,m,0,o);
			add(1,a[i+1]%m,o+1,(o+a[i+1]%m)%m);
		}
	}
	for(long long i=1;i<=m;i++)s[i]+=s[i-1];
	for(long long i=1;i<=m;i++)s[i]+=s[i-1];
	for(long long i=1;i<=m;i++)t[i]+=t[i-1];
	for(long long i=1;i<=m;i++)s[i]+=t[i];
	for(long long i=1;i<=m;i++)ans=max(ans,s[i]);
	printf("%lld\n",a[n]-a[1]-ans);
}