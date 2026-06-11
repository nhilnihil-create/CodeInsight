#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n;
int a[1000005];
bool val[1000005];
bool check(int lim){
	int ans=-1;
	for(int i=1;i<=n;i++){
		if(a[i]>lim)val[i]=1;
		else val[i]=0;
	}
	for(int i=n/2+2,j=n/2;i<=n;j--,i++)
	{
		if(val[i]==val[i-1]){
			ans=val[i];
			break;
		}
		if(val[j]==val[j+1]){
			ans=val[j];
			break;
		}
	}
	if(ans==-1) return val[1];
	else return ans;
}
signed main(){
	scanf("%lld",&n);
	n=2*n-1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	printf("%lld",l);
}