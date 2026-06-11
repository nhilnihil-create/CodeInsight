#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 2e18;

template< typename T >
struct edge {
    int src, to, number;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge(int src, int to, T cost, int number) : src(src), to(to), cost(cost), number(number) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
set<int> dijkstra(WeightedGraph< T > &g, int s) {
    const auto INF = numeric_limits< T >::max();
    vector< T > dist(g.size(), INF);
    set<int> number;

    using Pi = pair< T, int >;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while(!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }

    vector< T > temp(g.size(), INF);
    temp[s] = 0;
    que.emplace(temp[s], s);
    while(!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(temp[idx] < cost) continue;
        for(auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if(temp[e.to] < next_cost) continue;
            if (dist[e.to] == next_cost) {
                number.insert(e.number);
                if (temp[e.to] == next_cost) continue;
            }
            temp[e.to] = next_cost;
            que.emplace(temp[e.to], e.to);
        }
    }
    return number;
}


signed main() {
    int N, M;
    cin >> N >> M;
    WeightedGraph<int> g(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].emplace_back(a, b, c, i);
        g[b].emplace_back(b, a, c, i);
    }
    set<int> ans;
    for (int i = 0; i < N; i++) {
        auto temp = dijkstra(g, i);
        auto itr = temp.begin();
        while (itr != temp.end()) {
            ans.insert(*itr);
            itr++;
        }
    }
    cout << M - ans.size() << endl;
}
