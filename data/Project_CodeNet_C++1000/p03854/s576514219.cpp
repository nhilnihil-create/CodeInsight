#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());
	string d[4] = {"dream", "dreamer", "erase", "eraser"};
	rep(i,4) reverse(d[i].begin(), d[i].end());
	string t = "";
	rep(i,n) {
		rep(j,4) {
			if (t.size() + d[j].size() > n) continue;
			if (s.substr(i,d[j].size())==d[j]) {
				t += d[j];
				i += d[j].size()-1;
			}
		}
	}
	if (s == t) cout << "YES" << endl;
	else cout << "NO" << endl; 
	return 0;
}