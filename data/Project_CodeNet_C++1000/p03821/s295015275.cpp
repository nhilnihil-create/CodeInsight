#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
char map[505][505];
int def[505][505];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int>to[200005];
ll a[100005];
ll b[100005];

ll keisan(ll x,ll y) {
	if (x % y == 0) {
		return 0;
	}
	ll k = x / y+1;
	return  y * k - x;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	ll sum = 0;
	ll ans = 0;
	for (int i = n - 1; i > 0; i--) {
		ll x;
		x= keisan(a[i], b[i]);
		ans += x;
		sum += x;
		a[i - 1] += sum;
	}
	cout << ans + keisan(a[0],b[0])<< endl;
	return 0;
}
	
	