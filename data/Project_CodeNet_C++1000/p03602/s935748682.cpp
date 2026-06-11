#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N = 305;
const ll inf = 1e18;

int n, a[N][N];
ll ans, dis[N][N];

vector<pair<int,pii> > edg;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
			if(i < j) edg.push_back({a[i][j], {i,j}});
			dis[i][j] = inf;
		}
	}
	sort(edg.begin(), edg.end());
	for(auto &T : edg) {
		int A = T.Y.X, B = T.Y.Y, C = T.X;
		long long D = inf;
		for(int i=1;i<=n;i++) {
			D = min(D, dis[A][i] + dis[i][B]);
		}
		if(D < C) {
			puts("-1");
			return 0;
		}
		if(D > C) {
			ans += C;
		}
		dis[A][B] = C;
		dis[B][A] = C;
	}
	printf("%lld\n",ans);
}
