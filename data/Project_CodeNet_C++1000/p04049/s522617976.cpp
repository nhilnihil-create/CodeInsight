///supercalifragilisticexpialidocious.
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <bitset>
#include <complex>
using namespace std;
#define f first
#define s second
#define PB pop_back 
#define pb push_back
#define mp make_pair
#define int long long
#define y1 y_golabi
#define sz(s) (int)s.size()
#define seper(n) setprecision(n)
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
typedef map<int , int> mii;
typedef pair<int , int> pii;
typedef map<string , int> msi;
typedef pair<int , string> pis;
typedef pair<int , pair<int , int> > piii;
const int MAXN = 2e3 + 10;
int n , k , u , v , mn , h[MAXN];
pii edge[MAXN];
vector<int> adj[MAXN];
int dfs(int u)
{
	int ans = (k / 2 < h[u]);
	for(auto v : adj[u])
		if(h[v] == -1)
			h[v] = h[u] + 1 , ans += dfs(v);
	return ans;
}
void input()
{
	cin >> n >> k;
	for(int i = 0 ; i < n - 1 ; i ++)
		cin >> u >> v , u -- , v -- , adj[u].pb(v) , adj[v].pb(u) , edge[i] = mp(u , v);
	return;
}
int32_t main()
{
	input() , mn = 1e9;
	/*for(int i = 0 ; i < n - 1 ; i ++)
		cout << edge[i].f << " " << edge[i].s << "       ";
	cout << endl;*/
	/*for(int i = 0 ; i < n ; i ++)
	{
		for(auto j : adj[i])
			cout << "adj[i][j]: " << j << " "; 
		cout << endl;
	}*/
	if(!(k % 2))
		for(int i = 0 ; i < n ; i ++)
			mem(h , -1) , h[i] = 0 , mn = min(mn , dfs(i));
	else
		for(int i = 0 ; i < n - 1 ; i ++)
			mem(h , -1) , h[edge[i].f] = h[edge[i].s] = 0 , mn = min(mn , dfs(edge[i].f) + dfs(edge[i].s));
	return cout << mn << endl , 0;
}		
