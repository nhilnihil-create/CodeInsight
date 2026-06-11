#include <bits/stdc++.h>

#define fio() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<pi, ll> pii;

const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 6;
const ll N = 1e2 + 2;
const ll inf = 1e12;
const ld eps = 1e-6;

ll n, x;

int main() {
	fio();
	cin >> n >> x;
	cout << 3 * (n - __gcd(n, x)) << endl;
	return 0;
}
