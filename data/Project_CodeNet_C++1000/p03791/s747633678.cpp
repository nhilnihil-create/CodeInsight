#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr double eps = 1e-9;
constexpr ll MOD = 1000000007LL;
template <typename T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};
int main(){
	int n;cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	a[0]=1;
	int co=1;
	vector<ll> v;
	for(int i=1;i<n;i++){
		if(a[i]>=a[i-1]+2){
			co++;
			a[i]=a[i-1]+2;
		}else{
			v.push_back(co);
			co=1;
		}
	}
	vector<ll> f(n+1);
	f[0]=1;
	for(ll i=1;i<=n;i++){
		f[i]=f[i-1]*i%MOD;
	}
	v.push_back(co);
	ll res=1;
	ll t=0,sum=0;
	for(int i=0;i<v.size();i+=2){
		sum+=v[i];
		if(i>0){
			sum+=v[i-1];
		}
		if(i+1<v.size()){
			res*=sum-t+1LL;
		}else{
			res*=sum-t;
		}
		res%=MOD;
		t++;
	}
	res*=f[n-t];
	res%=MOD;
	cout<<res<<endl;
}
