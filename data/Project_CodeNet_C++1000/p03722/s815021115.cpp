//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
	ll N, M;
	cin >> N >> M;
	struct Edge {
		ll to;
		ll cost;
	};
	vector<vector<Edge>> graph(N);
	rep(i,0,M) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		c *= -1;
		graph[a].push_back({b, c});
	}
	vector<ll> loop_detect(N);
	vector<ll> loops;
	rep(n,0,M+1) {
		rep(i,0,N) {
			for (Edge& e : graph[i]) {
				if (loop_detect[i] + e.cost < loop_detect[e.to]) {
					loop_detect[e.to] = loop_detect[i] + e.cost;
					if (n == M) {
						loops.push_back(e.to);
					}
				}
			}
		}
	}
	vector<bool> reachable_from_start(N);
	reachable_from_start[0] = true;
	vector<bool> reachable_to_end(N);
	reachable_to_end[N-1] = true;
	rep(n,0,M) {
		rep(i,0,N) {
			for (Edge& e : graph[i]) {
				if (reachable_from_start[i]) {
					reachable_from_start[e.to] = true;
				}
				if (reachable_to_end[e.to]) {
					reachable_to_end[i] = true;
				}
			}
		}
	}
	for (ll pt : loops) {
		if (reachable_from_start[pt] && reachable_to_end[pt]) {
			cout << "inf" << endl;
			return 0;
		}
	}
	vector<ll> dist(N, numeric_limits<ll>::max());
	dist[0] = 0;
	rep(n,0,M) {
		rep(i,0,N) {
			for (Edge& e : graph[i]) {
				if (dist[i] != numeric_limits<ll>::max()
					&& dist[i] + e.cost < dist[e.to]) {
					dist[e.to] = dist[i] + e.cost;
				}
			}
		}
	}
	cout << -dist[N-1] << endl;
}
