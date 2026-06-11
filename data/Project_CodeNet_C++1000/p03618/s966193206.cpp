#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	map<char, ll> mp;
	ll n = s.size();
	rep(i, n) {
		mp[s[i]]++;
	}
	ll res = 0;
	for (auto& c : mp) {
		res += c.second * (c.second - 1) / 2;
	}
	ll ans = n * (n - 1) / 2 - res + 1;
	dunk(ans);
	return 0;
}
