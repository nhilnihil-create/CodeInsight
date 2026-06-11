#include<bits/stdc++.h>
using namespace std;
//#include<boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;

#define int long long
#define cint cpp_int
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) (((a)+(b)-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/2
#define PI acos(-1.0)

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;
typedef priority_queue<int> PQi;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
void vout(Vs &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
void vvout(VVi &v){for(int i=0;i<(v).size();i++) vout(v[i]);}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int mypow(int x, int n, int m){if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int digit(int k,int i){string s = to_string(k);return s[s.size()-i]-'0';}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
int leng(int n){string s=to_string(n); return s.size();}
int lesscount(int x,Vi &a){return lower_bound(a.begin(),a.end(),x)-a.begin();} //vector aにおけるx未満の数の個数
int orlesscount(int x,Vi &a){return upper_bound(a.begin(),a.end(),x)-a.begin();} //vector aにおけるx以下の数の個数
int morecount(int x,Vi &a){return a.size()-orlesscount(x,a);} //vector aにおけるxより大きい数の個数
int ormorecount(int x,Vi &a){return a.size()-lesscount(x,a);} //vector aにおけるx以上の数の個数
int count(int x,Vi &a) {return upper_bound(ALL(a),x)-lower_bound(ALL(a),x);}
Vi accum(Vi &v){Vi ret((v).size()+1);REP(i,0,(v).size()) ret[i+1]=ret[i]+v[i];return ret;}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

struct edge{int to,cost;};
struct graph{
    int N;  
    vector< vector<edge> > G;
    VVi dist;
    graph(int n){
        init(n);
    }
    void init(int n){
        N = n;
        G.resize(N);
        dist.resize(N);
        REP(i,0,N) dist[i].resize(N);
        REP(i,0,N){
            REP(j,0,N){
                dist[i][j] = INF;
            }
        }
    }
    void add_edge(int s,int t,int cost){
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }
    void warshall_floyd(){
        REP(i,0,N){
            dist[i][i]=0;
        }
        REP(i,0,N){
            for(auto e : G[i]){
                dist[i][e.to]=e.cost;
                dist[e.to][i]=e.cost;
            }
        }
        REP(i,0,N){
            REP(j,0,N){
                REP(k,0,N){
                    chmin(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
    }
};

signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
    int n,m;
    cin>>n>>m;
    Vi a(m),b(m),c(m);
    REP(i,0,m){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--; b[i]--;
    }

    graph G(n);
    REP(i,0,m){
        G.add_edge(a[i],b[i],c[i]);
    }
    G.warshall_floyd();

    int ans=0;
    REP(i,0,m){
        int from=a[i];
        int to=b[i];
        int cost=c[i];
        bool check=false;
        REP(j,0,n){
            REP(k,0,n){
                if(G.dist[j][from]+cost+G.dist[to][k]==G.dist[j][k]) check=true;
            }
        }
        if(check==false) ans++;
    }
    cout<<ans<<endl;

    return 0;
}
