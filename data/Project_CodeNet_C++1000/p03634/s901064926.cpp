#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const static ll Max = 100000+5;
const static ll INF = 1e18+5;
vector<set<ll>> G(Max);
ll N, Q, K;
map<pair<ll, ll>, ll> C;
ll DP[Max];


void Dijkstra(ll s){
    for(int i = 0; i < Max; i++) DP[i] = INF;
    DP[s] = 0;
    for(auto v : G[s]) DP[v] = C[make_pair(s, v)];
    priority_queue< pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>> > Q;
    for(auto v : G[s]){
        if(C.find(make_pair(s, v)) != C.end()) Q.push(make_pair(C[make_pair(s, v)], make_pair(s, v)));
    }
    while(!Q.empty()){
        auto next = Q.top(); Q.pop();
        auto w = next.second.second;
        for(auto v : G[w]) if(C.find(make_pair(w, v)) != C.end()){
            if(DP[w] + C[make_pair(w, v)] <= DP[v]){
                DP[v] = DP[w] + C[make_pair(w, v)];
                Q.push(make_pair(C[make_pair(w, v)], make_pair(w, v)));
            }
        }
    }
}


int main() {
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b, c; cin >> a >> b >> c;a--;b--;
        G[a].insert(b);
        G[b].insert(a);
        C[make_pair(a, b)] = c;
        C[make_pair(b, a)] = c;
    }
    cin >> Q >> K;K--;
    Dijkstra(K);

    for(ll i = 0; i < Q; i++){
        int x, y; cin >> x >> y;x--;y--;
        cout << DP[x] + DP[y] << endl;
    }
    return 0;
}