#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

const ll MOD = 1e9 + 7;
const ll INF = 9e18;
const double eps = -1e10;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second


int nextit[30], dp[200010];
string s;
vector<pair<char, int>>ans;

int main() {
	cin >> s;
	fill(dp, dp + (int)s.size() + 2, 1000000);
	fill(nextit, nextit + 26, s.size() + 1);
	dp[s.size()] = 1;
	dp[s.size() + 1] = 0;
	ans.resize((int)s.size() + 2);
	ans[(int)s.size()] = make_pair('a', s.size() + 1);
	for (int i = s.size();i >= 0;i--) {
		for (int j = 0;j < 26;j++) {
			if (dp[nextit[j]] + 1 >= dp[i])continue;
			ans[i] = make_pair('a' + j, nextit[j]);
			dp[i] = dp[nextit[j]] + 1;
		}
		if (i)nextit[s[i - 1] - 'a'] = i;
	}
	string an;
	for (int i = 0;i < s.size() + 1;) {
		an += ans[i].fr;
		i = ans[i].sc;
	}
	cout << an << endl;
	return 0;
}
