#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()
#define re return
#define mp make_pair
#define makeunique(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<string> vs;

template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }

const double pi = acos(-1.);
const int mod = 1e9 + 7;
const int N = 3e5 + 17;

int n, m;
int a[N], up[N][25];

int get(int l, int r) {
	int ans = 0;
	for (int i = 19; i >= 0; i--) {
	    int p = up[r][i];
//		cout << i << " " << r << " " << p << endl;
	    if (p > l) {
	    	ans += (1 << i);
	    	r = p;
	    }
	}
	return ans + 1;	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int l = 0, L; cin >> L;
	for (int i = 0; i < n; i++) {
		while (a[i] - a[l] > L) l++;
		up[i][0] = l;
		for (int j = 1; j < 20; j++)
			up[i][j] = up[up[i][j - 1]][j - 1];
	}
	cin >> m;
	while (m--) {
		int l, r; cin >> l >> r;
		l--; r--;
		if (r < l) swap(l, r);
		cout << get(l, r) << endl;
	}
}
