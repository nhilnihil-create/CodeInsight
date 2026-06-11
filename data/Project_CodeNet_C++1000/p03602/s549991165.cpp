#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define inf 1000000007
#define N 305
using namespace std;

typedef long long ll;
typedef pair < ll , ll > ii;

ll n, ans, ata[N], a[N][N], d[N];
vector < pair < ll , ii > > b;
vector < ii > g[N];
priority_queue < ii > q;

ll sp(ll x, ll y){
	for(ll i = 1; i <= n; i++)
		d[i] = inf;
	d[x] = 0;
	q.push(mp(0, x));
	while(!q.empty()){
		ll node = q.top().nd;
		q.pop();
		for(ll i = 0; i < g[node].size(); i++)
			if(d[g[node][i].st] > d[node] + g[node][i].nd){
				d[g[node][i].st] = d[node] + g[node][i].nd;
				q.push(mp(-d[g[node][i].st], g[node][i].st));
			}
	}
	return d[y];
}

ll atabul(ll x){return ata[x] = (ata[x] == x)?x:atabul(ata[x]);}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("outt.txt", "w", stdout);
	scanf("%lld",&n);
	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= n; j++){
			scanf("%lld",&a[i][j]);
			if(i < j)
				b.pb(mp(a[i][j], mp(i, j)));
		}
	for(ll i = 1; i <= n; i++)
		ata[i] = i;
	sort(b.begin(), b.end());
	for(ll i = 0; i < b.size(); i++){
		ll x = b[i].nd.st;
		ll y = b[i].nd.nd;
		ll xx = atabul(x);
		ll yy = atabul(y);
		if(xx != yy){
			ans += b[i].st;
			ata[xx] = yy;
			g[x].pb(mp(y, b[i].st));
			g[y].pb(mp(x, b[i].st));
			continue;
		}
		ll dd = sp(x, y);
		if(dd < b[i].st){
			puts("-1");
			return 0;
		}
		if(dd == b[i].st)
			continue;
		ans += b[i].st;
		g[x].pb(mp(y, b[i].st));
		g[y].pb(mp(x, b[i].st));
	}
	printf("%lld\n", ans);
	return 0;
}