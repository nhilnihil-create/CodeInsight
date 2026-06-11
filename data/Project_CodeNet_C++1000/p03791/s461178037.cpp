#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
void cmps(vector<int>&v,int &i){
	i=lower_bound(all(v),i)-v.begin();
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int mod_pow(int x,int y,int m=mod){
	int res=1;
	while(y>0){
		if(y&1)res=res*x%m;
		y>>=1;x=x*x%m;
	}
	return res;
}
int perm[1000001],inv[1000001];
void init_perm(){
	perm[0]=1;
	REP(i,1000001)perm[i]=perm[i-1]*i%mod;
	inv[1000000]=mod_pow(perm[1000000],mod-2);
	for(int i=999999;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
int nCk(int x,int y){
	if(x<y)return 0;
	return perm[x]*inv[x-y]%mod*inv[y]%mod;
}

int N,X[100005];
signed main(){
	init_perm();
	cin>>N;
	rep(i,N)cin>>X[i];
	int now=0,ans=1;
	rep(i,N){
		if(X[i]<(now+1)*2-1){
			ans*=(now+1);ans%=mod;
		}else now++;
	}
	cout<<ans*perm[now]%mod<<endl;
}
