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
const int MAXN = 1e5 + 10;
int n , m , q , a , b , v[MAXN] , d[MAXN] , c[MAXN] , co[10 + 10][MAXN];
vector<int> adj[MAXN];
void dfs(int u , int d , int col)
{
	if(co[d][u])
		return;
	co[d][u] = col;
	if(!d)
		return;
	dfs(u , d - 1 , col);
	for(auto v : adj[u])
		dfs(v , d - 1 , col);
	return;
}
void input()
{
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++)
		cin >> a >> b , a -- , b -- , adj[a].pb(b) , adj[b].pb(a);
	cin >> q;
	for(int i = 0 ; i < q ; i ++)
		cin >> v[i] >> d[i] >> c[i] , v[i] --;
	return;
} 
int32_t main()
{
	input();
	for(int i = q - 1 ; i >= 0 ; i --)
		dfs(v[i] , d[i] , c[i]);
	for(int i = 0 ; i < n; i ++)
		cout << co[0][i] << endl;
	return 0;
}
