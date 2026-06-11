#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

typedef pair<pair<int,int>,ll> P;

bool negative_cycle(int N,int M,vector<ll> &d,vector<P> &G){
    REP(i,N)d[i]=0;
  int tmp1,tmp2;
    REP(i,2*N){
      REP(j,M){
        P e=G[j];
        int from=e.first.first;
        int to =e.first.second;
        ll cost =e.second;
        if(d[to]>d[from]+cost){
            d[to]=d[from]+cost;
        }
        if(i==N-1)tmp1=d[N-1];
      }
    }
  tmp2=d[N-1];
    return !(tmp1==tmp2);
}

void Bellman_Ford(int s,int N,int M,vector<ll> &d,vector<P> &G){
    REP(i,N)d[i]=INF;
    d[s]=0;
    REP(l,N){
        bool update=false;
        REP(i,M){
            P e=G[i];
            int from=e.first.first;
            int to  =e.first.second;
            ll cost =e.second;
            if(d[from]!=INF && d[to]>d[from]+cost){
                d[to]=d[from]+cost;
                update=true;
            }
        }
        if(!update) break;
    }
}

int main(){
    int N,M;cin>>N>>M;
    vector<P> G;
    int a,b; ll c;
    REP(i,M){
        cin>>a>>b>>c;a--;b--;
        G.push_back(make_pair(make_pair(a,b),-c));
    }
    vector<ll> d(N);
    bool f=negative_cycle(N,M,d,G);
    if(f)cout<<"inf"<<endl;
    else{
        Bellman_Ford(0,N,M,d,G);
        cout<<-d[N-1]<<endl;
    }
    return 0;
}