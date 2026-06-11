#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
const int inf = 1e9+7;
const int INF = 1e18+7;
int mod = 1e9+7;

int a[100010], b[100010];
signed main(){
	int n, T, mx = 0, ans = 0;
	scanf("%lld%lld", &n, &T);
	rep(i,n)scanf("%lld", &a[i]);
	drep(i,n-1,0)b[i] = max(b[i+1], a[i]);
	rep(i,n)mx = max(mx, b[i]-a[i]);
	rep(i,n)if(b[i]-a[i] == mx)ans++;
	printf("%lld\n", ans);
	return 0;
}


