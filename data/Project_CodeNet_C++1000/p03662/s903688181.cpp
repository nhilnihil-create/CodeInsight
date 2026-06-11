#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;

int n, a, b, cnt;
pair<int, bool>f[100000], s[100000];
vector<int>g[100000];

int dfsf(int x) {
	lp(g[x].size()) {
		if (!f[g[x][i]].second) {
			f[g[x][i]] = make_pair(f[x].first + 1, true);
			dfsf(g[x][i]);
		}
	}
	return 0;
}

int dfss(int x) {
	lp(g[x].size()) {
		if (!s[g[x][i]].second) {
			s[g[x][i]] = make_pair(s[x].first + 1, true);
			dfss(g[x][i]);
		}
	}
	return 0;
}




int main() {
	cin >> n;
	lp(n-1) {
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	lp(n)
		f[i].second = s[i].second = false;
	f[0] = s[n - 1] = make_pair(0, true);
	dfsf(0);
	dfss(n-1);
	cnt = 0;
	lp(n) {
		if (f[i].first <= s[i].first)cnt++;
		else cnt--;
	}
	if (cnt > 0)cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
	return 0;
}