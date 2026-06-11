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

llint n, L, Q;
llint x[100005];
llint succ[17][100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	cin >> L;
	
	x[n+1] = inf;
	for(int i = 1; i <= n; i++){
		succ[0][i] = upper_bound(x, x+n+2, x[i]+L) - x - 1;
	}
	
	for(int i = 1; i < 17; i++){
		for(int j = 1; j <= n; j++){
			succ[i][j] = succ[i-1][succ[i-1][j]];
		}
	}
	
	cin >> Q;
	llint s, t;
	for(int q = 0; q < Q; q++){
		cin >> s >> t;
		if(s > t) swap(s, t);
		llint ans = 0, v = s;
		for(int i = 16; i >= 0; i--){
			if(succ[i][v] < t){
				v = succ[i][v];
				ans |= 1<<i;
			}
		}
		ans++;
		cout << ans << endl;
	}
	
	return 0;
}