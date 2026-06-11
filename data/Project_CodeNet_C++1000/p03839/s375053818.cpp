#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,K;
	cin >> N >> K;
	vector<long long> a(N);
	for(auto &i:a)cin >> i;
	vector<long long> sum(N+1,0);
	vector<long long> psum(N+1,0);
	for(int i=0;i<N;i++){
		sum[i+1]=sum[i]+a[i];
		psum[i+1]=psum[i]+max(0LL,a[i]);
	}
	
	long long ans=-999999999999999LL;
	for(int i=0;i+K-1<N;i++){
		long long tmp=max(0LL,sum[i+K]-sum[i]);
		tmp+=psum[i];
		tmp+=psum[N]-psum[i+K];
		ans=max(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}