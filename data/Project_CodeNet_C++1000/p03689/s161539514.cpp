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
 
int n, m, n1, m1;
/*int a[N];
int sum[55][55];
const int LIM = 2;

int sub (int lx, int ly, int rx, int ry) {
	int res = sum[rx][ry];
	if (lx >= 0) res -= sum[lx][ry];
	if (ly >= 0) res -= sum[rx][ly];
	if (lx >= 0 && ly >= 0) res += sum[lx][ly];
	return res;
}

void gen (int p = 0) {
	if (p == n * m) {         
		int ptr = 0;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				int &res = sum[i][j];
				res = 0;
				if (i > 0) res += sum[i-1][j];
				if (j > 0) res += sum[i][j-1];
				if (i > 0 && j > 0) res -= sum[i-1][j-1];
				res += a[ptr ++];
			}
		}

		ptr = 0;
		for (int i = n1 - 1; i < n; i ++) {
			for (int j = m1 - 1; j < m; j ++) if (sub(i - n1, j - m1, i, j) >= 0) {
				return;
			}
		}
		if (sum[n-1][m-1] <= 0) return;

		cout << "varient\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << a[ptr++] << ' ';
			}
			cout << '\n';
		}
		exit(0);

		return;
	}
	for (int i = -LIM; i <= LIM; ++i) {
		a[p] = i;
		gen(p+1);
	} 	
}
*/
int main () {
	SpeedForce;
	cin >> n >> m >> n1 >> m1;
//	gen();
	if (n % n1) {
		cout << "Yes\n";
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; ++j) {
				if (i % n1 == 0) cout << 1000 * (n1 - 1) - 1 << ' ';
				if (i % n1) cout << "-1000 "; 
			}
			cout << endl;
		}
		exit(0);
	}
	if (m % m1) {
		cout << "Yes\n";
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; ++j) {
				if (j % m1 == 0) cout << 1000 * (m1 - 1) - 1 << ' ';
				else cout << "-1000 "; 
			}
			cout << endl;
		}
		exit(0);
	}

	cout << "No\n";

   	return Accepted;
}

// B...a