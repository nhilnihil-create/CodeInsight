/*input

*/
/*
Contest: 
Problem: 
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define F first
#define S second
#define mp make_pair
#define append push_back
#define vi vector<ll>
#define pii pair<ll,ll>
#define qi queue<ll>
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define print(a) cout<<a<<endl
#define sorted(a) sort(arr.begin(), arr.end())
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define read(a) scanf("%d", &a)
#define int long long int
 
const int MAXN = 2019;

int n, k;
vector<int> graph[MAXN];
vector<int> depth(MAXN);
vector<pair<int, int> > edges;

void dfs(int node, int par){
	for(auto u : graph[node]){
		if(par == u)
			continue;
		depth[u] = depth[node] + 1;
		dfs(u, node);
	}
}

signed main(){
    
    cin>> n >> k;

    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin>> u >> v;
    	graph[u].append(v);
    	graph[v].append(u);
    	edges.append(mp(u, v));
    }
    int ans = n;
    if(k&1){
    	for(int i = 0; i < n-1; i++){
    		int u, v, res = 0;
    		u = edges[i].F;
    		v = edges[i].S;
    		depth[u] = depth[v] = 0;
    		dfs(u, v);
    		dfs(v, u);
    		for(int j = 1; j <= n; j++)
    			if(depth[j] > k/2)
    				res++;
    		ans = min(ans, res);
    	}
    }
    else{
    	for(int i = 1; i <= n; i++){
    		depth[i] = 0;
    		dfs(i, 0);
    		int res = 0;
    		for(int j = 1; j <= n; j++){
    			if(depth[j] > k/2)
    				res++;
    		}
    		ans = min(ans, res);
    	}
    }
    print(ans);

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
} 