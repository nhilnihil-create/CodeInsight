#include <bits/stdc++.h>
using namespace std;

#define FORE(i, a) for (auto i = a.begin(); i != a.end(); ++i)
#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

vector<string> split(const string &s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c)) v.push_back(x);
	return v;
}

#define DEBUG(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

void err(vector<string>::iterator it) {}

template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << "[DEBUG] " << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) { return (a < b) ? a : b; }
template<class T, class U> inline T tmax(T a, U b) { return (a > b) ? a : b; }
template<class T, class U> inline void amax(T &a, U b) { if (b > a) a = b; }
template<class T, class U> inline void amin(T &a, U b) { if (b < a) a = b; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

const int N = 100005;
vector<int> g[N];

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	REPU(i, 0, n) {
		int x; cin >> x;
		g[x % m].push_back(x);
	}
	REPU(i, 0, m) if (!g[i].empty()) {
		sort(ALL(g[i]));
	}
	int ans = 0;
	REPU(i, 0, m / 2 + 1) {
		int r = (m - i) % m;
		if (i != r) {
			ans += tmin(g[i].size(), g[r].size());
			if (g[i].size() > g[r].size()) {
				int t = g[i].size(), cnt = 0;
				for (int j = 0; j < g[i].size();) {
					int nxt = upper_bound(ALL(g[i]), g[i][j]) - g[i].begin();
					cnt += (nxt - j) / 2;
					j = nxt;
				}
				ans += tmin((g[i].size() - g[r].size()) / 2, cnt);
			}
			else if (g[i].size() < g[r].size()) {
				int cnt = 0;
				for (int j = 0; j < g[r].size();) {
					int nxt = upper_bound(ALL(g[r]), g[r][j]) - g[r].begin();
					cnt += (nxt - j) / 2;
					j = nxt;
				}
				ans += tmin((g[r].size() - g[i].size()) / 2, cnt);
			}
		}
		else {
			ans += g[i].size() / 2;
		}
	}
	cout << ans << endl;

	return 0;
}
