#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
 
using namespace std;


void solve()
{
	int n, K;
	scanf("%d%d", &n, &K);
	vector<int> a(n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ll min = LINF;
	int j;
	for (i = 1; i < (1<<n); i+=2) {
		int cnt = 0;
		ll sum = 0;
		int curr = -1;
		for (j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cnt++;
				if (curr < a[j]) {
					curr = a[j];
				}
				else {
					sum += (curr + 1 - a[j]);
					curr++;
				}
			}
			else {
				curr = MAX(curr, a[j]);
			}
		}
		if (cnt >= K) {
			min = MIN(min, sum);
		}
	}
	printf("%lld\n", min);

    return;
}


int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
