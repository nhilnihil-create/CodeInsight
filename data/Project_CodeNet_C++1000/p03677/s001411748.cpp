#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define inf 1000000000000000
#define eps 1e-9
using namespace std;
typedef long long ll;
ll n,m,ans=-inf,maxn=0,a[100001],s[200001];
int main(){
	memset(s,0,sizeof(s));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1)continue;
		if(a[i-1]>a[i])a[i]+=m;
		maxn+=a[i]-a[i-1];
		if(a[i-1]<a[i]-1){
			s[a[i-1]+2]++;
			s[a[i]+1]-=a[i]-a[i-1];
			s[a[i]+2]+=a[i]-a[i-1]-1; 
		}
		if(a[i]>m)a[i]-=m;
	}
	for(int i=1;i<=m*2;i++)s[i]+=s[i-1];
	for(int i=1;i<=m*2;i++)s[i]+=s[i-1];
	for(int i=1;i<=m;i++){
		ans=max(ans,s[i]+s[i+m]);
	}
	printf("%lld",maxn-ans);
	return 0;
}