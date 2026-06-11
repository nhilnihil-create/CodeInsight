#include <bits/stdc++.h>
using namespace std;
#define ar array
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef double db;
const ll mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	if(n > m/2) cout << m/2 << endl;
	else {
		ll y = n+n;
		ll t = m-y;
		ll k = ceil(t/4);
		cout << k + n << endl;
	}
    return 0;
}

