#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;
vector<vector<int> > g;
vector<int> color,flag;
void dfs(int x,int dst,int max_dst,int c){
	color[x] = color[x]==0?c:color[x];
	if(flag[x]>=max_dst-dst){
		return;
	}

	flag[x] = max_dst-dst;
	if(dst >= max_dst)
		return;
	for(int i = 0; i < g[x].size(); i++){
			dfs(g[x][i],dst+1,max_dst,c);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	g.resize(n,vector<int>());
	color.resize(n,0);
	for(int i = 0; i < m; i++){
		int a,b;
		cin>>a>>b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	int q;
	cin>>q;
	vector<int> v(q),d(q),c(q);
	for(int i = 0; i < q; i++){
		cin>>v[i]>>d[i]>>c[i];
		v[i]--;
	}

	flag.resize(n,0);
	for(int i = q-1; i >= 0; i--){
		dfs(v[i],0,d[i],c[i]);
	}

	for(int i = 0; i < n; i++){
		cout << color[i] << endl;
	}


	return 0;
}