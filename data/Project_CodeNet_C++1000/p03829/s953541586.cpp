#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

typedef pair<ll,int> P;

vector<ll> d(100005);
vector<vector<P> > G(100005);

void dijkstra(int V){
    REP(i,V)d[i]=INF;
    priority_queue<P,vector<P>,greater<P>> que;
    d[0]=0;
    que.push(P(0,0));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v = p.second;
        ll cost = p.first;
        if(d[v]<cost)continue;
        for(auto e:G[v]){
            if(d[e.second]>d[v]+e.first){
                d[e.second]=d[v]+e.first;
                que.push(P(d[e.second],e.second));
            }
        }
    }
}

int main(){
    int N;cin>>N;
    ll A,B;cin>>A>>B;
    vector<ll> X(N);
    REP(i,N)cin>>X[i];
    REP(i,N-1){
        G[i].push_back(P(min(A*(X[i+1]-X[i]),B),i+1));
    }
    dijkstra(N);
    cout<<d[N-1]<<endl;
    return 0;
}