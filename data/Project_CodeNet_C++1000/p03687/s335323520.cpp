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
	cin >> s;
	int n = s.size();
	int ans = inf;
	for (char c = 'a'; c <= 'z'; ++c) {
		vector<int> a(n);
		rep(i, n) a[i] = s[i] == c;
		while (a != vector<int>(a.size(), 1)) {
			vector<int> p(a.size() - 1);
			swap(a, p);
			rep(i, a.size()) a[i] = p[i] | p[i + 1];
		}
		mins(ans, n - (int)a.size());
	}
	cout << ans << endl;
	return 0;
}