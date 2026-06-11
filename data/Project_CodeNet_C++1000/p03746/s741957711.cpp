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
int n , m , a , b;
vector<int> adj[MAXN];
vector<int> ans;
bool bo[MAXN];
void dfs(int u)
{
	bo[u] = true, ans.pb(u);
	for(auto v : adj[u])
		if(!bo[v])
			return dfs(v);
	return;
}
int32_t main()
{
	cin >> n >> m;
	while(m --)
		cin >> a >> b , a -- , b -- , adj[a].pb(b) , adj[b].pb(a);
	dfs(0) , reverse(all(ans)) , ans.PB() , dfs(0) , cout << sz(ans) << endl;
	for(auto it : ans)
		cout << it + 1 << " ";
	return cout << endl , 0;
}
