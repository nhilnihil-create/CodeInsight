#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

typedef long long ll;
ll M = 1e9 + 7;
ll n, a[N];
ll s = 0, k = 0, h, cnt, u;
int main()
{
	ll i, j, w;
//	freopen ("input.txt", "r", stdin);
	cin >> n;
	for (i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
	}
	i = 1;
	s = 1;
	h = -1;
	u = n;
	w = 0;
	while (i <= n) {
		for (; i <= n; i++) {
			h += 2;
			if (h + k > a[i]) break;
		}
		i++;
		if(i > n) {
			for (j = 2; j <= u; j++) {
				s = (s * j) % M;
			}
		} else {
			cnt = (i - 1) - w;
			s = (s * cnt) % M;
		}
		k -= 2;
		u--;
		w++;
	}
    cout << s << endl;
    return 0;
}
