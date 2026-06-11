#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

vector<vector<int>> g(100010,vector<int>(0));
vector<int> ans(100010,-1);
int dp(int x){
	if(ans[x] >= 0)return ans[x];
	int sz = g[x].size();
	if(sz == 0) return ans[x] = 0;
	vector<int> res(sz,0);
	for (int i = 0; i < sz; ++i)
	{
		res[i] = dp(g[x][i]);
	}

	sort(res.begin(),res.end());
	for (int i = 0; i < sz; ++i)
	{
		res[i] += sz - i;
	}
	sort(res.begin(),res.end());
	return 	ans[x] = res[sz-1];
}

int main(int argc, char const *argv[])
{
	int n;scanf("%d",&n);
	for (int i = 0; i < n-1; ++i)
	{
		int a;scanf("%d",&a);
		a--;
		g[a].push_back(i+1);
	}
	printf("%d\n",dp(0));
	return 0;
}