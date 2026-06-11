#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 200500;

ll ans;
stack < int > st;
int n, p[N], l[N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n;

	st.push(0);

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		while (!st.empty() && p[st.top()] > p[i])
			st.pop();
		l[i] = st.top();
		st.push(i);
	}

	while (!st.empty())
		st.pop();
	st.push(n + 1);

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && p[st.top()] > p[i])
			st.pop();
		ans += p[i] * (st.top() - i + 0ll) * (i - l[i] + 0ll);
		st.push(i);
	}

	cout << ans;
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
