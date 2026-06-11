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

 
const ll INF = 1e12;
const ll N =(2e3+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

vector<int> adj[N];

int dis[N][N];
int s;
void dfs(int u,int p,int h){
    dis[s][u] = h;
    for(auto v:adj[u]) if(v != p){
    	dfs(v,u,h+1);
    }
}

void solve(){
    int n,m;
    cin >> n >> m; 
    for(int i = 2;i <= n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }  
    for(int i =1;i<=n;i++){
    	s = i;
    	dfs(i,0,0);
    }
    int ans = 0;
    if(m%2==0){
    	int cnt = 0;
    	for(int i = 1;i <= n;i++){
    		cnt =0;
    		for(int j = 1;j<=n;j++){
    			if(dis[i][j] <= (m >> 1ll))
    				cnt++;
    		}
    		ans = max(ans,cnt);
    	}
    }
    else{
    	for(int i = 1;i<=n;i++){
    		for(auto j:adj[i]){
    			int cnt =0;
    			for(int k = 1;k<=n;k++){
    				if(min(dis[i][k],dis[j][k]) <= (m>>1ll))
    					cnt++;
    			}
    			ans =max(ans,cnt);
    		}
    	}
    }
    cout << n-ans << endl;
   

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