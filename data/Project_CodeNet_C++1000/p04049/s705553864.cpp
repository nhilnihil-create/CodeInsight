#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

const int INF = 10000010;
const int N = 4040;

int n, k;
int ans = N;
int topQ;
int q[N];
int dist[N];
vector<int> G[N];

void BFS() {

	rep(k, topQ) {
		int v = q[k];
		for(auto u : G[v]) {
			int w = dist[v] + 2;
			if(dist[u] <= w) {
                continue;
            } 
			dist[u] = w;
			q[topQ++] = u;
		}
	}

	return;
}
 
int solveVertex(int v) {

	rep(i, n) {
        dist[i] = INF;
    }

	dist[v] = 0;
	topQ = 0;
	q[topQ++] = v;

	BFS();

	int res = 0;
	rep(i, n) {
        if(dist[i] > k) {
            res++;
        }
    }
		
	return res;
}

int solveEdge(int v, int u) {

	rep(i, n) {
		dist[i] = INF;
	}
		
	dist[v] = dist[u] = 1;
	topQ = 0;
	q[topQ++] = v;
	q[topQ++] = u;

	BFS();

	int res = 0;
	rep(i, n) {
		if(dist[i] > k) {
			res++;
		}
	}
		
	return res;
}
 
int main() {

	cin >> n >> k;

	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--;  b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	rep(v, n) {
		ans = min(ans, solveVertex(v));
	}

	rep(v, n) {
		for(auto u : G[v]) {
			if(u > v) {
				ans = min(ans, solveEdge(v, u));
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}