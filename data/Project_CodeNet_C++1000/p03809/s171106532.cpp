/*
https://open.spotify.com/track/1nEjpWJlqcOsf2ZaRQ3XdW?si=kp72YcBSRjSiiZjnbDqP2A

In the particularly cold night
Perhaps you couldn’t sleep well
In the bright morning woken up from sleep
You are full of darkness
You, who were so worried for some reason that you
Hugged me tightly and asked for my love

You broke and ruined my everything
My daily life and even my people yeah
I resent you all day
But to leave you I oh I

Don’t worry babe
I love you babe
I’ll be by your side
Maybe

Maybe

Looks about to collapse but remains
And the cycle continues unsteadily
I’m about to give up but when I see you I Oh I

No babe
I love you babe
I’ll hold your hand
Maybe

Maybe
I’ll be by your side
Maybe
I’ll trust you

Stay with me, stay with me
So you won’t think of anything
I’ll stay here pretending to be reluctant
So hold me back
Maybe

Maybe
I will be by your side
Maybe
I’ll trust you

Maybe
*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define for1(i, a, b) for(i = a; i <= b; ++i)
#define for0(i, a, b) for(i = a; i < b; ++i)
#define forw1(i, a, b) for(i = a; i >= b; --i)
#define forw0(i, a, b) for(i = a - 1; i >= b; --i)
#define fora(v, a) for(auto v : a)
#define bp __builtin_popcount
#define bpll __builtin_popcountll

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 1e5 + 10, K = 26, inf = 1e9;

int n, a[maxn], deg[maxn];
vi gr[maxn];

int dfs(int u, int par){
	int res = 0;	
	if(gr[u].size() == 1 && gr[u][0] == par){
		return a[u];
	}
	int mx = 0;
	fora(v, gr[u]){
		if(v == par){
			continue;
		}
		int tmp = dfs(v, u);
		res += tmp;
		mx = max(mx, tmp);
	}
	if(gr[u].size() == 2 && par != -1){
		if(res != a[u]){
			cout << "NO\n"; exit(0);
		}
		return a[u];
	}
	if(mx * 2 > res && par == -1){
		cout << "NO\n"; exit(0);
	}
	if(2 * a[u] - res < 0){
		cout << "NO\n"; exit(0);
	}
	if(2 * a[u] - res > res){
		cout << "NO\n"; exit(0);
	}
	if(a[u] < mx){
		cout << "NO\n"; exit(0);
	}
	return 2 * a[u] - res;
}

void solve(){
	int i, j, k, l, r; cin >> n;
	for1(i, 1, n){
		cin >> a[i];
	}
	for0(i, 1, n){
		int u, v; cin >> u >> v;
		gr[u].pb(v); gr[v].pb(u);
		deg[u]++; deg[v]++;
	}
	if(n == 2){
		if(a[1] == a[2]){
			cout << "YES\n"; return;
		}
		else cout << "NO\n"; return;
	}
	int root = -1;
	for1(i, 1, n){
		if(deg[i] > 1){
			root = i;
		}
	}
	//cout << root << '\n';
	int now = dfs(root, -1);
	if(now == 0){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}

signed main() {
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}