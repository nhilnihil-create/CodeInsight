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
//#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define printP(x) "(" << (x).first << ", " << (x).second << ")"
#define mod 1000000007
using namespace std;
typedef pair<int, int> P;

llint n;
vector<llint> G[100005];

llint dfs(int v)
{
	if(G[v].size() == 0) return 0;
	vector<llint> vec;
	for(int i = 0; i < G[v].size(); i++){
		vec.push_back(dfs(G[v][i]));
	}
	sort(vec.rbegin(), vec.rend());
	
	llint ret = 0;
	for(int i = 0; i < vec.size(); i++) ret = max(ret, vec[i]+i+1);
	return ret;
}

int main(void)
{
	cin >> n;
	llint p;
	for(int i = 2; i <= n; i++){
		cin >> p;
		G[p].push_back(i);
	}
	cout << dfs(1) << endl;
	
	return 0;
}
