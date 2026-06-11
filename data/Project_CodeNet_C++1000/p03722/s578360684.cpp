#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

const ll INF = -1e16+7;

struct edge{
    int from;
    int to;
    int c;
};

bool bellman_ford(const ll &s,const ll &V,const ll &E,const vector<edge> &ed, vector<ll> &d){

    // s=スタート, Vが頂点数，Eが辺の数, ed=どのようなパスを持つか, 
    //d=答えを保持するvector．今は１つの経路が欲しいので参照して書き換えているが全ての経路について必要になった場合にはdをreturnするように改造する

    // 初期化
    for(ll i = 0; i < V+1; i++){
        d[i] = INF;
    }

    d[s] = 0;
    ll num = 0;
    while(true){
        if(num>=V){
            return false;
        }
        //updateが更新されなくなるまでこの操作を繰り返す
        bool update = false;
        for(ll i = 0; i < E; i ++){
            edge e = ed[i];
            if(d[e.from]!=INF && d[e.to]<d[e.from]+ e.c){  // 更新条件を変更
                if(e.to==V && d[V]!=INF){
                    return true;
                }
                d[e.to] = d[e.from]+ e.c;
                update = true;
            }
        }
        if(!update){
            break;
        }

        num ++;
    }
    return false;
}


int main(){

    ll V,E; cin >> V >> E;
    vector<edge> ed(E);
    rep(i,E){
        cin >> ed[i].from >> ed[i].to >> ed[i].c;
    }
    vector<ll> d(V+5); // スタートの頂点番号を0ではなく１としたいので余分に作ってd[0]は使わない
    bool loop = bellman_ford(1, V, E, ed, d);

    if(loop){
        cout << "inf" << endl;
    }else{
        cout << d[V] << endl;
    }

    return 0;
}