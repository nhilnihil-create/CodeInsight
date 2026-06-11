#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using p  = pair<ll, ll>;
constexpr ll INF = 1LL << 62;
constexpr ll MAX_N = 200000;

ll N, K, L;
unordered_map<ll, vector<ll> > road, line;
ll road_link[MAX_N + 1], line_link[MAX_N + 1];


void patrol(ll root, ll node, unordered_map<ll, vector<ll> >& graph, ll* link, vector<bool>& used) {
    used[node] = true;
    link[node] = root;
    
    for (auto next : graph[node]) {
        if (!used[next]) {
            patrol(root, next, graph, link, used);
        }
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> K >> L;
    
    for (ll i = 0; i < K; i++) {
        ll from, to;
        cin >> from >> to;
        road[from].push_back(to);
        road[to].push_back(from);
    }
    
    for (ll i = 0; i < L; i++) {
        ll from, to;
        cin >> from >> to;
        line[from].push_back(to);
        line[to].push_back(from);
    }
    
    
    vector<bool> road_used(N + 1, false), line_used(N + 1, false);
    for (ll i = 1; i <= N; i++) {
        if (!road_used[i]) {
            patrol(i, i, road, road_link, road_used);
        }
        
        if (!line_used[i]) {
            patrol(i, i, line, line_link, line_used);
        }
    }
    
    unordered_map<ll, unordered_map<ll, ll> > m;
    for (ll i = 1; i <= N; i++) {
        m[road_link[i]][line_link[i]] += 1;
    }
    
    for (ll i = 1; i <= N; i++) {
        cout << m[road_link[i]][line_link[i]] << " \n"[i == N];
    }

    return 0;
}
