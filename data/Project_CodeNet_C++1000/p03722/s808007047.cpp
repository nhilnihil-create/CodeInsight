#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

//Bellman-Fordをする。Gは<to, cost>の配列。dは結果。vは始点。true:負閉路の存在
bool BellmanFord(vector<vector<llll>> &G, vector<ll> &d, int v){
    fill(ALL(d), INF);
    d[v] = 0;
    
    bool check; //更新があったかの確認
    int times = 0; //回数
    int V = G.size();
    while(true){
        check = false;
        times++;
        for (int i = 0; i < V; i++) {
            for (auto edge : G[i]){
                auto to = edge.first;
                auto cost = edge.second;
                if(d[i] != INF && d[to] > d[i] + cost){
                    d[to] = d[i] + cost;
                    check = true;
                }
            }
        }
        if(!check) break;
        if(times >= V-1 && check){
            return true;
        }
    }
    return false;
}

void BellmanFord2(vector<vector<llll>> &G, vector<ll> &d, int v){
    fill(ALL(d), INF);
    d[v] = 0;
    
    int times = 0; //回数
    int V = G.size();
    while(true){
        times++;
        for (int i = 0; i < V; i++) {
            for (auto edge : G[i]){
                auto to = edge.first;
                auto cost = edge.second;
                if(d[i] != INF && d[to] > d[i] + cost){
                    d[to] = d[i] + cost;
                }
            }
        }
        if(times >= 2*V-1){
            break;
        }
    }
}


int main(){
    int N, M;
    cin >> N >> M;
    ll a, b, c;
    vector<vector<llll>> G(N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(make_pair(b, -c));
    }

    vector<ll> d(N);

    if(BellmanFord(G, d, 0)){
        vector<ll> dd(N);
        BellmanFord2(G, dd, 0);
        if(dd[N-1] != d[N-1]){
            printf("inf\n");
        }
        else{
            printf("%d\n", - d[N-1]);
        }
    }
    else{
        printf("%lld\n", - d[N-1]);
    }



}