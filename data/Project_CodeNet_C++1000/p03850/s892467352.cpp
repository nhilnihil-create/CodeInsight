//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef long double ld ;

#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define IO ios_base::sync_with_stdio(false);
#define sz(a) (int)(a.size())
#define sg(a, b) (a + b - 1) / b

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 8 * 1000 * 1000 + 200;
const int MAXN =  100 * 1000 + 1;
const int MLOG = 18;
const int NMAX = 20;

vector<int> prime;

int is_p(int a){
	for(int i : prime)
		if(a % i == 0) return false;
	return true;
}

signed main(){
	IO;
	int dp[MAXN][3]; // dp[i][b] mishavad marhaleye i om ba b ta parntez baz
	int n;
	cin >> n >> dp[0][0];
	dp[0][2] = dp[0][1] = - INF * INF;
	for(int i = 1; i < n; i++){
		char op;
		int a;
		cin >> op >> a;
		if(op == '-'){
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) - a;
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]) + a;
			dp[i][0] = max({dp[i - 1][0] - a, dp[i][1], dp[i][2]});
			//cout << '-';
		}else{
			dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a;
			dp[i][1] = dp[i - 1][1] - a;
			dp[i][2] = dp[i - 1][2] + a;
			//cout << '+';
		}
		//cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
	}
	cout << dp[n - 1][0];
}