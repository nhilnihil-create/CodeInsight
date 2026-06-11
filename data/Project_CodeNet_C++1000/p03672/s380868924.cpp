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
	auto judge = [&](string t) {
		if ((int)t.size() % 2 != 0) return false;
		bool ok = true;
		for (int i = 0; i < (int)t.size() / 2; ++i) {
			if (t[i] != t[i + (int)t.size() / 2]) ok = false;
		}
		return ok;
	};
	for (int i = n - 2; i >= 1; --i) {
		if (judge(s.substr(0, i))) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}