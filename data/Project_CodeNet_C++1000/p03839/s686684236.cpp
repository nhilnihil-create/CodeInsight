#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
int arr[N],sum1[N],sum2[N];
signed main(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
		sum1[i]=sum1[i-1]+arr[i];
		if(arr[i]>0)
			sum2[i]=sum2[i-1]+arr[i];
		else 
			sum2[i]=sum2[i-1];
	}
	ans=max(ans,sum1[n]);
	for(int i=1;i<=n-k+1;i++){
		int t1=sum2[i-1];
		int t2=sum2[n]-sum2[i+k-1];
		ans=max(ans,t1+t2);
		ans=max(ans,t1+t2+sum1[i+k-1]-sum1[i-1]);
	}
	cout<<ans;
	return 0;
}