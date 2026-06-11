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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//shuffle(permutation.begin(), permutation.end(), rng);
//uniform_int_distribution<int>(l, r)(rng);

ll rek(ll a, ll b) {
	if (b == 0) return -a;
	ll now = 2 * (a / b) * b + rek(b , a % b);
	return now; 
}

ll n, x;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x;
	cout << n + rek(n - x, x) << '\n';
}