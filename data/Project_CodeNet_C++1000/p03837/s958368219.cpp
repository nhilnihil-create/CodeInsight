#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

const static ll Max = 100000+5;
const static ll INF = 1e18+5;
vector<set<ll>> G(Max);
ll N, Q, K, M;
map<pair<ll, ll>, ll> C;
ll DP[Max];

vector<vector<bool>> Map;

void Dijkstra2(ll s){
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
    
    ll DP2[Max]; for(int i = 0; i < Max; i++) DP2[i] = INF;
    DP2[s] = 0;
    for(auto v : G[s]) {
        DP2[v] = C[make_pair(s, v)];
        if(DP[v] == DP2[v]) Map[s][v] = Map[v][s] = false;
    }
    priority_queue< pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>> > Q2;
    for(auto v : G[s]){
        if(C.find(make_pair(s, v)) != C.end()) Q2.push(make_pair(C[make_pair(s, v)], make_pair(s, v)));
    }

    while(!Q2.empty()){
        auto next = Q2.top(); Q2.pop();
        auto w = next.second.second;

        //if(next.second.first == s && DP2[w] != DP[w]){
          //  Map[s][w] = Map[w][s] = true;
            //cout << s << " " << w << " " << DP[w] << " " << DP2[w] << endl;
        //}
        //else Map[s][w] = Map[s][w] = false;
        
        for(auto v : G[w]) if(C.find(make_pair(w, v)) != C.end()){
            if(DP2[w] + C[make_pair(w, v)] == DP[v]){
                DP2[v] = DP2[w] + C[make_pair(w, v)];
                Q2.push(make_pair(C[make_pair(w, v)], make_pair(w, v)));
                Map[w][v] = Map[v][w] = false;
            }
            //else Map[w][v] = true;
        }
        
    }
}


int main(){
    cin >> N >> M;
    Map.resize(N);
    for(int i = 0; i < N; i++) Map[i].resize(N);
    for(int i = 0; i < M; i++){
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        G[a].insert(b);
        G[b].insert(a);
        C[make_pair(a, b)] = c;
        C[make_pair(b, a)] = c;
        Map[a][b] = Map[b][a] = true;
    }

    for(int i = 0; i < N; i++){
        Dijkstra2(i);
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) if(Map[i][j]) ans++;
    }
    cout << ans/2 << endl;



}
