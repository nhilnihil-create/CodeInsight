#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = 1e9+7;

using namespace std;
int dp[45][450][450]; // dp[i][a][b] := i番目まで見て合計がa b となる場合の最小コスト
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,Ma,Mb;
	cin >> N >> Ma >> Mb;
	vector<int> a(N),b(N),c(N);
	rep(a,45)rep(b,450)rep(c,450)dp[a][b][c] = inf;
	rep(i,N){
		cin >> a[i] >> b[i] >> c[i];
	}
	dp[0][0][0] = 0;
	for(int i=1;i<=N;i++){
		for(int ta=0;ta<450;ta++){
			for(int tb=0;tb<450;tb++){
				//i番目の薬品を使わなかった場合
				dp[i][ta][tb] = min(dp[i][ta][tb],dp[i-1][ta][tb]);
				//i番目の薬品を使った場合
				if(ta+a[i-1] < 450 && tb+b[i-1] < 450){
					dp[i][ta+a[i-1]][tb+b[i-1]] = 
					min(dp[i][ta+a[i-1]][tb+b[i-1]],dp[i-1][ta][tb] + c[i-1]);
				}
			}
		}
	}
	int ans = inf;
	for(int i=1;i<=400;i++){
		if(Ma*i>=450 || Mb*i >=450)break;
		ans = min(ans,dp[N][Ma*i][Mb*i]);
	}
	if(ans<inf)cout << ans << endl;
	else cout << -1 << endl;
}