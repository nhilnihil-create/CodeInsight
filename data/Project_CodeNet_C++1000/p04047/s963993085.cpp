#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<19, mlg = 18, rt = 1<<10, mod = 1e9 + 7;
using ld = long double;
using pi = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;n<<=1;
	vi a(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	ll ans = 0;
	for(int i = 0; i < n; i+=2) ans += a[i];
	cout << ans;
} 
