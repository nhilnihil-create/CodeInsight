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
int a[N], b[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
	ll ans = 0;
	for (int i = 0; i < n; i++) ans += a[i];
	auto cur = ans;
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n; i++) {
			int pr = (i + n - 1) % n;
			if (a[i] > b[pr]) {
				cur += b[pr] - a[i];
				a[i] = b[pr];
			}
		}
		for (int i = 0; i < n; i++) b[i] = a[i];
		ans = min(ans, cur + j * x);
	}
	cout << ans;	
}
