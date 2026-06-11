#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint a[100005];
llint dif[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i]--;
	
	llint ans = 0;
	for(int i = 1; i < n; i++) ans += ((a[i+1]-a[i])%m+m)%m;
	
	for(int i = 1; i < n; i++){
		llint l = a[i], r = a[i+1];
		if(l > r) r += m;
		llint len = r-l;
		if(len <= 1) continue;
		dif[l+2]++, dif[r+1]-=len, dif[r+2]+=len-1;
	}
	for(int i = 1; i < 2*m; i++) dif[i] += dif[i-1];
	for(int i = 1; i < 2*m; i++) dif[i] += dif[i-1];
	
	llint mx = 0;
	for(int i = 0; i < m; i++) mx = max(mx, dif[i]+dif[m+i]);
	cout << ans-mx << endl;
	
	return 0;
}