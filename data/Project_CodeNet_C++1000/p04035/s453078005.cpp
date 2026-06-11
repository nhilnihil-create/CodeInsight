#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<20, mod = 924844033;
ll c[maxn], r[maxn], n, m;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	ll s = 0;
	for(int i = 1; i <= n; i++) cin >> c[i], s += c[i];
	int x = -1;
	for(int i = 1; i < n; i++) if(c[i]+c[i+1] >= m) x = i;
	if(x == -1) return cout << "Impossible", 0;
	cout << "Possible\n";
	for(int i = 1; i < x; i++) cout << i << '\n';
	for(int i = n-1; i > x; i--) cout << i << '\n';
	cout << x << '\n';
}
