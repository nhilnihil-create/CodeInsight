// Why am I so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;

vector<int> adj[MAXN];

ll arr[MAXN];

ll e[MAXN];

int n;

bool calc(vector<ll> vv, int lim) {
	vv.pb(lim);
	ll sum = 0;

	for (ll x : vv) {
		sum += x;
	}

	if (sum & 1) {
		return 0;
	}
	
	sum /= 2;

	for (ll x : vv) {
		if (x > sum) {
			return 0;			
		}
	}

	return 1;
}

bool dfs(int v, int pr) {
	if (adj[v].size() == 1) {
		e[v] = arr[v];
		return 1;
	}

	ll sum = 0, mx = 0;
	vector<ll> vv;

	for (int to : adj[v]) {
		if (to == pr) {
			continue;
		}

		if (!dfs(to, v)) {
			return 0;
		}

		vv.pb(e[to]);       
	}

	sort(all(vv));

	for (ll x : vv) {
		sum += x;
	}	

	e[v] = arr[v] * 2 - sum;

	if (e[v] < 0) {
		return 0;
	}

	if (pr == -1 && e[v] != 0) {
		return 0;
	}	
                 
	return calc(vv, e[v]);
}

void solve() {                   
	scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
    	scanf("%lld", &arr[i]);
    }    

    if (n == 2) {
		printf(arr[1] == arr[2] ? "YES\n" : "NO\n");
		return;
    }

    for (int i = 1, u, v; i < n; ++i) {
    	scanf("%d %d", &u, &v);
    	adj[u].pb(v);                                      
    	adj[v].pb(u);
    }

    int root = -1;

    for (int i = 1; i <= n; ++i) {
    	if (adj[i].size() > 1) {
    		root = i;
    		break;
    	}
    }
    
    printf(dfs(root, -1) ? "YES\n" : "NO\n");  
}

int main() {    
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}