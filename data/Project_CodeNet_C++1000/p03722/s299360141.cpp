#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll max_E=100000;
const ll max_V=100000;
ll INF=9000000000000000000;

struct edge{ll from,to,cost;};

edge es[max_E];
ll dist[max_V];
ll N,M;
bool negative[max_V];

void shortest_path(ll s){
    fill(negative,negative+N,0);
    for(int i=0;i<N;i++) dist[i]=INF;//INFを作る
    dist[s]=0;
    for(int loop=0;loop<N-1;loop++){
        for(int i=0;i<M;i++){
            edge e=es[i];
            if(dist[e.from]==INF) continue;
            if(dist[e.from]!=INF&&dist[e.to]>dist[e.from]+e.cost){
                dist[e.to]=dist[e.from]+e.cost;
            }
        }
    }
}

void find_negative_loop(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            edge e=es[j];
            if(dist[e.from]==INF) continue;
            if(dist[e.to]>dist[e.from]+e.cost){
                dist[e.to]=dist[e.from]+e.cost;
                negative[e.to]=1;
            }
            if(negative[e.from]) negative[e.to]=1;
        }
    }
}

int main(){
    cin>>N>>M;
    for(ll i=0;i<M;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        es[i].from=a;
        es[i].to=b;
        es[i].cost=-c;
    }
    shortest_path(0);
    find_negative_loop();
    if(negative[N-1]) cout<<"inf"<<endl;
    else{
        cout<<-dist[N-1]<<endl;
    }
}