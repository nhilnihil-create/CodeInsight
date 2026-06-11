#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll ;
typedef pair<int,int> pii ;

const int mx = 104 ;
const int inf= 1<<28 ;

vector <pii> adj[mx] ;
int par[mx] ;
int d[mx] ;
set <pii> s ;
bool mark[mx][mx] ;

void dij(int v){
    s.erase(s.begin()) ;
    for(auto x : adj[v] ){
        if(d[x.ff] > d[v] + x.ss ){
            s.erase({d[x.ff] , x.ff}) ;
            d[x.ff] = d[v] + x.ss ;
            s.insert({d[x.ff] , x.ff}) ;
            par[x.ff] = v ;
        }
    }
    if(s.size() == 0){
        return ;
    }
    dij(s.begin()->ss) ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0) ;
    cout.tie(0) ;
    int n,m ;
    cin >> n >> m ;
    for(int i =1 ; i<= m ; i++){
        int u,v,c ;
        cin >> u >> v >> c ;
        adj[v].pb({u, c}) ;
        adj[u].pb({v, c}) ;
        mark[u][v] = 1 ;
        mark[v][u] = 1 ;
    }
    for(int i=1 ; i<= n ; i++ ){
        for(int j=1 ; j <= n ; j++){
            d[j] = inf ;
        }
        d[i] = 0 ;
        s.insert({0 , i}) ;
        dij(i) ;
        for(int w =1 ; w <= n ; w++){
            if(w != i){
                mark[par[w]][w] =0 ;
                mark[w][par[w]] =0 ;
            }
        }
    }
    int jav=0 ;
    for(int i =1 ; i<= n ; i++){
        for(int j =1 ; j<= n ; j++){
            if(mark[i][j]){
                jav++;
            }
        }
    }
    cout << jav/2 ;


    return 0;
}
