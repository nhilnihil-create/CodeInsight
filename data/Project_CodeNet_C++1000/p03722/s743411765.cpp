#include <bits/stdc++.h>

#define PI 3.14159265359
#define EPS 1e-16
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
    int from;
    int to;
    ll cost;

    Edge(int from_, int to_, int cost_) : 
        from(from_), to(to_), cost(cost_) { }
};

void shortest_path(int s, vector<Edge> &edges, v_ll &dist, v_bool &negative, ll &ans) 
{ 
    irep(i, dist.size()) { dist[i] = LINF; }
    irep(i, negative.size()) { negative[i] = false; }
    dist[s] = 0;

    irep(v, dist.size()) {
        irep(i, edges.size()) { 
            Edge e = edges[i];
            if(dist[e.from] != LINF && 
               dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }

    ans = dist[dist.size()-1];

    irep(v, dist.size()+3) {
            
        irep(i, edges.size()) { 
            Edge e = edges[i];
            if(dist[e.from] != LINF && 
               dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                negative[e.to] = true; 
                if(negative[e.from]) {
                    negative[e.to] = true; 
                }
            }
        }
    }
}

bool find_negative_loop(vector<Edge> &edges, v_ll &dist) { /*find negative loop*/

    irep(i, dist.size()) { dist[i] = LINF; }

    for(int i = 0; i < dist.size(); i++) {
        for(int j = 0; j < edges.size(); j++) {
            Edge edge = edges[j];
            if(dist[edge.to] > dist[edge.from] + edge.cost) {
                dist[edge.to] = dist[edge.from] + edge.cost;
                if(i == dist.size()-1) return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges;
    v_ll dist(n);
    v_bool negative(n);

    irep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        Edge e(a-1, b-1, -c);
        edges.push_back(e);
    }

    ll ans = 0;
    shortest_path(0, edges, dist, negative, ans);

    if(negative[n-1]) {
        cout << "inf" << endl;
    } else {
        cout << -dist[n-1] << endl;
    }

    return 0;
}

