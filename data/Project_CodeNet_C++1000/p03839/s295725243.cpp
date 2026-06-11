#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
	int N,K;
	cin>>N>>K;
	vector<int> a(N);
	rep(i,N) cin>>a[i];

	vector<ll> v(N+1,0);
	rep(i,N) v[i+1]=v[i]+a[i];
	vector<ll> w(N+1,0);
	rep(i,N) w[i+1]=w[i]+max(a[i],0);
	ll ans=-INF;
	for(int i=0;i+K<=N;i++){
		ll tmp=w[N];
		tmp+=max(v[i+K]-v[i],0LL);
		tmp-=w[i+K]-w[i];
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
}