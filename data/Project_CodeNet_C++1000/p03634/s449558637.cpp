#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

#define MAX_V 100010


struct edge{
    int to;
    int cost;
};

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>>que;
    fill(d, d + MAX_V, INF * INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)continue;

        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
   cin >> V;
   rep(i, V - 1){
       ll a, b, c;
       cin >> a >> b >> c;
       edge e1 = {b, c};
       edge e2 = {a, c};

       G[a].push_back(e1);
       G[b].push_back(e2);
   }

   int q, k;
   cin >> q >> k;
   dijkstra(k);

   rep(i, q){
       ll x, y;
       cin >> x >> y;
       cout << d[x] + d[y] << endl;
   }
}

