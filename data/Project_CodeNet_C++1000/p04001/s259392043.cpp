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

	if (n == 1) {
		cout << stoi(s) << endl;
		return 0;
	}
	ll ans = 0;
	rep(t,1<<(n-1)) {
		int las = 0;
		rep(i,n-1) {
			if ((t>>i) & 1) {
				string sub = s.substr(las,i-las+1);
				ans += stoll(sub);
				las = i+1;
			}
		}
		ans += stoll(s.substr(las,n-las));
	}
	cout << ans << endl;
	return 0;
}