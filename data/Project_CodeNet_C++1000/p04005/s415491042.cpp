#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<20, mod = 924844033;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll a, b, c;
	cin >> a >> b >> c;
	if(a&b&c&1) cout << min({a*b, b*c, c*a});
	else cout << 0;
}
