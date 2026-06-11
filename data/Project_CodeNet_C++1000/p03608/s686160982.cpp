		#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;

 
const ll INF = (1001001001);
const ll N =(200+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

int a[N];
int adj[N][N];
void solve(){
	int n,m,r;
	cin >> n >> m >> r;	
	vector<int> v(r);
	for(int i =1;i<=r;i++){
		cin >> v[i-1];
	}
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			adj[i][j]=INF;
		}
		adj[i][i]=0;
	}
	for(int i =1;i<=m;i++){
		int u,vv,c;
		cin >> u >> vv >> c;
		adj[u][vv] = c;
		adj[vv][u] = c;
	}
	for(int k=1;k<=n;k++){
		for(int i =1;i<=n;i++){
			for(int j =1;j<=n;j++){
				
				adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
			}	
		}
	}
	sort(v.begin(),v.end());
	int ans = INF;
	do{
		int co = 0;
		for(int i = 1;i<v.size();i++){
			co += adj[v[i-1]][v[i]];
		}
		ans = min(ans,co);
	}while(next_permutation(v.begin(),v.end()));
	cout << ans << endl;
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     // freopen(".in","r",stdin);freopen(".out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}