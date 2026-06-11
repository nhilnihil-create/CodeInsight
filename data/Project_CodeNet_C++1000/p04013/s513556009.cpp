#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
ll dp[55][55][5000];

signed main(){
	//cout << fixed << setprecision(10);
	ll n,A; cin>>n>>A;
	vl vec(n);
	rep(i,0,n)cin>>vec[i];
	dp[0][0][0]=1;
	rep(i,0,n){
		rep(j,0,n+1){
			rep(k,0,3000){
				dp[i+1][j][k]+=dp[i][j][k];
				if(k+vec[i]<5000)dp[i+1][j+1][k+vec[i]]+=dp[i][j][k];
			}
		}
	}
	ll ans=0;
	rep(i,1,n+1)ans+=dp[n][i][A*i];
	cout<<ans<<endl;

	return 0;
}