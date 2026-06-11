#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()
#define trill pair<ll,pill>
#define F f
#define S s.f
#define Th s.s


using namespace std;

const ll N = 2011;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll n, k;

bool del[N];

vector<ll> g[N];

ll gl[N][N];

void bfs(ll s) {
	queue<pill> x;
	x.push({s, 0});
	bool w[N] = {0};
	w[s] = 1;
	while(x.size()) {
		ll v = x.front().f, rst = x.front().s;
		gl[s][v] = rst;
		x.pop();
		for(auto u : g[v]) {
			if(!w[u] && !del[u])
				w[u] = 1,x.push({u, rst + 1});
		}
	}
}

int main() {
	speed;
	cin >> n >> k;
	rep(1, n, 1) {
		ll a,b;
		cin >> a >> b;
		g[a].pb(b), g[b].pb(a);
	}
	for(int i = 1; i <= n; i++)
		bfs(i);
	ll ans = n;
	for(int x = 1 ; x <= n ; x++) {
		if(k % 2) {
			for(auto u : g[x]) {
				ll z = n;
				for(int i = 1; i <= n; i++) {
					if(min(gl[x][i], gl[u][i]) <= k / 2 )
						z--;
				}
				ans = min(z, ans);
			}
		} else {
			ll z = n;
			for(int i = 1; i <= n ; i++)
				if(gl[x][i] <= k / 2)
				z--;
			ans = min(z, ans);
		}
	}
	cout << ans;
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/

