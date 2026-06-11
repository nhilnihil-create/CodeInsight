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

int n, x, u[N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n >> x;

	if (x == 1 || x == n + n - 1) {
		cout << "No";
		return 0;
	}

	cout << "Yes" << endl;

	if (n == 2) {
		cout << "1\n2\n3\n";
		return 0;
	}

	if (x == 2)
		u[x] = u[x - 1] = u[x + 1] = u[x + 2] = 2;
	else
		u[x] = u[x - 1] = u[x + 1] = u[x - 2] = 2;

	for (int i = 1, ptr = 1; i < n - 1; i++) {
		while (u[ptr]) ptr++;
		u[ptr] = 1;
		cout << ptr << '\n';
	}

	if (x == 2)
		cout << x + 2 << '\n' << x << '\n' << x - 1 << '\n' << x + 1 << '\n';
	else
		cout << x - 2 << '\n' << x << '\n' << x + 1 << '\n' << x - 1 << '\n';

	for (int i = 1, ptr = 1; i < n - 2; i++) {
		while (u[ptr]) ptr++;
		u[ptr] = 1;
		cout << ptr << '\n';
	}
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
