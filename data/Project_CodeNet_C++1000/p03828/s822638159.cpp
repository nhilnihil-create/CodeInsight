#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

map<int, int> m;
void find(int n) {
	for(int i = 2; i <= n; ++i) {
		if(n % i == 0) {
			n /= i;
			m[i]++;
			i--;
			}
		}
}

void solve() {
	int n;
	cin >> n;
	for(int i = n; i > 0; --i) find(i);
	ll ans = 1;
	for(auto x : m) (ans *= (x.second + 1)) %= mod;
	cout << ans << endl;
}
	

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
