#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define F0R(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define sz (ll)size
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define f first
#define s second

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}


int main() {
	ll N, B;
	cin >> N >> B;

	cout << 3 * (N - __gcd(N, B)) << "\n";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?)