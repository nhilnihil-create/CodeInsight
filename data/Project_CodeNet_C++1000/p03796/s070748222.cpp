#include <bits/stdc++.h>
using namespace std;
#define ar array
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const ll mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int mxN = 1e5;
ll dp[mxN + 1];
ll fac(ll n) {
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
		dp[i] = (dp[i-1] * i) % mod;
	return dp[n];
}

int main() {
	ll n;
	cin >> n;
	cout << fac(n) << endl;
    return 0;
}

