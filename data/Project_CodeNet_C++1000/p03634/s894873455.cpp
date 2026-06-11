#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<edge>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

vector<bool> seen;
vector<ll> dist;
void dfs(const Graph &G, int v,ll cos){

    dist.at(v) = cos;
    seen.at(v) = true;

    for(auto d : G.at(v)){
        if(seen.at(d.to)) continue;
        ll new_cos = cos + d.weight;
        dfs(G,d.to,new_cos);
    }

}

int main(){

    int n; cin >> n;
    Graph G(n);
    rep(i,n-1){
        int a,b,c; cin >> a >> b >> c;
        a--;b--;
        G.at(a).push_back(edge(b,c));
        G.at(b).push_back(edge(a,c));
    }
    int q,k; cin >> q >> k;
    k--;
    seen.assign(n,false);
    dist.assign(n,-1);
    dfs(G,k,0);

    rep(i,q){
        int x,y; cin >> x >> y;
        x--;y--;
        cout << dist.at(x)+dist.at(y) << endl;;
    }

    return 0;
}