#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>
#include <cassert>
using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

vector<vector<int> > g;

int dfs(int id,int pre){
	int res = 0;
	for(auto x:g[id]){
		if(x!=pre){
			res ^=dfs(x,id)+1;
		}
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	g.resize(n);
	rep(i,n-1){
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(dfs(0,0)==0){
		cout << "Bob" << endl;
	}else{
		cout << "Alice" << endl;
	}
	return 0;
}