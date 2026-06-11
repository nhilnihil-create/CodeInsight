#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n, k; scanf("%d %d", &n, &k);
	int a[100000], b[100000];
	for(int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
	ll res = 0;
	for(int i = 0; i < n; i++) if((k | a[i]) <= k) res += b[i];
	for(int i = 0; i < 30; i++) if((k >> i) & 1){
		int t = k & ~((1 << (i + 1)) - 1) | ((1 << i) - 1);
		ll ret = 0;
		for(int j = 0; j < n; j++) if((t | a[j]) <= t) ret += b[j];
		res = max(res, ret);
	}
	printf("%lld\n", res);
	return 0;
}