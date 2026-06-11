#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)
ll INF = 1LL << 60;

struct edge{
    ll to;
    ll cost;
    edge(ll t, ll c){
        to = t;
        cost = c;
    }
};

struct fulledge{ //* u->v with cost
    ll u, v, cost;
    fulledge(){}
    fulledge(ll _u, ll _v, ll _c){
        u = _u; v = _v; cost = _c;
    }

    bool operator< ( fulledge const &e) const {
        return cost < e.cost;
    }
};

struct edgeGreater{
    bool operator()(const fulledge &e1, const fulledge &e2){
        return e1.cost > e2.cost;
    }
};

//* simplest bellman-ford shortest path calculator
bool BellmanFord(vector<fulledge> &es, vector<ll> &dist, vector<bool> &neg, ll s){
    ll N = dist.size();
    ll M = es.size();
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    bool update;
    rep(loop, N){
        update = false;
        rep(i, M){
            fulledge e = es[i];
            if(dist[e.u]!=INF && dist[e.v] > dist[e.u]+e.cost) {
                dist[e.v] = dist[e.u] + e.cost;
                update = true;
            }
        }
        if(!update) 
            break;
    }
    //* check which node can be affected by negative cycles
    fill(neg.begin(), neg.end(), false);
    rep(loop, N){
        rep(i, M){
            fulledge e = es[i];
            if(dist[e.u]!=INF && dist[e.v] > dist[e.u]+e.cost) {
                dist[e.v] = dist[e.u] + e.cost;
                neg[e.v] = true;
            }
            if(neg[e.u] == true)
                neg[e.v] = true;
        }
    }

    return update;
}


void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c){
    vector<fulledge> es;
    rep(i, M){
        es.push_back(fulledge(a[i]-1, b[i]-1, -c[i]));
    }
    vector<ll> dist(N);
    vector<bool> neg(N);
    ll isBad = BellmanFord(es, dist, neg, 0LL);
    if(neg[N-1]==true)
        cout << "inf" << endl;
    else
        cout << -dist[N-1] << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    std::vector<long long> c(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&c[i]);
    }
    solve(N, M, std::move(a), std::move(b), std::move(c));
    return 0;
}
