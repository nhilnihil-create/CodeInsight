#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;

vector< int> g[N];
int n, k, a[N], ans;
int dfs(int v){
	int mx = 0;
	for(auto to : g[v]){
		int x = dfs(to) + 1;
		if(x == k && v != 1)
			ans++;	
		else
			mx = max(mx, x);

	}
	return mx;
}
int main(){    
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(a[1] != 1 )
		a[1] = 1, ans ++;
	for(int i = 2; i <= n; i++)
		g[a[i]].pb(i);
	dfs(1);
	cout << ans;
	return 0;
}
