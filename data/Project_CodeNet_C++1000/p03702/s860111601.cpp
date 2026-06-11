# include <bits/stdc++.h>

using namespace std;
#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n;
int x, y;
int a[N];
int b[N];

inline bool check (int cur) {

	for (int i = 1; i <= n; i ++) {
		if (a[i] > cur * (ll)y) {
			b[i] = a[i] - cur * y;
		} else {
			b[i] = 0;
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i ++) {
		sum += (b[i] + x - 1) / x;
		if (sum > cur) return 0;
	}
	return 1;
}


int main () {
	SpeedForce;
	cin >> n >> x >> y;
	x -= y;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	int l = 0, r = *max_element(a + 1, a + n + 1) / y + 1;

	while (r - l > 1) {
		int md = (l + r) >> 1;
		if (check(md)) r = md;
		else l = md;
	}

	cout << r << '\n';

   	return Accepted;
}

// B...a