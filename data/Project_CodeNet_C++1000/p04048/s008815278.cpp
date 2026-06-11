#include <bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
#define MP make_pair
#define ld long double
 
using namespace std;
 
const int N = 1e5 + 12;
const ll mod = 1e9 + 7;

int dp[N], a[N], n;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
    ll n, x;
    cin >> n >> x;
    ll res = 3 * (n - __gcd(n, x));
    cout << res;
}