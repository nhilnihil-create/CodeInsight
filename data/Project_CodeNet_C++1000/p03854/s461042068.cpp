#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)


constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s; cin >> s;
	reverse(s.begin(), s.end());
	string t[4] = { "maerd", "remaerd", "esare", "resare" };

	while (s.size()) {
		int sz = s.size();

		rep(i, 0, 4) {
			if (s.size() < t[i].size()) continue;
			bool match = true;
			rep(j, 0, t[i].size())  if (s[j] != t[i][j]) match = false;
			if (match) s.erase(0, t[i].size());
		}

		if (s.size() == sz) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}