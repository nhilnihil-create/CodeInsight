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
#define printP(x) "(" << (x).first << ", " << (x).second << ")"
#define mod 1000000007
using namespace std;
typedef pair<llint, llint> P;

llint n;
llint x[505], rem[505];
llint ans[250005];
priority_queue<P, vector<P>, greater<P> > Q;
multiset<llint> S;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
		ans[x[i]] = i;
		rem[i] = i-1;
		if(i > 1) Q.push(P(x[i], i));
	}
	
	for(int i = 1; i <= n*n; i++){
		if(ans[i]){
			for(int j = 0; j < n-ans[i]; j++) S.insert(ans[i]);
			continue;
		}
		if(Q.size()){
			llint p = Q.top().first, id = Q.top().second;
			Q.pop();
			if(p < i){
				cout << "No" << endl;
				return 0;
			}
			ans[i] = id;
			rem[id]--;
			if(rem[id] > 0) Q.push(P(x[id], id));
		}
		else{
			if(S.size() == 0){
				cout << "No" << endl;
				return 0;
			}
			ans[i] = *S.begin();
			S.erase(S.begin());
		}
	}
	
	cout << "Yes" << endl;
	for(int i = 1; i <= n*n; i++) cout << ans[i] << " ";  cout << endl;
	
	return 0;
}
