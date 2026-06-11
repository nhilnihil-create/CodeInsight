#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	ll x,y;
	cin >> x >> y;
	ll ans = 1e18;
	if(y > x)ans = min(ans,y-x);
	ans = min(ans,abs(y+x)+1LL);
	ans = min(ans,abs(x-y)+2LL);

	cout << ans << endl;
}
