#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <cstring>
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define RREP(i,n) for(int i=1; i<=(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> P; 
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

vector<vector<int>> calcNext(const string &S)
{
	int n = S.size();
	vector<vector<int>> ret(n + 2, vector<int>(26, n + 1));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) ret[i][j] = ret[i + 1][j];
		ret[i][S[i] - 'a'] = i;
	}
	return ret;
}

void solve()
{
	string S; cin >> S;
	int n = S.size();
	auto next = calcNext(S);

	vector<int> dp(n + 1, INF);
	vector<int> rc(n + 1, 'a');

	//calc dp
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			if (next[i][j] == n + 1) {
				if (dp[i] > 1) {
					dp[i] = 1;
					rc[i] = j + 'a';
				}
			}
			else {
				if (dp[i] > dp[next[i][j] + 1] + 1) {
					dp[i] = dp[next[i][j] + 1] + 1;
					rc[i] = j + 'a';
				}
			}
		}
	}

	//recovery
	string ans = "";
	int ind = 0;
	while (ind <= n) {
		ans += rc[ind];
		ind = next[ind][rc[ind] - 'a'] + 1;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}

