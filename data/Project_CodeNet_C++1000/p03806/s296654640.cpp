#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
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


const int inf = 1000000000;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,ma,mb;cin >> n >> ma >> mb;
	vector<int> a(n),b(n),c(n);
	rep(i,n) cin >> a.at(i) >> b.at(i) >> c.at(i);
	vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(500,vector<int>(500,inf)));
	dp[0][0][0] = 0;
	rep(i,n){
		rep(j,401){
			rep(k,401){
				dp[i + 1][j + a.at(i)][k + b.at(i)] = min(dp[i + 1][j + a.at(i)][k + b.at(i)], dp[i][j][k] + c.at(i));
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}
	int ans = inf;
	rep(i,n){
		for(int j = 1; j * ma <= 400 && j * mb <= 400; j++){
			ans = min(ans, dp[i + 1][j * ma][j * mb]);
		}
	}
	cout << (ans == inf ? -1 : ans) << endl;
}
