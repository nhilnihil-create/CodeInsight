#include <bits/stdc++.h>

using namespace std;

#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)


#define LL long long
#define mp make_pair
#define pb push_back
LL max(LL a, LL b) { return (a > b ? a : b); }

#define K 600001

int n, k;
LL a[K], s[K];
LL b[K];

int main() {
	scanf("%d%d", &n, &k);
	FOE(i, 1, n) scanf("%lld", &a[i]);
	FOE(i, 1, n) s[i] = s[i - 1] + a[i];
	FOE(i, 1, n) b[i] = b[i - 1] + max(0, a[i]);
	
	LL ret = s[n];
	
	FOE(i, 1, n - k + 1) {
		LL s1 = s[i + k - 1] - s[i - 1];
		LL s2 = b[i - 1];
		LL s3 = b[n] - b[i + k - 1];
		
	//	printf("dafuq %lld %lld %lld\n", s1, s2, s3);
		
		ret = max(ret, max(s1, 0) + s2 + s3);
	}
	
	printf("%lld\n", ret);
}