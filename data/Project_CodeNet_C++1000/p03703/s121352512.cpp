// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;

#define int ll
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9;
const int MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 2e5 + 5;

int A[N], FEN[N];
ll PS[N];

void Add(int p, int x = 1) { for (p++; p < N; p += p & -p) FEN[p] += x; }
int Get(int p) {
	int sum = 0;
	for (; p > 0; p -= p & -p) sum += FEN[p];
	return sum;
}

int32_t main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k, ans = 0; cin >> n >> k;
	vector<int> comp; comp.push_back(0);
	for (int i = 1; i <= n; i++) cin >> A[i], PS[i] = PS[i - 1] + A[i];
	for (int i = 1; i <= n; i++) PS[i] -= 1LL * i * k, comp.push_back(PS[i]);
	sort(all(comp));
	comp.resize(unique(all(comp)) - comp.begin());
	for (int i = 0; i <= n; i++) PS[i] = lower_bound(all(comp), PS[i]) - comp.begin();
	Add(PS[0]);
	for (int i = 1; i <= n; i++) {
		ans += Get(PS[i] + 1);
		Add(PS[i]);
	}
	cout << ans << endl;

	return 0;
}
