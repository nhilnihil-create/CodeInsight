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


int n, k, l, p, q, r, s, cnt, ans[200000], mem;
vector<int>c[200000], t[200000];
pair<pair<int, int>, int>g[200001];
bool vtdc[200000], vtdt[200000];

int dfsc(int x) {
	lp(c[x].size()) {
		if (!vtdc[c[x][i]]) {
			vtdc[c[x][i]] = true;
			g[c[x][i]].first.first = mem;
			dfsc(c[x][i]);
		}
	}
	return 0;
}

int dfst(int x) {
	lp(t[x].size()) {
		if (!vtdt[t[x][i]]) {
			vtdt[t[x][i]] = true;
			g[t[x][i]].first.second = mem;
			dfst(t[x][i]);
		}
	}
	return 0;
}


int main() {
	int n, k, l;
	cin >> n >> k >> l;
	lp(k) {
		cin >> p >> q;
		c[p - 1].push_back(q - 1);
		c[q - 1].push_back(p - 1);
	}
	lp(l) {
		cin >> r >> s;
		t[r - 1].push_back(s - 1);
		t[s - 1].push_back(r - 1);
	}
	lp(n) {
		vtdc[i] = false;
		vtdt[i] = false;
		g[i].second = i;
	}
	lp(n) {
		if (!vtdc[i]) {
			mem = i;
			g[i].first.first = i;
			vtdc[i] = true;
			dfsc(i);
		}
	}
	lp(n) {
		if (!vtdt[i]) {
			mem = i;
			g[i].first.second = i;
			vtdt[i] = true;
			dfst(i);
		}
	}
	sort(g, g + n);
	g[n] = make_pair(make_pair(intmax, intmax), intmax);
	cnt = 1;
	mem = 0;
	lp(n) {
		if (g[i].first == g[i + 1].first) {
			cnt++;
		}
		else {
			for (int j = mem; j <= i; j++) {
				ans[g[j].second] = cnt;
			}
			mem = i + 1;
			cnt = 1;
		}
	}
//	lp(n)cout <<g[i].second<< sp << g[i].first.first << sp << g[i].first.second << endl;
	lp(n-1) {
		cout << ans[i] << sp;
	}
	cout << ans[n - 1] << endl;
	return 0;
}