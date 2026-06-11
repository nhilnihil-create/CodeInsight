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
int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	vi w;
	for (int i = 0; i < n; i++) cin >> a[i], w.pb(a[i]);
	sort(all(w));
	for (int i = 0; i < n; i++) a[i] = lower_bound(all(w), a[i]) - w.begin();
	int ans = 0;
	for (int i = 0; i < n; i += 2)
		if (a[i] & 1) ans++;
	cout << ans;
}
