#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF=(1LL<<61)-1;

int N,M;
struct edge{ ll from,to,cost;};
vector<edge> E;
vector<ll> d;
vector<bool> negative;

void f(int s){
    rep(i,N+10) {d[i] = INF; negative[i] = false;}

    d[s] = 0;
    ll cnt=0;
    rep(i,N){
        rep(j,M){
            edge e = E[j];
            if(d[e.from] != INF && d[e.to] > d[e.from]+e.cost){
                d[e.to] = d[e.from] + e.cost;
                if(i==N-1) negative[e.to] = true;
            }
        }
    }
    rep(i,N){
        rep(j,M){
            edge e = E[j];
            if(negative[e.from]){
                negative[e.to] = true;
            }
        }
    }
    return ;
}

int main(){
    cin >> N >> M;
    d.resize(N+10); negative.resize(N+10);
    rep(i,M){
        int s,t,c; cin >> s >> t >> c;
        s--;t--;c=-c;
        edge e = {s,t,c};
        E.push_back(e);
    }
    f(0);
    if(negative[N-1]) cout << "inf" << endl;
    else cout << -d[N-1] << endl;
}