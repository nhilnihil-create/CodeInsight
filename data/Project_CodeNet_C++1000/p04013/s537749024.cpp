#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<40)
#define mod 998244353
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
	ll n,A;cin>>n>>A;
	vector<ll> a(n+1);
	rep(i,n+1) if(i!=0) cin>>a[i];

	vector<vector<vector<ll>>> dp(55,vector<vector<ll>>(55,vector<ll>(3000,0)));//i番目まで選べるとき 要素をk個選んでいるとき　和をjにする方法数
	dp[0][0][0]=1;

	rep(i,n+1){//i番目まで選べる
		rep(j,n+1){//選ぶ個数
			rep(k,3000){//和
				if(i==0 && j==0 && k==0) continue;

				if(i>=1 && k-a[i]<0) dp[i][j][k]=dp[i-1][j][k];//i番目を選ばないとき
				else if(i>=1 && j>=1 && k-a[i]>=0) dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-a[i]];//i番目を選択する
				else dp[i][j][k]=0;
			}
		}
	}

	ll ans=0;
	rep(i,n+1){
		if(i==0) continue;
		ans+=dp[n][i][i*A];
	}
	cout<<ans<<endl;
    return 0;
}