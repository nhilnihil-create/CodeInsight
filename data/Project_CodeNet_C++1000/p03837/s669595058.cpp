#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double EPS=1e-10;
const double PI=acos(-1);

struct edge{
    int to,cost,id;
};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<edge>> g(n);
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        g[a].push_back({b,c,int(i)});
        g[b].push_back({a,c,int(i)});
    }
    vector<bool> used(m,false);
    auto dijkstra=[&](int st,int en){
        priority_queue<Pi,vector<Pi>,greater<Pi>> que;
        vector<int> dist(n,INF);
        vector<Pi> pre(n);
        dist[st]=0;
        que.push({0,st});
        while(!que.empty()){
            auto hoge=que.top();
            que.pop();
            int v=hoge.se,d=hoge.fi;
            if(dist[v]<d) continue;
            for(auto e:g[v]){
                if(chmin(dist[e.to],dist[v]+e.cost)){
                    que.push({dist[e.to],e.to});
                    pre[e.to]=Pi(v,e.id);
                }
            }
        }
        for(int v=en;v!=st;v=pre[v].fi){
            used[pre[v].se]=true;
        }
    };
    rep(i,n)FOR(j,i+1,n){
        dijkstra(i,j);
    }
    int ans=0;
    rep(i,m) if(!used[i]) ans++;
    cout<<ans<<endl;
}