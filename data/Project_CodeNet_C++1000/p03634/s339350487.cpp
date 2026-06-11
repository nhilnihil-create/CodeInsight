#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll LINF = (1LL<<60);
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
vector<pl> g[100100];
ll n , q , k;

vl dijkstra(ll s){
	priority_queue<pl, vector<pl>, greater<pl>> q;
	vl dist(n , LINF);
	dist[s] = 0;
	q.push(pl(dist[s] , s));
	while(!q.empty()){
		pl p = q.top(); q.pop();
		ll cost = p.first;
		ll from = p.second;
		if(dist[from] < cost)continue;
		for(auto c:g[from]){
			ll to = c.first;
			ll di = c.second;
			if(dist[from] + di < dist[to]){
				dist[to] = dist[from] + di;
				q.push(pl(dist[to] , to));
			}
		}
	}
	return dist;
}

signed main(){
	//cout << fixed << setprecision(10);
    cin >> n;
	rep(i,0,n - 1){
		ll a,b,c; cin >> a >> b >> c;
		--a; --b;
		g[a].push_back(pl(b,c));
		g[b].push_back(pl(a,c));
	}
	cin >> q >> k;
	--k;
	auto dist = dijkstra(k);
	while(q--){
		ll x,y; cin >> x >> y;
		--x; --y;
		cout << dist[x] + dist[y] << endl;
	}

	return 0;
}