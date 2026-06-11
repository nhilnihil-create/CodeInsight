#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(v) v.begin(), v.end()
#define revall(v) v.rbegin(), v.rend()
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){ if(y<h && y>=0 && x<w && x>=0) return true; return false; }
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true; } return false; }






int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a;cin >> n >> a;
	vector<int> x(n);
	rep(i,n) cin >> x.at(i);
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n * 60)));
	dp[0][0][0] = 1;
	rep(i,n){
		rep(j,n){
			rep(k,n * 50 + 1){
				dp[i + 1][j][k] += dp[i][j][k];
				dp[i + 1][j + 1][k + x.at(i)] += dp[i][j][k];
			}
		}
	}
	ll ans = 0;
	for(int i = a; i <= a * n; i += a){
			ans += dp[n][i / a][i];
	}
	cout << ans << endl;
}
