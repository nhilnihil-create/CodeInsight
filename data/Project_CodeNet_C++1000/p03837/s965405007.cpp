#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> init(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second
using P = pair<int, int>;

int n, m;
v2<P> adj;
set<P> seen;

void solve(){
    cin >> n >> m;
    adj = v2<P>(n);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for(int s = 0; s < n; ++s){
        vector<int> d(n, 1e9), p(n, -1);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, s});
        d[s] = 0;
        while(!pq.empty()){
            int node = pq.top().S;
            pq.pop();
            for(P& a : adj[node]){
                int next = a.F, w = a.S;
                if(d[node] + w < d[next]){
                    d[next] = d[node] + w;
                    pq.push({d[next], next});
                    p[next] = node;
                }
            }
        }

        vector<int> v(n, false);
        for(int i = 0; i < n; ++i){
            int node = i;
            while(p[node] != -1){
                if(v[node]) break;
                v[node] = true;
                int a = min(node, p[node]), b = max(node, p[node]);
                seen.insert({a, b});
                node = p[node];
            }
        }
    }

    cout << m - (int)seen.size() << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}