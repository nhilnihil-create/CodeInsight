#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

vvi nex;

int main() {

	string s;
	cin >> s;

	int ans = INF;

	bool all = true;
	rep(i, s.size() - 1)if (s[i] != s[i + 1])all = false;
	if (all) { cout << 0 << endl;return 0; }
	
	rep(i, 26) {
		
		char c = 'a' + i;
		string ss = s;
		int cnt = 0;

		while (true) {

			string t = "";
			bool allc = true;
			rep(j, ss.size() - 1) {
				if (ss[j] == c || ss[j + 1] == c)t += c;
				else { allc = false; t += '?'; }
			}
			cnt++;
			if (allc)break;
			ss = t;
			
		}

		ans = min(ans, cnt);


	}

	cout << ans << endl;

}