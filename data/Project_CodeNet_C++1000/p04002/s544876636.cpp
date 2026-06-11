#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000


int main() {
	long long a[N];
	long long b[N];
	long long c[10];
	f(i, 10)c[i] = 0;
	set<pair<long long,long long> >s;
	set<pair<long long, long long> >u;
	f(i, N)a[i] = 0;
	long long n, k;
	long long x, y, z, xx, yy;
	scanf("%lld %lld %lld", &xx, &yy ,&n);
	f(i, n) {
		scanf("%lld %lld", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		s.insert(make_pair(a[i], b[i]));
	}
	c[0] = (xx - 2)*(yy - 2);
	f(i, n) {
		for (long long ii = -2; ii < 3; ii++) {
			for (long long jj = -2; jj < 3; jj++) {
				x = a[i] + ii;
				y = b[i] + jj;
				if ((x >= 0) && (y >= 0) && ((x + 2) < xx) && ((y + 2) < yy)) {
					if (u.count(make_pair(x, y)) == 0) {
						k = 0;
						f(iii, 3) {
							f(jjj, 3) {
								if (s.count(make_pair(x + iii, y + jjj)) == 1)k++;
							}
						}
							c[0]--;
							c[k]++;
						u.insert(make_pair(x, y));
					}
				}
			}
}
	}
	f(i,10)printf("%lld\n", c[i]);


	return 0;
}