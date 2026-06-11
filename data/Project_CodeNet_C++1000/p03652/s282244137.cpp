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
typedef pair<P, llint> E;

llint n, m;
llint a[305][305], b[305][305];
set<llint> S[305];
bool used[305];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) b[i][a[i][j]] = j;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			S[i].insert(j);
		}
	}
	
	llint ans = inf;
	for(int i = 1; i <= m; i++){
		
		llint max_val = -1, max_j;
		for(int j = 1; j <= m; j++){
			if(used[j]) continue;
			llint cnt = 0;
			for(int k = 1; k <= n; k++){
				if(b[k][j] == *S[k].begin()) cnt++;
			}
			if(cnt > max_val){
				max_val = cnt;
				max_j = j;
			}
		}
		ans = min(ans, max_val);
		
		used[max_j] = true;
		for(int k = 1; k <= n; k++) S[k].erase(b[k][max_j]);
	}
	cout << ans << endl;
	
	
	return 0;
}
