#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

int dp[202020];

int main() {
	string s;
	cin >> s;
	int n = s.size();
	map<int,vector<int>>mp;
	rep(i, 0, s.size())mp[s[i]-'a'].pb(i);
	rep(i, 0, 202020)dp[i] = 303030;

	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		rep(j, 0, 26) {
			if (mp[j].size() == 0 || mp[j][mp[j].size()-1] < i) {
				dp[i] = 1;
			}
			else {
				int nxt = *lower_bound(all(mp[j]), i);
				dp[i] = min(dp[i],dp[nxt+1]+1);
			}
		}
	}

	string ans;
	int cur = 0;
	while (ans.size() < dp[0]) {
		rep(j, 0, 26) {
			auto tmp = mp[j];
			if (tmp.size() == 0 || tmp.back() < cur) {
				ans += 'a' + j;
				break;
			}
			else {
				int idx = tmp[lower_bound(all(tmp), cur) - tmp.begin()];
				if (dp[cur] == dp[idx + 1] + 1) {
					ans += 'a' + j;
					cur = idx + 1;
					break;
				}
			}
		}
	}
	puts(ans);


	return 0;
}
