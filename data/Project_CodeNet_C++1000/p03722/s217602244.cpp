#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
struct edge{int from,to;
            ll cost;};
edge es[2002];
ll d[1002];
bool neg[1001];
int V,E;
const ll INF = (1LL << 61);

void find_negative_loop(int s){
    for (int i=0;i < V;i++) d[i] = INF;
    d[s] = 0;
    for (int i=0;i < V;i++){
        for (int j = 0;j < E;j++){
            edge e =es[j];
            if ( d[e.from] != INF && d[e.to] >  d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                if (i == V-1 ) return;
            }
        }
    }
    return;
}
void f(){
    for (int i=0;i < V;i++){
        for (int j = 0;j < E;j++){
            edge e = es[j];
            if (d[e.from] != INF && d[e.to] >  d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                neg[e.to] = true;
            }
            if (neg[e.from] == true) neg[e.to] = true;
        }
    }
}
int main(){
    cin >> V >> E;
    rep(i,E){
        int x,y;
        ll z;
        cin >> x >> y >> z;
        es[i] = {x-1,y-1,-z};
    }
    find_negative_loop(0);
    rep(i,V) neg[i] = false;
    f();
    if (neg[V-1]){
        cout << "inf" << endl;
    }
    else cout << -d[V-1] << endl;
   
    
    return 0;    
}