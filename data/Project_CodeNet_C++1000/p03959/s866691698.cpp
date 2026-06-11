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
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

void solve(){
	//最大値が更新されるとき、高さは一意に決まり、それ以外は今まで登ってきた山の中から最も高い山の標高通りある。
	//更新されるときときに相手が自分より低いと矛盾になる(相手は自分より先を見てきたはずなので)
	int n;
	cin>>n;
	vector<ll>t(n),a(n);
	ll maxv=0,maxv2=0;
	vector<ll>cnt(n),cnt2(n);
	rep(i,n)cin>>t[i];
	rep(i,n)cin>>a[i];
	rep(i,n){
		if(!chmax(maxv,t[i]))cnt[i]=t[i];
		else {
			if(maxv>a[i])cnt[i]=0;
			else cnt[i]=1;
		}
	}
	for(int i=n-1;i>=0;--i){
		if(!chmax(maxv2,a[i]))cnt2[i]=a[i];
		else {
			if(maxv2>t[i])cnt2[i]=0;
			else cnt2[i]=1;
		}
	}
	ll ans=1;
	rep(i,n){
		ans*=min(cnt[i],cnt2[i]);
		ans%=mod;
	}
	cout<<ans<<"\n";
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
