#include<bits/stdc++.h>
#define rint register int
#define ll long long 
using namespace std;
int N,A[1010010];
ll ans=1e18,X;
multiset<ll> st;
int main(){
	cin>>N>>X;
	for(rint i=1;i<=N;++i) cin>>A[i];
	for(rint i=N+1;i<=2*N;++i) A[i]=A[i-N]; 
	for(rint i=0;i<N;++i) {
		ll sum=1ll*i*X;
		st.clear();
		for(rint j=1;j<=N;++j){
			st.insert(1ll*A[j]);
		}
		int cur=1;
		for(rint j=N+1;j<=N+N;++j){
			while(cur<j-i) st.erase(A[cur]),cur++;
			st.insert(1ll*A[j]);
			sum+=(*st.begin());
		}
		ans=min(ans,sum);
	} 
	cout<<ans;
	return 0;
}