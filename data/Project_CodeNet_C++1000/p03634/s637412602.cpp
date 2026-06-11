#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

struct edge{
    lli to,cost;
};
vector<vector<edge>> G;
lli dist[100100];
void func(lli now,lli from){
    for(auto e:G[now]){
        if(e.to==from)continue;
        dist[e.to] = dist[now] + e.cost;
        func(e.to,now);
    }
}

void func(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, long long Q, long long K, std::vector<long long> x, std::vector<long long> y){
    G.resize(N);
    REP(i,0,N-1){
        G[a[i]].push_back({b[i],c[i]});
        G[b[i]].push_back({a[i],c[i]});
    }
    dist[K]=0;
    func(K,-1);

    REP(i,0,Q){
        cout<<dist[x[i]]+dist[y[i]]<<endl;
    }
}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    std::vector<long long> c(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&c[i]);
        a[i]--,b[i]--;
    }
    long long Q;
    scanf("%lld",&Q);
    long long K;
    scanf("%lld",&K);
    K--;
    std::vector<long long> x(Q);
    std::vector<long long> y(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
        x[i]--,y[i]--;
    }
    func(N, std::move(a), std::move(b), std::move(c), Q, K, std::move(x), std::move(y));
    return 0;
}
