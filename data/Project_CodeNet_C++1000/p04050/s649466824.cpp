#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long 
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
 
#define y1 what

using namespace std;
 
const int N = (int) 5e3 + 10;
const int M = (int) 4e6 + 7;
const ll LINF = (ll) 1e18;
const int INF = (int) 1e9 + 7;
const double EPS = (double) 1e-9;
const int mod = 1e9 + 7;

const int nx[4] = {1, -1, 0, 0};
const int ny[4] = {0, 0, 1, -1};

int n, m;
int a[N];
vector<int> v[2];
vector<int> ans;

void print() {
	for (auto it : ans) if (it) cout << it << " ";
	ans[0]--;
	ans[sz(ans) - 1]++;
	if (ans[0] == 0) {
		reverse(all(ans));
		ans.pop_back();
		reverse(all(ans));
	}
	cout << "\n" << sz(ans) << "\n";
	for (auto it : ans) cout << it << " ";
	exit(0);
}

int main() {
    #define fn "balls"
    #ifdef witch
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen(fn".in", "r", stdin);
//        freopen(fn".out", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	cin >> a[i];
    	v[a[i] % 2].pb(a[i]);
    }
    if (m == 1) {
    	ans.pb(a[1]);
    	ans.pb(0);
    	print();
    }
    if (sz(v[1]) > 2) {
    	cout << "Impossible";
    	return 0;
    }
    if (sz(v[1]) == 2) {
    	ans.pb(v[1][0]);
    	for (auto it : v[0]) ans.pb(it);
    	ans.pb(v[1][1]);
    	print();
	}
	if (sz(v[1]) == 1) {
		ans.pb(v[1][0]);
    	for (auto it : v[0]) ans.pb(it);
    	print();
	}
	for (auto it : v[0]) ans.pb(it);
	print();
    return 0;
}