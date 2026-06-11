#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
ll h, w, n, a, b, c[15], E=1e9;
map<ll,ll> mp;
int main() {
	ll i, j, k;
	scanf("%d%d%d", &h, &w, &n);
	c[0] = (h-2) * (w-2);
	while(n--) {
		scanf("%d%d", &a, &b);
		for(i=a; i<a+3; i++) for(j=b; j<b+3; j++) {
			if(i>2 && j>2 && i<=h && j<=w) {
				k = mp[i*E+j]++;
				c[k]--; c[++k]++;
			}
		}
	}
	for(i=0; i<=9; i++) printf("%lld\n", c[i]);
	return 0;
}