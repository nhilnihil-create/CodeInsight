#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

struct Edge{
    ll from;ll to;ll cost;
};
using Edges = vector<Edge>;
bool bellman_ford(const Edges &Es,ll V,int s,vector<ll> &dis){
    dis[s] = 0;
    int cnt = 0;
    while(cnt < V){
        bool end = true;
        for(auto e:Es){
            if(dis[e.from] != INF && dis[e.from]+e.cost < dis[e.to]){
                dis[e.to] = dis[e.from] + e.cost;
                end = false;
                if(cnt==V-1&&e.to==V-1) return true;
            }
        }
        if(end) break;
        cnt++;
    }
    return false;
}

int main(){
    ll N, M;
    cin >> N >> M;
    Edges Es(M);
    rep(i,M){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;c*=-1;
        Es[i] = {a,b,c};
    }
    vector<ll> dis(N,INF);
    if(bellman_ford(Es,N,0,dis)) cout << "inf" << endl;
    else{
        cout << -dis[N-1] << endl;
    }
}