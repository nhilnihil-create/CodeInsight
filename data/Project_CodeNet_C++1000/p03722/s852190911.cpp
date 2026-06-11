#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};
vector<vector<ll> > G;
vector<bool> seen;

void dfs(ll v){
    seen[v]=1;
    rep(i,G[v].size()){
        if(seen[G[v][i]] == 0){
            dfs(G[v][i]);
        }
    }

}
struct edge {
    ll from; //出発点
    ll to;   //到達点
    ll cost; //移動コスト
};

int main() {
    ll MAX_V =1200;
    ll V; //頂点の数
    ll side; //辺の数
    ll S; //始点
   
    ll d[MAX_V]; //始点から添え字の頂点に行くのにかかるコスト
    vector<edge> edges2; //移動の情報を保存する

    cin>>V>>side;
    S=0;
   

    G.resize(V);
    seen.resize(V);
    fill(d, d+V+5, INF); //すべての頂点をINFにする
    d[S] = 0; //始点を0にする

    for (int i = 0; i < side; i++) {
        struct edge add;

        cin >> add.from;

        cin >> add.to;
        add.from--;add.to--;
        G[add.from].pb(add.to);
        cin >> add.cost;
        add.cost*=-1;
        edges2.push_back(add);
    }

    vector<ll>ban;
    rep(i,V){
        seen.clear();
        seen.resize(V);
        dfs(i);
        if(seen[V-1]==0){
            ban.pb(i);
        }
    }
    /*rep(i,ban.size()){
        cout<<ban[i]<<endl;
    }*/
    vector<edge> edges;

    rep(i,edges2.size()){
        rep(j,ban.size()){
            if(edges2[i].from==ban[j] || edges2[i].to==ban[j]){
                break;
            }
            if(j==ban.size()-1){
                edges.push_back(edges2[i]);
            }
        }
    }
    if(ban.size()==0){
        edges=edges2;
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (ll)edges.size(); j++) {

            struct edge e = edges[j];

            if (d[e.to] > d[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
                d[e.to] = d[e.from] + e.cost;
                if (i == V-1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                    cout << "inf" << endl;
                    return 0;
                } 
            }
        }
    }

    cout<<-d[V-1]<<endl;


    return 0;
    

}