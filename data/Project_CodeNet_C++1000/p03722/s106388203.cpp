#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

typedef struct edge{
    ll from, to, cost;
}edge;

int main() {
    cin>>N>>M;
    vector<edge> ed(M), rev(M);
    rep(i,M){
        cin>>A>>B>>L;
        --A; --B;
        ed[i].from = rev[i].to = A;
        ed[i].to = rev[i].from = B;
        ed[i].cost = rev[i].cost = L;
    }
    vector<bool> fromN(N,false), updated(N,false);
    vec score1(N,-INF);
    score1[0] = 0;
    rep(i,N){
        for(edge e : ed){
            if((score1[e.from] != -INF) && (score1[e.to] < score1[e.from] + e.cost)){
                score1[e.to] = score1[e.from] + e.cost;
                if(i == N - 1) updated[e.to] = true;
            }
        }
    }
    fromN[N-1] = true;
    rep(i,N){
        for(edge e : rev){
            if(fromN[e.from]) fromN[e.to] = true;
        }
    }
    rep(i,N) {
        if(updated[i] && fromN[i]){
            cout<<"inf"<<endl;
            return 0;
        }
    }
    cout<<score1[N-1]<<endl;
}