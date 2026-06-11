#include<iostream>
#include<vector>
using namespace std;

#define pii pair<int, int>
#define ft  first
#define sd second


const int N = 1e5+5;
vector<pii> vec[N];
long long dis[N];


void dfs(int u, int p){
    for(pii x: vec[u]){
        if(x.ft != p){
            dis[x.ft] = dis[u] + x.sd;
            dfs(x.ft, u);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i< n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    int q, k;
    cin >> q >> k;
    dfs(k, 0);
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << dis[x] + dis[y] << endl;
    }
}
