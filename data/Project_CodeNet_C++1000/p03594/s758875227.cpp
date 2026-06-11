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

llint h, w, d;
llint ans[505][505];

int main(void)
{
	cin >> h >> w >> d;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			if((x+y)%(2*d) < d) ans[x][y] |= 1;
			if(((x-y)%(2*d)+2*d)%(2*d) < d) ans[x][y] |= 2;
		}
	}
	
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cout << "RYGB"[ans[x][y]];
		}
		cout << endl;
	}
	
	return 0;
}
