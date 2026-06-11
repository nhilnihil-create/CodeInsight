#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}


const int inf = 1e9;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,ma,mb;cin >> n >> ma >> mb;
	vector<int> a(n),b(n),c(n);
	rep(i,n) cin >> a.at(i) >> b.at(i) >> c.at(i);
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(410, vector<int>(410, inf)));
	dp[0][0][0] = 0;
	rep(i,n){
		rep(j,401){
			rep(k,401){
				if(j - a.at(i) >= 0 && k - b.at(i) >= 0){
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - a.at(i)][k - b.at(i)] + c.at(i));
				}
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}
	int ans = inf;
	for(int i = ma, j = mb; i <= 400 && j <= 400; i += ma, j += mb){
		ans = min(ans, dp[n][i][j]);
	}
	if(ans == inf) cout << -1 << endl;
	else cout << ans << endl;
}
