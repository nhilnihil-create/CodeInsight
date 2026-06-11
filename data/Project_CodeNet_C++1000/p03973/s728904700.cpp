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
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n;
llint a[100005];
bool used[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ans = a[1]-1, mx = 1;
	for(int i = 2; i <= n; i++){
		if(a[i] <= mx) continue;
		if(a[i] == mx+1){
			mx++;
			continue;
		}
		ans += a[i]/(mx+1);
		if(a[i] % (mx+1) == 0) ans--;
	}
	cout << ans << endl;
	
	return 0;
}
