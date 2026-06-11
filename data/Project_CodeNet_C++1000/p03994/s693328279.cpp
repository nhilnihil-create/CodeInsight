#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int k;
	cin >> s >> k;
	auto cal = [&](char c) {
		int p = c - 'a';
		return 25 - p + 1;
	};
	int n = s.size();
	rep(i, n) {
		if (s[i] == 'a') continue;
		if (cal(s[i]) <= k) {
			k -= cal(s[i]);
			s[i] = 'a';
		}
	}
	k %= 26;
	int np = s[n - 1] - 'a';
	np += k;
	s[n - 1] = char(np + 'a');
	cout << s << endl;
	return 0;
}