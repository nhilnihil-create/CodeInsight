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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 2000






int main() {
	int a[N];
	f(i, N)a[i] = 0;
	int n, x, mi, ma;
	bool v = true;
	scanf("%d", &n);
	mi = n;
	ma = 0;
	f(i, n) {
		scanf("%d", &x);
		a[x]++;
		mi = min(mi, x);
		ma = max(ma, x);
	}
	if (ma % 2 == 0) {
		if (ma != (2 * mi))v = false;
		if (a[mi] != 1)v = false;
		for (int i = mi + 1; i <= ma; i++) {
			if (a[i] < 2)v = false;
		}
	}
	else {
		if (ma != (2 * mi - 1))v = false;
		if (a[mi] != 2)v = false;
		for (int i = mi + 1; i <= ma; i++) {
			if (a[i] < 2)v = false;
		}
	}
	if(v)printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}