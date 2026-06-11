#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N,K,A[5005];
signed dpl[5005][5005],dpr[5005][5005];
signed main(){
	cin>>N>>K;
	rep(i,N){
		cin>>A[i];
	}
	dpl[0][0]=1;
	rep(i,N){
		rep(j,K+1){
			dpl[i][j]=(bool)dpl[i][j];
			dpl[i+1][j]|=dpl[i][j];
			dpl[i+1][min(K,j+A[i])]|=dpl[i][j];
		}
	}
	dpr[N][0]=1;
	for(int i=N;i>0;i--){
		rep(j,K+1){
			dpr[i][j]=(bool)dpr[i][j];
			dpr[i-1][j]|=dpr[i][j];
			dpr[i-1][min(K,j+A[i-1])]|=dpr[i][j];
		}
		for(int j=K;j>0;j--)dpr[i][j-1]+=dpr[i][j];
	}
	int ans=0;
	rep(i,N){
		bool flag=true;
		rep(j,K+1){
			if(!dpl[i][j])continue;
			if(dpr[i+1][max(0ll,K-A[i]-j)]-dpr[i+1][K-j])flag=false;
		}
		ans+=flag;
	}
	cout<<ans<<endl;
}
