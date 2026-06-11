//解説AC

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

class Edge
{
public:
    int from,to,cost;
    Edge(int a, int b, int c) {
        from = a; to = b; cost = c;
    }
};


const int MAX = 1010;        // Set
vi dist(MAX);
vector<bool> negative(MAX);
vector<Edge> edges;


void bellmanford(int s, int N)
{
        fill(dist.begin(), dist.end(), 1LL<<60);
        dist[s] = 0;

        for (int node = 0; node < N; ++node) {
                for (auto e : edges) {
                        if (dist[e.to] > dist[e.from] + e.cost) {
                                dist[e.to] = dist[e.from] + e.cost;
                        }
                }
        }
        for (int node = 0; node < N; ++node) {
                for (auto e : edges) {
                        if (dist[e.to] > dist[e.from] + e.cost) {
                                dist[e.to] = dist[e.from] + e.cost;
                                negative[e.to] = true;
                        }
                }
        }
}

signed main()
{
        int N, M;
        cin >> N >> M;
        for (int i=0;i<M;i++){
                int a, b, c;
                cin >> a >> b >> c;
                Edge e(a, b, -c);
                edges.push_back(e);
        }

        bellmanford(1, N);
        if (negative[N]) {
                cout << "inf" << endl;
        } else {
                cout << -dist[N] << endl;
        }

}
