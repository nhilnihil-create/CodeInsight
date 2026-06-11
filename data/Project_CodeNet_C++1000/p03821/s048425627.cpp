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
const ll inf = 1e18 + 7;
const int N = 3e5 + 17;

int n, m;
int x[N], y[N], r[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	reverse(x, x + n), reverse(y, y + n);

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		r[i] = (y[i] - (x[i] + cur) % y[i]) % y[i];
		cur += r[i];
	}
//	for (int i = 0; i < n; i++) cout << x[i] << " " << y[i] << " " << r[i] << endl;
	cout << cur << endl;
}