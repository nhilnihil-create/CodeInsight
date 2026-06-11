#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll N,x;
	cin>>N>>x;
	vector<ll> a(N), dp(N,LLONG_MAX);
	for (int i=0; i<N; i++)
		cin>>a[i];
	ll ret=LLONG_MAX;
	for(int i=0; i<N; i++) {
		ll cur=0;
		for(int j=0; j<N; j++)
			dp[j]=min(dp[j],a[(j+N-i)%N]), cur+=dp[j];
		ret=min(ret,cur+i*x);
	}
	cout<<ret<<"\n";
	return 0;
}