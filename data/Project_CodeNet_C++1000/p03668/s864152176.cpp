#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
typedef vector<int> V;
typedef vector<V> VV;
int main(){
    int N;
    cin>>N;
    VV g(N);
    REP(i,N-1){
        int a,b;cin>>a>>b;a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    REC(int,int,int) dfs=[&](int v,int p){
        int ret=0;
        for(auto &u:g[v])if(u!=p)
                             ret^=dfs(u,v)+1;
        return ret;
    };
    if(dfs(0,0))cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    return 0;
}
