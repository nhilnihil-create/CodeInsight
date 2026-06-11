#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization ("Ofast")
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define siz(s) (int)s.size()

template<class T> inline bool chmin(T &a, T b) {
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if(a<b){a=b;return true;}
	return false;
}
template<class T> inline int getidx(vector<T> &v, T a) {
	return lower_bound(all(v), a) - v.begin();
}

constexpr int mod=1e9+7;
constexpr int inf=3e18;


int mod_pow(int x,int y){
	int res=1;
	while(y>0){
		if(y&1)(res*=x)%=mod;
		(x*=x)%=mod;y>>=1;
	}
	return res;
}
int N,dp[5005][5005];
string s;
signed main(){
	cin>>N>>s;
	dp[0][0]=1;
	rep(i,N){
		rep(j,i+1){
			dp[i][j]%=mod;
			dp[i+1][max(0ll,j-1)]+=dp[i][j];
			dp[i+1][j+1]+=dp[i][j]*2;
		}
	}
	cout<<dp[N][siz(s)]*mod_pow(mod_pow(2,siz(s)),mod-2)%mod<<endl;
}
