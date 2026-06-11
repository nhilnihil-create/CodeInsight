#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,m,a[N],sum[N],sum1[N];
void add1(int l,int r,int z){sum[l]+=z;sum[r+1]-=z;}
void add2(int l,int r,int z){sum1[l]+=z;sum1[r+1]-=z;}
signed main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++){
		int l=a[i];int r=a[i+1];
		if (l==r) continue;
		if (l<r){
			add1(1,l,r-l);
			add1(r+1,m,r-l);
			add1(l+1,r,r+1);
			add2(l+1,r,-1);
		}
		else {
			add1(r+1,l,r+m-l);
			add1(l+1,m,r+m+1);
			add2(l+1,m,-1);
			add1(1,r,r+1);
			add2(1,r,-1);
		}
	}
	int ans=1e18;
	for (int i=1;i<=m;i++){
		sum[i]+=sum[i-1];sum1[i]+=sum1[i-1];
		ans=min(ans,sum[i]+sum1[i]*i);
	}
	printf("%lld\n",ans);
	return 0;
}