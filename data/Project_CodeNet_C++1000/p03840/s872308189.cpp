#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 1<<20, mod = 924844033;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll i, o, t, j, l, s, z;
	cin >> i>> o >> t >> j >> l >> s >> z;
	ll o1 = o;
	o += (i/2)*2 + 2*(j/2) + 2*(l/2);
	o += 3*(i&j&l&1);
	if(i&&j&&l) o1 += 3, i--,j--,l--;
	o1 += (i/2)*2 + 2*(j/2) + 2*(l/2);
	cout << max(o, o1);
}
