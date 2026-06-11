#include<bits/stdc++.h>
using namespace std;
//#include<boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;

#define int long long
#define cint cpp_int
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) ((a+b-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/2

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> void YesNo(T a) {cout<<(a?"Yes":"No")<<endl;}
template<class T> void YESNO(T a) {cout<<(a?"YES":"NO")<<endl;}
void vin(Vi &v){REP(i,0,(v).size()) cin>>v[i];}
void vin(Vi &v,Vi &v2){REP(i,0,(v).size()) cin>>v[i]>>v2[i];}
void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
void accum(Vi &v){REP(i,1,(v).size()) v[i]+=v[i-1];}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

struct edge{int to,cost;};
struct graph{
    int N;  
    vector< vector<edge> > G;
    Vi dist;
    graph(int n){
        init(n);
    }
    void init(int n){
        N = n;
        G.resize(N);
        dist.resize(N);
        REP(i,0,N){
            dist[i] = INF;
        }
    }
    void add_edge(int s,int t,int cost){
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }
    void bfs(int s){
        REP(i,0,N){
            dist[i] = 0;
        }
        dist[s]=1;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int now=q.front();q.pop();
            //終了条件などの処理
            for(auto e : G[now]){
                if(dist[e.to]==0){
                    dist[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
    void dijkstra(int s){
        REP(i,0,N){
            dist[i] = INF;
        }
        dist[s] = 1;
        priority_queue<Pii,vector<Pii>,greater<Pii>> q;
        q.push(mp(s,0));
        while(!q.empty()){
            int now,nowdist;
            tie(now,nowdist) = q.top();q.pop();
            if(dist[now]<nowdist) continue;
            for(auto e : G[now]){
                if(dist[e.to]>dist[now]+e.cost){
                    dist[e.to] = dist[now]+e.cost;
                    q.push(mp(e.to,dist[e.to]));
                }
            }
        }
    }
    int bellman_ford(int s){
        REP(i,0,N){
            dist[i]=INF;
        }
        dist[s]=0;
        REP(i,0,N){
            REP(j,0,N){
                for(auto e : G[j]){
                    if(dist[e.to] > dist[j] + e.cost){
                        dist[e.to] = dist[j] + e.cost;
                        if(i>=N-1){
                            return 1;
                        }
                    }
                }
            }
            // REP(j,0,N) cout<<dist[j]<<" ";
            // cout<<endl;
        }
        return 0;
    }
};


signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    Vi a(m),b(m),c(m);
    REP(i,0,m){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;
    }

    graph G1(n),G2(n);
    REP(i,0,m){
        G1.add_edge(a[i],b[i],1);
        G2.add_edge(b[i],a[i],1);
    }

    G1.bfs(0);
    G2.bfs(n-1);

    graph G(n);
    REP(i,0,m){
        if(G1.dist[a[i]]==1 && G2.dist[b[i]]==1) G.add_edge(a[i],b[i],-c[i]);
    }

    // REP(i,0,n) cout<<G.dist[i]<<" ";
    int negaloop=G.bellman_ford(0);
    if(negaloop) cout<<"inf"<<endl;
    else cout<<-G.dist[n-1]<<endl;
}
