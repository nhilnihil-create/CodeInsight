#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl

/*-- template --*/
int N;
vector<vector<int>>G;
vector<int> bfs(int root) {
    vector<int> dist(N, INF);
    dist[root] = 0;
    queue<int>Q;
    Q.push(root);
    while(!Q.empty()) {
        int q = Q.front();Q.pop();
        for(int i : G[q]) {
            if(dist[i] == INF) {
                dist[i] = dist[q] + 1;
                Q.push(i);
            }
        }
    }
    return dist;
}

int main() {
    cin >> N;
    G.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].pb(b), G[b].pb(a);
    }
    vector<int>dist1 = bfs(0);
    vector<int>distN = bfs(N - 1);
    int scoreFenec = 0, scoreSnuke = 0;
    rep(i, N) {
        ++((dist1[i] <= distN[i]) ? scoreFenec : scoreSnuke);
    }
    cout << ((scoreFenec > scoreSnuke) ? "Fennec" : "Snuke") << endl;
}
