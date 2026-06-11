#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const ll INF = 1LL << 58;

struct edge{
	ll from;
	ll to;
	ll cost;
};

vector<edge> G;

int main(){
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		G.pb({a, b, -c});
	}
	ll d[1010];
	for(int i = 0; i < 1010; i++) d[i] = INF;
	d[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			edge e = G[j];
			if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
				d[e.to] = d[e.from] + e.cost;
				if(i == n-1 && e.to == n-1){
					cout << "inf" << endl;
					return 0;
				}
			}
		}
	}
	cout << -d[n-1] << endl;
	return 0;
}
