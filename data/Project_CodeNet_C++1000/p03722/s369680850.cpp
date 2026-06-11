#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int inf = 1 << 20;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


struct edge {ll from,to,cost;};

int main()
{
    int n,m;
    cin >> n >> m;
    edge es[m];
    for(int i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        es[i].from = a;
        es[i].to = b;
        c *= -1;
        es[i].cost = c; 
    }
    ll d[n],dis[n];
    for(int i = 0; i < n; i++){
        d[i] = INF;
        dis[i] = INF;
    }
    d[0] = 0;
    dis[0] = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            edge e = es[j];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    ll ans = d[n-1];
    
    bool negative[n];
    for(int i = 0; i < n; i++){
        negative[i] = false;
    }

    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            edge e = es[j];
            if(dis[e.from] != INF && dis[e.to] > dis[e.from] + e.cost){
                dis[e.to] = dis[e.from] + e.cost;
            }
        }
    }
    ll ans1 = dis[n-1];

    if(ans == ans1){
        cout << -1 * ans << endl;
    }else{
        cout << "inf" << endl;
    }

}
