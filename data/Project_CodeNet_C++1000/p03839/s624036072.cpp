#include<bits/stdc++.h>
using namespace std;

long long int pre[100001],pre2[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>pre[i];
		pre2[i]=max(pre[i],0LL);
		pre[i]+=pre[i-1];
		pre2[i]+=pre2[i-1];
	}
	long long int ans=-1e18;
	for(int i=k;i<=n;i++){
		long long int x=pre[i]-pre[i-k];
		ans=max(ans,pre2[n]-(pre2[i]-pre2[i-k])+max(x,0LL));
	}
	cout<<ans<<endl;
}

