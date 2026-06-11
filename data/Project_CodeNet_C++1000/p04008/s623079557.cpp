#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ll long long

const int N = 1e5+11;
int n, k, a[N], res, d[N], p[N], bio[N];
vector <int> ls[N];
set <pair <int, int> > s;

void dfs (int x, int mama, int dubina) {
	p[x] = mama;
	d[x] = dubina;
	if (ls[x].size() == 1) {
		s.insert(mp(-dubina, x));
	}
	for (int i=0;i<ls[x].size();i++) {
		if (ls[x][i] == mama) continue;
		dfs (ls[x][i], x, dubina+1);
	}
}

void gore (int x, int kol) {
	if (bio[x]) return;
	bio[x] = 1;
	if (kol == 0) {
		s.insert(mp(-d[p[x]], p[x]));
		res++;
		return;
	}
	gore (p[x], kol-1);
}

int main() {
	cin >> n >> k;
	for (int i=0;i<n;i++) {
		scanf ("%d", &a[i]);
		a[i]--;
		if (i != 0) {
			ls[i].pb(a[i]);
			ls[a[i]].pb(i);
		}
	}
	if (a[0] != 0) res++;
	dfs (0, 0, 0);
	while (!s.empty()) {
		int x = s.begin()->ss;
		int depth = -s.begin()->ff;
		if (depth <= k) break;
		gore(x, k-1);
		s.erase(s.begin());
	}
	cout << res;
	return 0;
}