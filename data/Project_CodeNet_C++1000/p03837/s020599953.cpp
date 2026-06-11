#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = (a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (a); i <= (long long)(n); i++)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<double> v_double;
typedef std::vector<std::vector<double> > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

struct Edge {
    int cost, to;
    Edge(int to_, int cost_) : 
        to(to_), cost(cost_) { } 
};


int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<Edge> > node(n);
    map<pii, bool> used_path;

    irep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        node[a-1].push_back(Edge(b-1, c));
        node[b-1].push_back(Edge(a-1, c));
        used_path[pii(a-1,b-1)] = false;
    }

    irep(start, n) {
        v_int dist(n, INF);
        v_bool seen(n, false);
        v_int prev(n, -1);

        dist[start] = 0;
        vector<pii> dist_path[n];

        while(1) {
            int current = -1;
            irep(i, n) {
                if(seen[i] == false && (current == -1 || dist[i] < dist[current])) {
                    current = i;
                }
            }

            if(current == -1) { break; }
            seen[current] = true;

            vector<Edge> edges = node[current];

            irep(i, edges.size()) {
                if(dist[edges[i].to] > dist[current] + edges[i].cost) {
                    dist[edges[i].to] = dist[current] + edges[i].cost;
                    prev[edges[i].to] = current;
                }
            }
        }

        irep(i, n) {
            v_int path;
            if(i == start) { continue; }
            for (int cur = i; cur != -1; cur = prev[cur]) {
                path.push_back(cur);
            } 
            irep(j, path.size()-1) {
                used_path[pii(path[j], path[j+1])] = true;        
                used_path[pii(path[j+1], path[j])] = true;        
            }
        }
    }
    int ans = 0;
    for(auto path : used_path) {
        if(!path.second) { ans++; }
    }
    cout << ans << endl;
    return 0;
}
/** atcoder **/
