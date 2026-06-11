#include <bits/stdc++.h>
#define REP(a, b) for(int a = 0; a < b; a++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair
#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//shuffle(permutation.begin(), permutation.end(), rng);
//uniform_int_distribution<int>(l, r)(rng);
int n, k;
bool sudah[MAXN];
int A[MAXN], res;
vi v;

void dfs(int now) {
	sudah[now] = 1;
	if (now == 1) {
		v.pb(now);	
		return;
	}
	if (!sudah[A[now]]) dfs(A[now]);
	v.pb(now);
}

int DP[MAXN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	FOR(i, 1, n) cin >> A[i];
	if (A[1] != 1) {
		A[1] = 1; res++;
	}
	FOR(i, 1, n) if (!sudah[i]) dfs(i);
	reverse(v.begin(), v.end());
	REP(i, v.size() - 1) {
		int now = v[i];
		if (DP[now] == k - 1) {
			if (A[now] == 1);
			else {
				A[now] = 1;
				res++;
			}
		}
		else {
			DP[A[now]] = max(DP[A[now]], DP[now] + 1);
		}
	}
	cout << res << '\n';
}