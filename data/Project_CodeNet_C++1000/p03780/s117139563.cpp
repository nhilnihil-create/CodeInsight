#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define all(v) begin(v), end(v)
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = (int)1e9;
const ll inf = (ll)1e18;
const ll MOD{ (ll)1e9 + 7 };

int n, k;
bool dp[5050][5050]; //dp[i][j]: i枚目まで使ったとき総和をjにできるか
vector<int> v;

bool check(int x) { //xが必要か不要か
	int n = (int)v.size();
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;

	rep(i, n) {
		rep(j, k) {
			dp[i + 1][j] = dp[i + 1][j] || dp[i][j];
			if (j + v[i] < k && dp[i][j] && x != i) dp[i + 1][j + v[i]] = true;
		}
	}

	rep(j, k) {
		if (dp[n][j] && j + v[x] >= k) return true; //必要
	}
	return false; //不要
}

int main()
{
	cin >> n >> k;
	rep(i, n) {
		int a;
		cin >> a;
		if (a < k) v.push_back(a); //k未満のa
	}
	sort(v.begin(), v.end());
	
	int ok = (int)v.size(), ng = -1; //にぶたん(どこまでが不要か)
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (check(mid)) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	cout << ng + 1 << endl;
	return  0;
}