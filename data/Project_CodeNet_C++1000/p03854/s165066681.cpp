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
	reverse(s.begin(), s.end());
	vector<string> d = { "maerd","remaerd","esare","resare" };
	int n = s.size();
	string t;
	rep(i, n) {
		for (string c : d) {
			if (c == s.substr(i, c.size())) {
				t += c;
				i += c.size() - 1;
				break;
			}
		}
	}
	if (s == t) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
