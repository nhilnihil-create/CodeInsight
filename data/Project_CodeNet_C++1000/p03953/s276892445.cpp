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
#define N 200010






int main() {
	long long n, m, k;
	long long ss;
	vector<long long>d;
	vector<long long>ans;
	vector<long long>a;
	vector<long long>b;
	vector<bool>used;
	long long x, y;
	scanf("%lld", &n);
	f(i, n) {
		scanf("%lld", &x);
		d.push_back(x);
	}
	ss = d[0];
	f(i, n - 1)d[i] = d[i + 1] - d[i];
	f(i, n - 1)a.push_back(i);
	scanf("%lld %lld", &m, &k);
	f(i, m) {
		scanf("%lld", &x);
		swap(a[x - 2], a[x - 1]);
	}
	f(i, n - 1) {
		ans.push_back(0);
		used.push_back(false);
	}
	f(i, n - 1) {
		if (!used[i]) {
			b.clear();
			b.push_back(i);
			used[i] = true;
			y = 1;
			x = a[i];
			while (x != i) {
				b.push_back(x);
				used[x] = true;
				y++;
				x = a[x];
			}
			f(j, y) {
				x = (j + k) % y;
				ans[b[j]] = d[b[x]];
			}
		}
	}
	x = ss;
	printf("%lld\n", x);
	f(i, n - 1) {
		x += ans[i];
		printf("%lld\n", x);
	}

	return 0;
}
