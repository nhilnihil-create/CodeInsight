/*input
14 10
1 4
5 7
7 11
4 10
14 7
14 3
6 14
8 11
5 13
8 3
8
8 6 2
9 7 85
6 9 3
6 7 5
10 3 1
12 9 4
9 6 6
8 2 3
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long 
#define double long double
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define RE(i,n) for (int i = 1; i <= n; i++)
#define RED(i,n) for (int i = n; i > 0; i--)
#define REPS(i,n) for(int i = 1; (i*i) <= n; i++)
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int INF = 1e18+1;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int raise(int a,int n,int m = MOD){
  if(n == 0)return 1;
  if(n == 1)return a;
  int x = 1;
    x *= raise(a,n/2,m);
    x %= m;
    x *= x;
    x %= m;
    if(n%2)x*= a;
    x %= m;
    return x;
}

int floor1(int n,int k){
    if(n%k == 0 || n >= 0)return n/k;
    return (n/k)-1;
}

int ceil1(int n,int k){
    return floor1(n+k-1,k);
}

const int N = 1e5+1;
vector<int> adj[N];
int vis[N][11];
int color[N];
int n,m,q;
vector< pair< pair<int,int>,int> > nice; 

void solve(){
  	cin >> n >> m;
  	REP(i,m){
  		int a,b;cin >> a >> b;
  		adj[a].pb(b);
  		adj[b].pb(a);
  	}
  	cin >> q;
  	REP(i,q){
  		int v,d,c;cin >> v >> d >> c;
  		nice.pb({{v,d},c});
  	}
  	reverse(all(nice));
  	REP(i,q){
  		int v = nice[i].f.f;
  		int d = nice[i].f.s;
  		queue< pair<int,int> > q;
  		if(vis[v][d])continue;
  		vis[v][d] = 1;
  		q.push({v,d});
  		while(!q.empty()){
  			int u = q.front().f;
  			int dis = q.front().s;
  			q.pop();
  			if(!color[u])color[u] = nice[i].s;
  			for(int v:adj[u]){
  				if(dis == 0)continue;
  				if(!vis[v][dis-1]){
  					vis[v][dis-1] = 1;
  					q.push({v,dis-1});
  				}
  			}
  		}
  	}
  	RE(i,n)cout << color[i] << "\n";
}

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen(".in","r",stdin);freopen(".out","w",stdout);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }
  return 0;
}