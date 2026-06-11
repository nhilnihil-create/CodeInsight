#include <bits/stdc++.h>
using namespace std;

#define mp(x, y) make_pair((x), (y))

typedef long long ll;

int n;
int x[100005];

ll mod=1000000007;

ll ans=1;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &x[i]);
	int empty=0;
	int cur=0;
	for(int i=0; i<n; i++) {
		empty+=(i==0 ? x[i]-1 : x[i]-x[i-1]-1);
		cur++;
		if(cur-empty>=2) {
			ans=(ans*cur)%mod;
			cur--;
			empty++;
		}
	}
	while(cur>0) {
		ans=(ans*cur)%mod;
		cur--;
	}
	printf("%lld\n", ans);

	return 0;
}