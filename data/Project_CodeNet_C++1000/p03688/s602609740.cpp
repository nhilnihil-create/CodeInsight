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
llint a[100005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	if(a[n]-a[1] >= 2){
		cout << "No"<< endl;
		return 0;
	}
	if(a[n] == a[1]){
		if(a[1] == n-1 || a[1] * 2 <= n) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
	llint cnt = 0, kind = a[n];
	for(int i = 1; i <= n; i++){
		if(a[i] == a[1]) cnt++;
	}
	if(cnt >= kind || 2*(kind-cnt) > n-cnt) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	return 0;
}
