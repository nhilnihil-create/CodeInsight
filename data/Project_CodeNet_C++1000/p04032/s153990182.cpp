#include <bits/stdc++.h>
using namespace std;

#define sz(x) static_cast<int>((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ld = long double;

template<class T> bool cmn(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool cmx(T &a, T b) { return a < b ? (a = b, true) : false; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string inp;
	cin >> inp;
	int ans1 = -1, ans2 = -1;
	for(int i = 0; i + 1 < sz(inp); ++i) {
		if(inp[i] == inp[i + 1]) {
			ans1 = i + 1;
			ans2 = i + 2;
			break;
		}
	}
	if(ans1 == -1) {
		for(int i = 0; i < sz(inp) - 2; ++i) {
			if(inp[i] == inp[i + 2]) {
				ans1 = i + 1;
				ans2 = i + 3;
				break;
			}
		}
	}
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}