#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

struct Edge{
	int from, to;
	ll cost;
	Edge(int from, int to, ll cost) : from(from), to(to), cost(cost){}
};

int n, m;

vector<bool> ng;

vector<Edge> es;
vector<ll> dist;
void bellman_ford(int s){
	dist[s] = 0;
	for(int i = 0; i < n - 1; ++i){
		for(auto e : es){
			if(dist[e.from] == LINF)continue;
			dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
		}
	}

	ng.assign(n, false);
	for(int i = 0; i < n; ++i){
		for(auto e : es){
			if(dist[e.from] == LINF)continue;
			if(dist[e.from] + e.cost < dist[e.to]){
				dist[e.to] = dist[e.from] + e.cost;
				ng[e.to] = true;
			}

			if(ng[e.from])ng[e.to] = true;
		}
	}
}

int main(){
  int s;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
  	int a, b;
  	ll c;
  	cin >> a >> b >> c;
  	--a;
  	--b;
  	c = -c;
  	es.push_back(Edge(a, b, c));
  }

  dist.assign(n, LINF);
  bellman_ford(0);
  if(ng[n - 1]){
  	cout << "inf" << endl;
  	return 0;
  }
  cout << -dist[n - 1] << endl;
  return 0;
}
