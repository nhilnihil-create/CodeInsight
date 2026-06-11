
#include <iostream>
#include <cstdio>
#include <map>
#define PII pair<ll, ll>
#define F first
#define S second
using namespace std;

typedef long long ll;
ll h, w, n, c[15];
PII t;
map<PII, ll> m;
int main()
{
	ll i, j, t1, t2, t3;
	cin >> h >> w >> n;
	c[0] = (h - 2) * (w - 2);
	while (n--) {
		scanf("%lld %lld", &t1, &t2);
		for (i = t1; i < t1 + 3; i++) {
			for (j = t2; j < t2 + 3; j++) {
				if (i > 2 && j > 2 && i <= h && j <= w) {
					t.F = i, t.S = j;
					t3 = m[t]++;
					c[t3]--, c[t3 + 1]++;
				}
			}
		}
	}
	for (i = 0; i <= 9; i++) printf("%lld\n", c[i]);
    return 0;
}