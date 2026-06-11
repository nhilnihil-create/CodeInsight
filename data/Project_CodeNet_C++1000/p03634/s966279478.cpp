#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define g(a, b) __gcd((a), (b))
#define l(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;



const ll MAX = 100010;        // Set
using Vertex = pair<ll, ll>;  // (dist, id)
class Edge
{
public:
    ll to;
    ll cost;
    Edge() : to{0}, cost{0} {}
    Edge(ll a, ll b) : to{a}, cost{b} {}
};

vector<vector<Edge> > Graph(MAX, vector<Edge>(0));
vll dist(MAX, inf);

void dijkstra(ll s)
{
    fill(dist.begin(), dist.end(), inf);
    dist[s] = 0;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex> > pq;    

    pq.push(Vertex(0, s));
    while(! pq.empty()) {
        // Enqueue first node
        Vertex now = pq.top(); pq.pop();
        ll vertex = now.second;
        if (dist[vertex] < now.first) continue;
        // Check for each adjacent node
        for (Edge edge : Graph[now.second]) {
            if (dist[edge.to] > dist[now.second] + edge.cost) {
                dist[edge.to] = dist[now.second] + edge.cost;
                pq.push(Vertex(dist[edge.to], edge.to));
            }
        }
    }
}

// TODO: Graph[from].push_back(Edge(to, cost))
int main()
{
        ll N;
        cin >> N;
        rep(i, 0, N-1) {
                ll a, b, c;
                cin >> a >> b >> c;
                Graph[a].push_back(Edge(b, c));
                Graph[b].push_back(Edge(a, c));
        }

        ll Q, K;
        cin >> Q >> K;
        dijkstra(K);
        rep(i, 0, Q) {
                ll x, y;
                cin >> x >> y;
                cout << dist[x] + dist[y] << endl;
        }
}