// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int A[N], D[N];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	ll s = 0;
	for (int i = 0; i < n; i++) cin >> A[i], s += A[i];
	A[n] = A[0];
	for (int i = 0; i < n; i++) D[i] = A[i + 1] - A[i];
	if (s % (1LL * n * (n + 1) / 2) != 0) die("NO");
	ll k = (2 * s) / (1LL * n * (n + 1));
	for (int i = 0; i < n; i++) if (k < D[i] || (k - D[i]) % n != 0) die("NO");
	cout << "YES" << endl;

	return 0;
}
