#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;



signed main(){
	int n;
	cin>>n;
	vector<ll>a(n);
	vector<int>idx(n+5);
	rep(i,n){
		cin>>a[i];
		idx[a[i]]=i+1;
	}
	set<ll>s;
	s.emplace(n+1);
	s.emplace(0);
	ll ans=0;
	for(int64_t i=1;i<=n;++i){//値の小さなものから見ていく
		auto right=s.upper_bound(idx[i]);
		auto left=right;
		left--;
		ans+=i*(*right-idx[i])*(idx[i]-*left);
		s.emplace(idx[i]);
	}
	cout<<ans<<endl;
	return 0;
}