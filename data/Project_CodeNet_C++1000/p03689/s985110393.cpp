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

llint H, W, h, w;

int main(void)
{
	cin >> H >> W >> h >> w;
	if(H%h == 0 && W%w==0){
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			if(i % h == 0 && j % w == 0) cout << -400*(h*w-1)-1 << " ";
			else cout << 400 << " ";
		}
		cout << endl;
	}
	
	return 0;
}
