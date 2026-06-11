#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
 
#define cmp_all(X) (X).begin(), (X).end(), cmp
 
#define B begin()
#define E end()
#define sz size()
#define skip continue
 
#define ppi pair<pair<int, int>, int>
#define pii pair<int, int> 
#define pli pair<ll, int>
 
#define F first
#define S second
 
using namespace std;
 
const int maxn = 1e7 + 17;
const int MAXN = maxn * 4;
const int darr = 1e3 + 17;
const ll INF = 1e17 + 5;
const int mod = 1e9 + 7;
 
void Need_For_Speed () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

ll n, x;

ll get (ll n, ll x) {
	if (n % x == 0) {
		return ((n / x) * x) * 2 - x;
	}
	return (((n - (n % x)) / x) * x) * 2 + get(x, n % x);
}

int main () {
	Need_For_Speed();
	cin >> n >> x;
	cout << get(n - x, x) + n;
	return 0;
}