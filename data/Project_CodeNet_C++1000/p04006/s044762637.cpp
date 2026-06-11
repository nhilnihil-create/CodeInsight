#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll a[2005];ll x;ll dp[2005][2005];ll sum=1ll<<60ll;
int main(){
	cin>>N>>x;

	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	for(int i=1;i<=N;i++){
		dp[i][0]=a[i];
	
	for(int j=1;j<=N;j++){
		int pos=i-j;
		if(pos<=0)pos=N-abs(pos);
		dp[i][j]=min(dp[i][j-1],a[pos]);

	}
}

for(int i=0;i<=N-1;i++){
	ll ans=0;
	for(int j=1;j<=N;j++){
		ans+=dp[j][i];
		
	}
	sum=min(sum,ans+i*x);
}
	cout<<sum<<endl;
}
