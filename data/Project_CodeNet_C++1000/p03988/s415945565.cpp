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

llint n;
llint a[105], cnt[105];

int main(void)
{
	cin >> n;
	
	llint mn = inf, mx = -inf;
	for(int i = 1; i <= n; i++){
		cin >> a[i], cnt[a[i]]++;
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if(cnt[mn] >= 3){
		cout << "Impossible" << endl;
		return 0;
	}
	if(cnt[mn] == 1 && mx != 2*mn){
		cout << "Impossible" << endl;
		return 0;
	}
	if(cnt[mn] == 2 && mx != 2*mn-1){
		cout << "Impossible" << endl;
		return 0;
	}
	
	for(int i = mn+1; i <= mx; i++){
		if(cnt[i] < 2){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
	
	return 0;
}
