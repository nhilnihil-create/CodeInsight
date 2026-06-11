#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

typedef long long ll;
int H, W, N;
map<pair<int, int>, ll> mp, vis;
ll cnt[10];

int main() {
	register int i, j; int x, y;
	scanf("%d%d%d", &H, &W, &N); cnt[0] = 1ll * (H - 2) * (W - 2);
	while(N--) {
		scanf("%d%d", &x, &y);
		if(!vis[make_pair(x, y)]) {
			vis[make_pair(x, y)] = 1;
			for(i = -1; i <= 1; ++i)
				for(j = -1; j <= 1; ++j)
					if(2 <= x + i && x + i <= H - 1 && 2 <= y + j && y + j <= W - 1)
						--cnt[mp[make_pair(x + i, y + j)]],
						++mp[make_pair(x + i, y + j)],
						++cnt[mp[make_pair(x + i, y + j)]];
		}
	}
	for(i = 0; i <= 9; ++i)
		printf("%lld\n", cnt[i]);
	return 0;
}