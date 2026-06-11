#include <bits/stdc++.h>
using namespace std;
	int N,K;
	const int MAX_N = 5000;
	int a[MAX_N];
	bool dp[MAX_N];

bool C(int k){
	if(k<0) return false;
	if(k>=N) return false;
	if(a[k]>=K) return true;
	fill(dp,dp+K,false);
	dp[0]=true;
	for(int i=0;i<N;i++){
		if(i==k) continue;
		for(int j=K-1;j>=a[i];j--){
			dp[j] |= dp[j-a[i]];
		}
	}
	for(int i=K-a[k];i<K;i++){
		if(dp[i]) return true;
	}
	return false;
}

void solve(){
	sort(a,a+N);
	int lo = -1;
	int hi = N;
	while(hi-lo>1){
		int mi = (hi+lo)/2;
		if(C(mi)) hi = mi;
		else lo = mi;
	}
	printf("%d\n",hi);
}

int main(){
	cin>>N>>K;
	for(int i=0; i<N; i++){
		cin>>a[i];
	}
	solve();
	return 0;
}