#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;


ll v = 1005,e;
vector<vector<pair<ll,ll>>> graph(v,vector<pair<ll,ll>>());
vector<ll> shortest(v,LINF);

//ベルマンフォードもし負の閉路があったらfalseをかえす
bool bellmanford(ll start){
    shortest[start] = 0;
    int cnt = 0;
    while(1){
        bool update = false;
        bool goal = false;
        for(int i=0;i<v;i++){
            if(shortest[i] == LINF) continue;
            for(pair<ll,ll> edge:graph[i]){
                if(shortest[edge.second] > shortest[i] + edge.first){
                    if(cnt < v) shortest[edge.second] = shortest[i] + edge.first;
                    else shortest[edge.second] = -LINF;
                    update = true;
                    if(edge.second==v-1){
                        goal = true;
                    }
                }
            }
        }
        if(!update) break;
        cnt ++;
        if(cnt >= v && goal){
            return false;
        }
        if(cnt > 3*v){
            return true;
        }
    }
    return true;
}

int main(){
    cin >> v >> e;
    rep(i,e){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        --a;--b;
        graph[a].push_back(pll{-c,b});
    }

    if(bellmanford(0)){
        cout << -shortest[v-1] << endl;
    }else{
        cout << "inf" << endl;
    }

    return 0;
}