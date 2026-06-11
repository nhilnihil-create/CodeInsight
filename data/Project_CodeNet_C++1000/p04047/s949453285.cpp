#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define F0R(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define sz (int)size
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MX = 200;

int N, a[MX];

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}


int main() {
	cin >> N;
	F0R(i, 2 * N) cin >> a[i];
	sort(a, a + 2 * N);

	int ans = 0;
	for (int i = 0; i < 2 * N; i += 2) {
		ans += a[i];
	}

	cout << ans << "\n";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)