#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;
typedef long long ll;
ll inf = 100000000;
ll v[205];
ll x[20000005];
ll a[10000005];
ll b[10000005];
ll dp[10005][10005];
ll ex = 1000000007;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
typedef pair<ll, ll> P;
double q[200005];
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ll n, m;
	cin >> n >> m;
	if (n*2 >= m) {
		cout << m / 2<< endl;
		return 0;
	}
	else {
		ll count = n;
		m -= 2* n;
		count += m / 4;
		cout << count << endl;
		return 0;
	}
}