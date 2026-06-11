#include<bits/stdc++.h>
using namespace std;
int n,k;
long long sum[100100];
long long possum[100100];
int a;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum[i]=sum[i-1]+a;
		possum[i]=possum[i-1];
		if(a>0)
			possum[i]+=a;
	}
	long long ans=sum[n];
	for(int i=1;i<=n-k+1;i++){
		long long s1=possum[i-1];
		long long s2=possum[n]-possum[i+k-1];
		ans=max(ans,s1+s2);
		ans=max(ans,s1+s2+sum[i+k-1]-sum[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}
